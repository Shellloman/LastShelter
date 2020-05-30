#include "stat.h"

Stat::Stat(){
    pieces = nullptr;
    ferraille = 300;
    eau = 500;
    energie = 500;
    nourriture = 500;
    joie = 500;
    nbPerso = 0;
    nbPersoMax = 0;
    lastUpdate = 0;
    beau = true; benergie = true; bnourriture = true; bjoie = true;
    taille_inv = 0;
}

void Stat::setPtr(Piece** pieces_,Alerte* alerte_){
    pieces = pieces_;
    alerte = alerte_;
}

void Stat::setStat(int save,SDL_Rect tab[9*17]){
    string a = to_string(save);
    ifstream file("save/save"+a+".txt");
    stringstream strs;
    string str;
    bool verif = false;
    int type, niv, nb_perso, age, force, inte, soc, charme, agi, conc;
    int th,tb,tt;
    bool etat, sante, vie;
    getline(file,str);
    strs << str;
    strs >> verif;
    if (!verif) {
        pieces[3] = pieces[2] = pieces [1] = pieces[0] = new Milice(0,0,2);
        ferraille = 300;
        eau = 500;
        energie = 500;
        nourriture = 500;
        joie = 500;
        nbPerso = 0;
        nbPersoMax = 0;
        lastUpdate = 0;
        beau = true; benergie = true; bnourriture = true; bjoie = true;
        return;
    }
    for (int j = 0; j<9; ++j) {
        for(int i = 0; i<17; ++i) {
            pieces[j*17+i] = nullptr;
        }
    }
    strs.str(""); strs.clear();
    getline(file,str);
    strs << str;
    strs >> ferraille >> energie >> nourriture >> eau >> joie;
    int piece = 0; int xp; int yp;
    strs.str(""); strs.clear();
    while(getline(file,str)) {
        strs << str;
        strs >> verif;
        if (verif) {
            strs >> type >> niv >> nb_perso;
            strs.str(""); strs.clear();
            yp = piece/17; xp = piece%17;
            switch (type) {
                case ASC: pieces[piece] = new Piece(yp,xp,0,true); break;
                case DORTOIR: pieces[piece] = new Dortoir(yp,xp,niv); break;
                case REACTEUR: pieces[piece] = new Reacteur(yp,xp,niv); break;
                case EAU: pieces[piece] = new Eaupotable(yp,xp,niv); break;
                case SELF: pieces[piece] = new Refectoire(yp,xp,niv); break;
                case ATELIER: pieces[piece] = new Atelier(yp,xp,niv); break;
                case SALON: pieces[piece] = new Salon(yp,xp,niv); break;
                case INFIRM: pieces[piece] = new Infirmerie(yp,xp,niv); break;
                case MILICE: pieces[piece] = new Milice(yp,xp,niv); break;
                default: break;
            }
            if(!pieces[piece]->isAsc()) pieces[piece+1] = pieces[piece+2] = pieces[piece];
            while(nb_perso > 0) {
                getline(file,str);
                strs << str;
                strs >> th>>tb>>tt>>etat>> age >>sante>> vie>> force >> inte >> soc >> charme >> agi >> conc;
                strs.str(""); strs.clear();
                pieces[piece]->addPerso(new Personnage(th,tb,tt,etat,age,sante,vie,force,inte,soc,charme,agi,conc),tab[yp*17+xp].y,tab[yp*17+xp].x);
                nb_perso--;
            }
            switch (niv) {
                case 0: piece++; break;
                case 1: piece+= 3; break;
                case 2: pieces[piece+3] = pieces[piece]; piece+=4; break;
                case 3: pieces[piece+5] = pieces[piece+4] = pieces[piece+3] = pieces[piece];
                    piece+=6; break;
                default: break;
            }
        }
        else {
            strs.str(""); strs.clear();
            piece++;
        }
    }
    file.close();
}

void Stat::save(int save){
    string a = to_string(save);
    Piece* p = nullptr;
    Personnage* pe = nullptr;
    ofstream file("save/save"+a+".txt");
    file.write("1\n",2);
    a = to_string(ferraille)+" "+to_string(energie)+" "+to_string(nourriture)+
        " "+to_string(eau)+" "+to_string(joie)+"\n";
    file.write(a.c_str(),a.size());
    for(int i = 0; i<9*17; i++) {
        if(pieces[i]==nullptr) {
            file.write("0\n",2);
        }else{
            p = pieces[i];
            a = "1 "+to_string(p->getType())+" "+to_string(p->getNiveau())+" "+
                to_string(p->getNbPerso())+"\n";
            file.write(a.c_str(),a.size());
            for(int j = 0; j < int(p->getNbPerso()); j++ ) {
                pe = p->getPerso(j);
                a = to_string(pe->getTexHaut())+" "+to_string(pe->getTexBas())+" "+
                    to_string(pe->getTexTete())+" "+to_string(pe->getStatut())+
                    " "+to_string(pe->getAge())+" "+to_string(pe->getSante())+" "+
                    to_string(pe->getVie())+" "+to_string(pe->getForce())+" "+
                    to_string(pe->getIntelligence())+" "+to_string(pe->getSociabilite())+
                    " "+to_string(pe->getCharme())+" "+to_string(pe->getAgilite())+
                    " "+to_string(pe->getConcentration())+"\n";
                file.write(a.c_str(),a.size());
            }
            i+= p->getDimX()-1;
        }
    }
    file.close();
}

void Stat::update(int perso_mouv,int t_inv){
    int eauProd = 0;
    int energieProd = 0;
    int nourritureProd = 0;
    int joieProd = 0;
    int nbPersoProd = perso_mouv;
    int nbPersoMaxProd = 0;
    int tailleInvProd = 0;
    Piece *piece_tmp;
    for (int i = 0; i<4; ++i) {
        for(int j = 0; j<17; ++j) {
            piece_tmp= pieces[17*i+j];
            if (piece_tmp != nullptr) {
                switch(piece_tmp->getType()) {
                    case SALON: joieProd += piece_tmp->getProduction(); break;
                    case DORTOIR: nbPersoMaxProd += piece_tmp->getProduction(); break;
                    case REACTEUR: energieProd += piece_tmp->getProduction(); break;
                    case SELF: nourritureProd += piece_tmp->getProduction(); break;
                    case EAU: eauProd += piece_tmp->getProduction(); break;
                    case ATELIER: tailleInvProd += piece_tmp->getNiveau()*2; break;
                    default: break;
                }
                nbPersoProd += piece_tmp->getNbPerso();
                j+= piece_tmp->getDimX()-1;
            }
        }
    }
    joieProd = joieProd*2.5-nbPersoProd;
    energieProd = energieProd*2.5-nbPersoProd;
    nourritureProd = nourritureProd*2.5-nbPersoProd;
    eauProd = eauProd*2.5-nbPersoProd;
    if(joieProd < 0) bjoie = false; // nbPersoProd
    else bjoie = true;
    if( energieProd < 0) benergie = false;
    else benergie = true;
    if( nourritureProd < 0) bnourriture = false;
    else bnourriture = true;
    if(eauProd < 0) beau = false;
    else beau = true;

    joie += joieProd;
    if(joie<0) joie = 0;
    else if(joie>1000) joie= 1000;
    if(joie<334) alerte->addAlerte("Attention Tout le monde s'ennuie !",8);
    energie += energieProd;
    if(energie <0) energie = 0;
    else if(energie>1000) energie= 1000;
    if(energie<334) alerte->addAlerte("Attention Bientot plus de courant !",9);
    nourriture += nourritureProd;
    if(nourriture <0) nourriture = 0;
    else if(nourriture>1000) nourriture= 1000;
    if(nourriture<334) alerte->addAlerte("Attention la nourriture commence a manquer !",10);
    eau += eauProd;
    if(eau <0) eau = 0;
    else if(eau>1000) eau= 1000;
    if(eau<334) alerte->addAlerte("Attention il n'y aura bientot plus d'eau potable !",11);
    nbPerso = nbPersoProd;
    nbPersoMax = nbPersoMaxProd;

    if(tailleInvProd !=0) {
        taille_inv = tailleInvProd;
        double dt_inv = double(t_inv);
        double dtaille_inv = double(taille_inv);
        double coef = (dt_inv/dtaille_inv)*100;
        std::cout<<"coef : "<<coef<<std::endl;
        int ajout = 0;
        Piece* piece_tmp;
        if(coef > 33 && coef < 67) ajout = 3;
        else if(coef > 67) ajout  = 6;
        for (int i = 0; i<4; ++i) {
            for(int j = 0; j<17; ++j) {
                piece_tmp= pieces[17*i+j];
                if (piece_tmp != nullptr && piece_tmp->getType() == ATELIER) {
                    piece_tmp->setTexture(piece_tmp->getNiveau() + ajout);
                }
            }
        }
    }
}

void Stat::afficher() const {
    std::cout<<"Stats ->\n";
    std::cout<<"Joie : "<<joie<<"\n";
    std::cout<<"Energie : "<<energie<<"\n";
    std::cout<<"Eau : "<<eau<<"\n";
    std::cout<<"Nourriture : "<<nourriture<<"\n";
    std::cout<<"Nombre de lits : "<<nbPersoMax<<"\n";
    std::cout<<"-------------------------\n\n";
}

int Stat::getFerraille() const {
    return ferraille;
}
int& Stat::getObjFerraille(){
    return ferraille;
}
int Stat::getEau() const {
    return eau;
}
int Stat::getEnergie() const {
    return energie;
}
int Stat::getNourriture() const {
    return nourriture;
}
int Stat::getJoie() const {
    return joie;
}
int Stat::getNbPerso() const {
    return nbPerso;
}
int Stat::getNbPersoMax() const {
    return nbPersoMax;
}
int Stat::getLastUpdate() const {
    return lastUpdate;
}
int Stat::getTailleInv() const {
    return taille_inv;
}

void Stat::setFeraille( int value){
    ferraille = value;
    if (ferraille <0 ) ferraille= 0;
}
void Stat::setLastUpdate( int value){
    lastUpdate = value;
}
void Stat::setNbPerso( int value){
    nbPerso = value;
}
void Stat::setNbPersoMax( int value){
    nbPersoMax = value;
}
bool Stat::getBeau() const {
    return beau;
}
bool Stat::getBenergie() const {
    return benergie;
}
bool Stat::getBnourriture() const {
    return bnourriture;
}
bool Stat::getBjoie() const {
    return bjoie;
}

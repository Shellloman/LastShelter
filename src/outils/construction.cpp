#include "construction.h"

Construction::Construction(){
    pieces = nullptr;
}

void Construction::setPtr(Piece **pieces_,Alerte* alerte_){
    pieces = pieces_;
    alerte = alerte_;
    for(int i = 0; i<9; i++) {
        pieces_achetable[i] = false;
    }
    Piece * tmp1,* tmp2;
    for (int j = 0; j<9; ++j) {
        for(int i=0; i<16; ++i) {
            tmp1 = pieces[j*17+i]; tmp2 = pieces[j*17+i+1];
            if (j>0 && tmp2 == nullptr &&pieces[(j-1)*17+i+1] != nullptr &&pieces[(j-1)*17+i+1]->isAsc()) {
                if (chantier.estVide()) {chantier.ajouterEnQueue(co({j,i+1}));}
                else if(chantier.dernier().x != i+1 && chantier.dernier().y != j) {
                    chantier.ajouterEnQueue(co({j,i+1}));
                }
            }
            if (tmp1==nullptr && tmp2 != nullptr) {
                if (chantier.estVide()) {chantier.ajouterEnQueue(co({j,i}));}
                else if(chantier.dernier().x != i && chantier.dernier().y != j) {
                    chantier.ajouterEnQueue(co({j,i}));
                }
            }
            if (tmp1!=nullptr && tmp2 == nullptr) {
                if (chantier.estVide()) {chantier.ajouterEnQueue(co({j,i+1}));}
                else if(chantier.dernier().x != i+1 && chantier.dernier().y != j) {
                    chantier.ajouterEnQueue(co({j,i+1}));
                }
                cout<<"init des salles\n";
            }

        }
    }
    cout<<"Piece.s constructible.s\n";
    chantier.afficherDroiteGauche();
}


void Construction::nouvelle_piece(int y, int x,int k,Audio &audio, int& ferraille){
    if(chantier.estConstrcutible({y,x})) {
        choix_piece(y,x,k);
        if (pieces[y*17+x]!= nullptr) {
            pieces[y*17+x]->setAnim(60);
            ferraille -= pieces[y*17+x]->getPrix(1);
            alerte->addAlerte("Nouvelle piece construite pour "+to_string(pieces[y*17+x]->getPrix(1))+" ferrailles !",3);
        }else if(k>=-12 && k<= -4) {
            alerte->addAlerte("Pas assez d'argent ou pas assez de place !",4);
        }
        if(pieces[y*17+x]!=nullptr && pieces[y*17+x]->isAsc()) {
            chantier.sup({y,x});
            if(x<16 && pieces[y*17+x+1]==nullptr && !chantier.estConstrcutible({y,x+1})) chantier.ajouterEnQueue(co({y,x+1}));
            if(x>0  && pieces[y*17+x-1]==nullptr&& !chantier.estConstrcutible({y,x-1})) chantier.ajouterEnQueue(co({y,x-1}));
            if(x<17 && x>=0 && y<8 && pieces[(y+1)*17+x]==nullptr) chantier.ajouterEnQueue(co({y+1,x}));
            cout<< "Création d'un ascenceur en " <<y<<" , "<<x<<endl;
            audio.play_travaux();
        }
        else if (pieces[y*17+x]!=nullptr) {
            int dir = pieceConstructible(y,x,1);
            if(dir != 0) {
                if (dir ==-1) {
                    pieces[y*17+x]->setYX(y,x-2);
                }
                chantier.sup({y,x}); chantier.sup({y,x+1*dir}); chantier.sup({y,x+2*dir});
                pieces[y*17+x+2*dir] = pieces[y*17+x+1*dir] = pieces[y*17+x];
                if(dir == 1 && x<14 && pieces[y*17+x+3]==nullptr && !chantier.estConstrcutible({y,x+3})) chantier.ajouterEnQueue(co({y,x+3}));
                if(dir ==-1 && x>2  && pieces[y*17+x-3]==nullptr&& !chantier.estConstrcutible({y,x-3})) chantier.ajouterEnQueue(co({y,x-3}));
                audio.play_travaux();
            }
            else{
                pieces[y*17+x]=nullptr;
            }
        }
        else cout<<"construction annulé\n";
    }
}

int Construction::pieceConstructible(int y,int x,int k) const {
    int ret = 0;
    if(k == 1 || k == 3) {
        if(x<15 && pieces[y*17+x+1]==nullptr && pieces[y*17+x+2]==nullptr) ret = 1;
        if(x>1 && pieces[y*17+x-1]==nullptr && pieces[y*17+x-2]==nullptr) ret = -1;
    }else if(k == 2) {
        if(x<16 && pieces[y*17+x+1]==nullptr ) ret = 1;
        if(x>0 && pieces[y*17+x-1]==nullptr ) ret = -1;
    }
    return ret;
}

void Construction::choix_piece(int y,int x,int k){
    switch (k) {
        case -12: if(pieces_achetable[ASC]) { pieces[y*17+x] = new Piece(y,x); pieces[y*17+x]->setAsc(); break;}
        case -11: if(pieces_achetable[DORTOIR]) { pieces[y*17+x] = new Dortoir(y,x); break;}
        case -10: if(pieces_achetable[REACTEUR]) { pieces[y*17+x] = new Reacteur(y,x); break;}
        case -9: if(pieces_achetable[EAU]) { pieces[y*17+x] = new Eaupotable(y,x); break;}
        case -8: if(pieces_achetable[SELF]) { pieces[y*17+x] = new Refectoire(y,x); break;}
        case -7: if(pieces_achetable[ATELIER]) { pieces[y*17+x] = new Atelier(y,x); break;}
        case -6: if(pieces_achetable[SALON]) { pieces[y*17+x] = new Salon(y,x); break;}
        case -5: if(pieces_achetable[INFIRM]) { pieces[y*17+x] = new Infirmerie(y,x); break;}
        case -4: if(pieces_achetable[MILICE]) { pieces[y*17+x] = new Milice(y,x); break;}
        default: return;
    }
}
Cellule* Construction::getPtrPrem() const {
    return chantier.prem;
}

bool Construction::estConstrcutible(int y,int x) const {
    return chantier.estConstrcutible({y,x});
}
bool Construction::estAchetable(int i) const {
    return pieces_achetable[i];
}

void Construction::setAchetable(int y,int x, int ferraille){
    bool placement = pieceConstructible(y,x,1) !=0 && (y==0 ||pieces[(y-1)*17+x]==nullptr || !pieces[(y-1)*17+x]->isAsc());
    if(ferraille > 100) pieces_achetable[ASC] = true;
    else pieces_achetable[ASC] = false;
    if(placement && ferraille >= 100) pieces_achetable[DORTOIR] = true;
    else pieces_achetable[DORTOIR] = false;
    if(placement && ferraille >= 100) pieces_achetable[REACTEUR] = true;
    else pieces_achetable[REACTEUR] = false;
    if(placement && ferraille >= 100) pieces_achetable[EAU] = true;
    else pieces_achetable[EAU] = false;
    if(placement && ferraille >= 100) pieces_achetable[SELF] = true;
    else pieces_achetable[SELF] = false;
    if(placement && ferraille >= 100) pieces_achetable[ATELIER] = true;
    else pieces_achetable[ATELIER] = false;
    if(placement && ferraille >=100) pieces_achetable[SALON] = true;
    else pieces_achetable[SALON] = false;
    if(placement && ferraille >= 100) pieces_achetable[INFIRM] = true;
    else pieces_achetable[INFIRM] = false;
    if(placement && ferraille >= 200) pieces_achetable[MILICE] = true;
    else pieces_achetable[MILICE] = false;
}
bool Construction::estAgrandissable(Piece *p,int ferraille) const {
    bool tmp = false;
    switch(pieceConstructible(p->getY(),p->getX()+p->getDimX()-1,p->getNiveau()+1)) {
        case  0: break;
        case  1: tmp = true; break;
        case -1: tmp = true; break;
        default: break;
    }
    switch(pieceConstructible(p->getY(),p->getX(),p->getNiveau()+1)) {
        case  0: break;
        case  1: tmp = true; break;
        case -1: tmp = true; break;
        default: break;
    }
    if (ferraille < int(p->getPrix(p->getNiveau()+1)) || p->getPrix(p->getNiveau()+1) == 0) tmp = false;
    p->setAgran(tmp);
    return tmp;
}
void Construction::Agrandir(Piece *&p,Audio &audio, int& ferraille){
    if (!p->getAgran()) {cout<<"hum nope\n"; return;}
    int y = p->getY();
    int x = p->getX();
    int dir;
    dir = pieceConstructible(p->getY(),p->getX(),p->getNiveau()+1);
    if (dir == 0) dir = 1;
    if (p->getNiveau()+1 == 2) {
        if (dir == 1) {
            pieces[y*17+x+3] = p;
            chantier.sup({y,x+3});
            if(x+4<17 && pieces[y*17+x+4]==nullptr && !chantier.estConstrcutible({y,x+4})) chantier.ajouterEnQueue(co({y,x+4}));
        }else{
            pieces[y*17+x-1] = p;
            p->setYX(y,x-1);
            chantier.sup({y,x-1});
            if(x-2> -1 && pieces[y*17+x-2]==nullptr && !chantier.estConstrcutible({y,x-2})) chantier.ajouterEnQueue(co({y,x-2}));
            if(p->getNbPerso() > 0) p->getPerso(0)->setCo(p->getPerso(0)->getX()-96);
        }
        p->setDimX(4);
        p->setNiveau(2);
        p->setTexture(2);
        p->setAnim(60);
        ferraille -= p->getPrix(2);
        alerte->addAlerte("Piece agrandis pour "+to_string(p->getPrix(2))+" ferrailles !",5);
    }else
    if (p->getNiveau()+1 == 3) {
        if (dir == 1) {
            pieces[y*17+x+4] = pieces[y*17+x+5] = p;
            chantier.sup({y,x+4}); chantier.sup({y,x+5});
            if(x+6<17 && pieces[y*17+x+6]==nullptr && !chantier.estConstrcutible({y,x+6})) chantier.ajouterEnQueue(co({y,x+6}));
        }else{
            pieces[y*17+x-1] = pieces[y*17+x-2] = p;
            p->setYX(y,x-2);
            chantier.sup({y,x-1}); chantier.sup({y,x-2});
            if(x-3>-1  && pieces[y*17+x-3]==nullptr && !chantier.estConstrcutible({y,x-3})) chantier.ajouterEnQueue(co({y,x-3}));
            if(p->getNbPerso() > 0) p->getPerso(0)->setCo(p->getPerso(0)->getX()-96*2);
            if(p->getNbPerso() > 1) p->getPerso(1)->setCo(p->getPerso(1)->getX()-96*2);
        }
        p->setDimX(6);
        p->setNiveau(3);
        p->setTexture(3);
        p->setAnim(60);
        ferraille -= p->getPrix(3);
        alerte->addAlerte("Piece agrandis pour "+to_string(p->getPrix(2))+" ferrailles !",6);
    }
    audio.play_travaux();
}

bool Construction::estDestructible(Piece *p) const {
    int y = p->getY();
    int x = p->getX();
    bool tmp = false;
    if ((x != 0 || y != 0) && !p->isAsc()) {
        if(x-1 < 0 || pieces[y*17+x-1] == nullptr) tmp = true;
        else if(x+int(p->getDimX())+1 > 16 || pieces[y*17+x+int(p->getDimX())+1] == nullptr) tmp = true;
    }else if (p->isAsc()) {
        if(y+1>8 || pieces[(y+1)*17+x]==nullptr) {
            if ((x-1 < 0 && pieces[y*17+x+1]==nullptr)||(x+1 > 16 && pieces[y*17+x-1]==nullptr)) tmp = true;
            else if(pieces[y*17+x+1]==nullptr && pieces[y*17+x-1]==nullptr ) tmp = true;
            else if( ( y-1 < 0 || (pieces[(y-1)*17+x]!=nullptr && !pieces[(y-1)*17+x]->isAsc()) )
                     && ((x+1 < 17 && pieces[y*17+x+1]==nullptr) || ( x-1 > -1 && pieces[y*17+x-1]==nullptr)))
                tmp = true;
        }
    }
    if(p->getNbPerso()!=0) tmp = false;
    p->setDest(tmp);
    return tmp;
}
void Construction::destruction(Piece *&p,Audio &audio){
    if (!p->getDest()) return;
    int y = p->getY();
    int x = p->getX();
    if (p->isAsc()) {
        chantier.sup({y,x+1}); chantier.sup({y,x-1}); chantier.sup({y+1,x});
        chantier.ajouterEnQueue({y,x});
        delete pieces[y*17+x];
        pieces[y*17+x] = nullptr;
    }else{
        if(chantier.estConstrcutible({y,x-1})) {
            chantier.sup({y,x-1});
            chantier.ajouterEnQueue({y,x + int(p->getDimX())-1});
        }else if(chantier.estConstrcutible({y,x+int(p->getDimX())})) {
            chantier.sup({y,x+int(p->getDimX())});
            chantier.ajouterEnQueue({y,x});
        }else if(x+p->getDimX()>=16) {
            chantier.ajouterEnQueue({y,x});
        }
        for (int i = 0; i<int(p->getDimX()); i++) {
            pieces[y*17+x+i] = nullptr;
        }
        delete p;
        p = nullptr;
    }
    alerte->addAlerte("Piece Detruite !",7);
    audio.play_travaux();
}
void Construction::clear(){
    chantier.vider();
}
Construction::~Construction() {

}

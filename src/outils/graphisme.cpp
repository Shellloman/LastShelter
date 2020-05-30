#include "graphisme.h"

Graphisme::Graphisme(SDL_Renderer *rendu_){
    rendu = rendu_;
    T_Pieces = new SDL_Texture* [31];
    T_Pieces[ASC] = Load("data/img/pieces/ascenceur.png");
    T_Pieces[DORTOIR1] = Load("data/img/pieces/dortoir_taille1.png");// remplacer par dortoire
    T_Pieces[DORTOIR2] = Load("data/img/pieces/dortoir_taille2.png");
    T_Pieces[DORTOIR3] = Load("data/img/pieces/dortoir_taille3.png");
    T_Pieces[EAU1] = Load("data/img/pieces/eau_taille1.png");
    T_Pieces[EAU2] = Load("data/img/pieces/eau_taille2.png");
    T_Pieces[EAU3] = Load("data/img/pieces/eau_taille3.png");
    T_Pieces[INFIRM1] = Load("data/img/pieces/infirmerie_taille1.png");
    T_Pieces[INFIRM2] = Load("data/img/pieces/infirmerie_taille2.png");
    T_Pieces[INFIRM3] = Load("data/img/pieces/infirmerie_taille3.png");
    T_Pieces[MILICE1] = Load("data/img/pieces/sas_taille1.png");
    T_Pieces[MILICE2] = Load("data/img/pieces/sas_taille2.png");
    T_Pieces[MILICE3] = Load("data/img/pieces/sas_taille3.png");
    T_Pieces[REACTEUR1] = Load("data/img/pieces/reacteur_taille1.png");
    T_Pieces[REACTEUR2] = Load("data/img/pieces/reacteur_taille2.png");
    T_Pieces[REACTEUR3] = Load("data/img/pieces/reacteur_taille3.png");
    T_Pieces[SELF1] = Load("data/img/pieces/self_taille1.png");
    T_Pieces[SELF2] = Load("data/img/pieces/self_taille2.png");
    T_Pieces[SELF3] = Load("data/img/pieces/self_taille3.png");
    T_Pieces[SALON1] = Load("data/img/pieces/salon_taille1.png");
    T_Pieces[SALON2] = Load("data/img/pieces/salon_taille2.png");
    T_Pieces[SALON3] = Load("data/img/pieces/salon_taille3.png");
    T_Pieces[ATELIER1S] = Load("data/img/pieces/atelier_taille1_s.png");
    T_Pieces[ATELIER1M] = Load("data/img/pieces/atelier_taille1_m.png");
    T_Pieces[ATELIER1L] = Load("data/img/pieces/atelier_taille1_l.png");
    T_Pieces[ATELIER2S] = Load("data/img/pieces/atelier_taille2_s.png");
    T_Pieces[ATELIER2M] = Load("data/img/pieces/atelier_taille2_m.png");
    T_Pieces[ATELIER2L] = Load("data/img/pieces/atelier_taille2_l.png");
    T_Pieces[ATELIER3S] = Load("data/img/pieces/atelier_taille3_s.png");
    T_Pieces[ATELIER3M] = Load("data/img/pieces/atelier_taille3_m.png");
    T_Pieces[ATELIER3L] = Load("data/img/pieces/atelier_taille3_l.png");

    T_Select = new SDL_Texture*[13];
    T_Select[TRAVAUX] = Load("data/img/construire.png");
    T_Select[SEL_PIECE1] = Load("data/img/selection_piece1.png");
    T_Select[SEL_PIECE2] = Load("data/img/selection_piece2.png");
    T_Select[SEL_PIECE3] = Load("data/img/selection_piece3.png");
    T_Select[SEL_ASC] = Load("data/img/selection_asc.png");
    T_Select[M1_PIECE] = Load("data/img/menu1_piece.png");
    T_Select[M2_PIECE] = Load("data/img/menu2_piece.png");
    T_Select[M3_PIECE] = Load("data/img/menu3_piece.png");
    T_Select[M1_TRAVAUX] = Load("data/img/menu1_construction.png");
    T_Select[M2_TRAVAUX] = Load("data/img/menu2_construction.png");
    T_Select[EXPL1] = Load("data/img/exploration_t1.png");
    T_Select[EXPL2] = Load("data/img/exploration_t2.png");
    T_Select[EXPL3] = Load("data/img/exploration_t3.png");

    T_Decor = new SDL_Texture*[8];
    T_Decor[FOND] = Load("data/img/fond.png");
    T_Decor[EFFECT] = Load("data/img/effect.png");
    T_Decor[PANNEAU] = Load("data/img/panneau.png");
    T_Decor[CT1] = Load("data/img/contour_t1.png");
    T_Decor[CT2] = Load("data/img/contour_t2.png");
    T_Decor[CT3] = Load("data/img/contour_t3.png");
    T_Decor[CURSOR] = Load("data/img/cursor.png");
    T_Decor[CHOIX] = Load("data/img/choix.png");

    T_Stat = new SDL_Texture*[13];
    T_Stat[0] = Load("data/img/barre_fond.png");
    T_Stat[1] = Load("data/img/barre_v.png");
    T_Stat[2] = Load("data/img/barre_r.png");
    T_Stat[3] = Load("data/img/barre_n.png");
    T_Stat[4] = nullptr;
    T_Stat[5] = Load("data/img/icone_scrap.png");
    T_Stat[6] = Load("data/img/icone_personnes.png");
    T_Stat[7] = Load("data/img/icone_energie.png");
    T_Stat[8] = Load("data/img/icone_eau.png");
    T_Stat[9] = Load("data/img/icone_nourriture.png");
    T_Stat[10] = Load("data/img/icone_joie.png");
    T_Stat[11] = Load("data/img/sac.png");
    T_Stat[12] =  Load("data/img/sac_ouvert.png");

    T_Perso = new SDL_Texture*[8];
    T_Perso[0] = Load("data/img/personnage/sprite_base.png");
    T_Perso[1] = Load("data/img/personnage/haut_blanc.png");
    T_Perso[2] = Load("data/img/personnage/haut_rouge.png");
    T_Perso[3] = Load("data/img/personnage/haut_bleu.png");
    T_Perso[4] = Load("data/img/personnage/bas_bleu.png");
    T_Perso[5] = Load("data/img/personnage/bas_marron.png");
    T_Perso[6] = Load("data/img/personnage/tete_blond.png");
    T_Perso[7] = Load("data/img/personnage/tete_brun.png");


    for(int i = 0; i<17; i++) {
        if (i == 0) {
            sPerso[i].x = 30; sPerso[i].y = 164*2; sPerso[i].w = 70; sPerso[i].h = 164;
        }else if(i<9) {
            sPerso[i].x = 128*(i-1)+30; sPerso[i].y = 0; sPerso[i].w = 70; sPerso[i].h = 164;
        }else{
            sPerso[i].x = 128*(i-9)+30; sPerso[i].y = 164; sPerso[i].w = 70; sPerso[i].h = 164;
        }
    }
    couleur = {200,200,200};
    police = TTF_OpenFont("data/img/MYTYPE.ttf", 40); // chiptype.ttf NOZSTUDIO.ttf SHPinscher-Regular.otf
    ttf = new SDL_Texture* [14];
    SDL_Surface *tmp;
    T_alerte = nullptr;
    string s[14] = {"Ascenceur","Dortoir","Reacteur","Eau potable","Refectoire","Atelier","Salon","Infirmerie","Milice","Infos","Travaux","Retour","Agrandir","Detruire"};
    for (int i = 0; i<14; i++) {
        tmp = TTF_RenderText_Solid(police,s[i].c_str(), couleur);
        rttf[i].w = tmp->w;
        rttf[i].h = tmp->h;
        ttf[i] =  SDL_CreateTextureFromSurface(rendu,tmp);
    }

    rFond.x = -(1920-1920)/2; rFond.y= 1080-2700; rFond.h= 2700; rFond.w = 1920;
    rCarte.x = (1920-1280/2)/2; rCarte.y= (1080-900)/2; rCarte.h= 900; rCarte.w = 1280/2;
    rPiece.x = 0; rPiece.y=0; rPiece.h= 270; rPiece.w = 96;
    rCursor.x = 0; rCursor.y = 0; rCursor.w = 36; rCursor.h = 48;
}

void Graphisme::setPtr(Piece** pieces_,Alerte* alerte_){
    pieces = pieces_;
    alerte = alerte_;
}
void Graphisme::setTexturePersonnage(){
    Piece *piece;
    for (int i = 0; i<4; ++i) {
        for(int j = 0; j<17; ++j) {
            piece= pieces[17*i+j];
            if(piece!=nullptr) {
                for(int k = 0; k<int(piece->getNbPerso()); k++) {
                    V_perso.push_back(CreateTexturePerso(piece->getPerso(k)));
                    piece->getPerso(k)->setTexture(V_perso.size());
                }
            }
        }
    }
}
SDL_Texture* Graphisme::Load(const char* chemin){
    SDL_Surface *surface = IMG_Load(chemin);
    if (surface == NULL) {
        cout<<"Error: ne peut pas charger l'image "<< chemin <<endl;
        exit(1);
    }
    SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(surface,SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(surface);
    surface = surfaceCorrectPixelFormat;

    SDL_Texture *texture = SDL_CreateTextureFromSurface(rendu,surface);
    if (texture == NULL) {
        cout << "Error: problème pour créer la texture "<< chemin<< endl;
        exit(1);
    }
    cout<<"texture de "<<chemin<<" chargé"<<endl;
    SDL_FreeSurface(surfaceCorrectPixelFormat);
    return texture;
}

void Graphisme::Affichage_jeu(Construction &batiment,SDL_Rect *tab){
    SDL_RenderClear(rendu);
    SDL_RenderCopy(rendu,T_Decor[FOND],NULL,&rFond);
    SDL_Rect rPerso,rClipp;
    Piece *piece_tmp;
    for (int i = 0; i<4; ++i) {
        for(int j = 0; j<17; ++j) {
            piece_tmp= pieces[17*i+j];
            if(piece_tmp!=nullptr) {
                rPiece.x = tab[i*17+j].x; rPiece.y = tab[i*17+j].y+rFond.y; rPiece.w = 96*piece_tmp->getDimX();
                SDL_RenderCopy(rendu,T_Pieces[piece_tmp->getTexture()],NULL,&rPiece);
                for(unsigned int i = 0; i<piece_tmp->getNbPerso(); i++) {
                    rPerso = {rPiece.x+50+200*int(i),rPiece.y+90,70,164};
                    if ( !piece_tmp->getPerso(i)->getDeplacement())
                        SDL_RenderCopy(rendu,V_perso[piece_tmp->getPerso(i)->getTexture()-1],&sPerso[piece_tmp->getPerso(i)->getSprite()],&rPerso);
                }
                if(piece_tmp->getAnim()>0) {
                    int i = 13 - int(piece_tmp->getAnim()*0.217);
                    rClipp = {104*i,0,104,104};
                    SDL_RenderCopy(rendu,T_Decor[EFFECT],&rClipp,&rPiece);
                    piece_tmp->setAnim(piece_tmp->getAnim()-1);
                }
                j=j+piece_tmp->getDimX()-1;
            }
        }
    }
    Cellule* tmp = batiment.getPtrPrem();
    int i,j;
    rPiece.w = 96;
    while(tmp != nullptr) {
        i = tmp->info.y; j = tmp->info.x;
        rPiece.x = tab[i*17+j].x; rPiece.y = tab[i*17+j].y+rFond.y;
        SDL_RenderCopy(rendu,T_Select[TRAVAUX],NULL,&rPiece);
        tmp = tmp->suivant;
    }
}
void Graphisme::Afficher_selection(Piece *p,SDL_Rect *tab){
    if (p != nullptr &&p->getSelection()) {
        rPiece.x = tab[p->getY()*17+p->getX()].x; rPiece.y = tab[p->getY()*17+p->getX()].y+rFond.y; rPiece.w = 96*p->getDimX();
        if(p->isAsc()) SDL_RenderCopy(rendu,T_Select[SEL_ASC],NULL,&rPiece);
        else if(p->getNiveau()==1) SDL_RenderCopy(rendu,T_Select[SEL_PIECE1],NULL,&rPiece);
        else if(p->getNiveau()==2) SDL_RenderCopy(rendu,T_Select[SEL_PIECE2],NULL,&rPiece);
        else if(p->getNiveau()==3) SDL_RenderCopy(rendu,T_Select[SEL_PIECE3],NULL,&rPiece);

        if(p->getType()==MILICE) {
            SDL_Rect r;
            switch(p->getNiveau()) {
                case 1: r = {rPiece.x,rPiece.y-30,rPiece.w,30};
                    SDL_RenderCopy(rendu,T_Select[EXPL1],NULL,&r); break;
                case 2: r = {rPiece.x,rPiece.y-30,rPiece.w,30};
                    SDL_RenderCopy(rendu,T_Select[EXPL2],NULL,&r); break;
                case 3: r = {rPiece.x,rPiece.y-30,rPiece.w,30};
                    SDL_RenderCopy(rendu,T_Select[EXPL3],NULL,&r); break;
                default: break;
            }
        }
    }
}
void Graphisme::Afficher_contour(Construction &batiment,SDL_Rect *tab){
    Piece *piece_tmp;
    for (int i = 0; i<4; ++i) {
        for(int j = 0; j<17; ++j) {
            piece_tmp= pieces[17*i+j];
            if(piece_tmp!=nullptr) {
                rPiece.x = tab[i*17+j].x; rPiece.y = tab[i*17+j].y+rFond.y; rPiece.w = 96*piece_tmp->getDimX();
                switch (piece_tmp->getNiveau()) {
                    case 1: SDL_RenderCopy(rendu,T_Decor[CT1],NULL,&rPiece); break;
                    case 2: SDL_RenderCopy(rendu,T_Decor[CT2],NULL,&rPiece); break;
                    case 3: SDL_RenderCopy(rendu,T_Decor[CT3],NULL,&rPiece); break;
                }
                j=j+piece_tmp->getDimX()-1;
            }
        }
    }
}

void Graphisme::Afficher_menu_piece(Piece* tmp,Construction &batiment){
    SDL_Rect r,rtext;
    int nb;
    r.x = 0; r.h = 1080/4; r.w = 94*3;
    rtext.x = 10;
    if(tmp->getSelection()==1) {
        for(int i =0; i<3; ++i) {
            r.y=1080/4*i;
            rtext.h = rttf[9+i].h; rtext.w = rttf[9+i].w;
            rtext.y = r.y+(1080/4  - rtext.h)/2;
            rtext.x = (288 - rtext.w)/2;
            SDL_RenderCopy(rendu,T_Select[M1_PIECE],NULL,&r);
            SDL_RenderCopy(rendu,ttf[9+i],NULL,&rtext);
        }
    }else if(tmp->getSelection()==3) {

        r.y=1080/4*0;
        rtext.h = rttf[13].h; rtext.w = rttf[13].w;
        rtext.y = r.y+(1080/4  - rtext.h)/2;
        rtext.x = (288 - rtext.w)/2;
        nb = M2_PIECE;
        if (tmp->getDest()) nb = M1_PIECE;
        SDL_RenderCopy(rendu,T_Select[nb],NULL,&r);
        SDL_RenderCopy(rendu,ttf[13],NULL,&rtext);

        r.y=1080/4*1;
        rtext.h = rttf[12].h; rtext.w = rttf[12].w;
        rtext.y = r.y+(1080/4  - rtext.h)/2;
        rtext.x = (288 - rtext.w)/2;
        if (tmp->getAgran()) nb = M1_PIECE;
        else nb = M2_PIECE;
        SDL_RenderCopy(rendu,T_Select[nb],NULL,&r);
        SDL_RenderCopy(rendu,ttf[12],NULL,&rtext);

        r.y=1080/4*2;
        rtext.h = rttf[11].h; rtext.w = rttf[11].w;
        rtext.y = r.y+(1080/4  - rtext.h)/2;
        rtext.x = (288 - rtext.w)/2;
        SDL_RenderCopy(rendu,T_Select[M1_PIECE],NULL,&r);
        SDL_RenderCopy(rendu,ttf[11],NULL,&rtext);

    }else if(tmp->getSelection()==2) {
        r.y=1080/4*0;
        r.h = r.h*2;
        SDL_RenderCopy(rendu,T_Select[M1_PIECE],NULL,&r);
        r.y=1080/4*2;
        r.h = r.h/2;
        rtext.h = rttf[11].h; rtext.w = rttf[11].w;
        rtext.y = r.y+(1080/4  - rtext.h)/2;
        rtext.x = (288 - rtext.w)/2;
        SDL_RenderCopy(rendu,T_Select[M1_PIECE],NULL,&r);
        SDL_RenderCopy(rendu,ttf[11],NULL,&rtext);
    }
}

void Graphisme::Afficher_menu_construction(Construction &batiment){
    int a;
    SDL_Rect tmp;
    for (int i = 0; i<9; ++i) {
        tmp.x = 0; tmp.y = 90*i; tmp.h = 90; tmp.w = 288;
        if (batiment.estAchetable(i)) a= M1_TRAVAUX;
        else a= M2_TRAVAUX;
        SDL_RenderCopy(rendu,T_Select[a],NULL,&tmp);
        tmp.h = rttf[i].h; tmp.w = rttf[i].w;
        tmp.y = tmp.y+(1080/12  - tmp.h)/2;
        tmp.x = (288 - tmp.w)/2;
        SDL_RenderCopy(rendu,ttf[i],NULL,&tmp);
    }
}
void Graphisme::Afficher_stat(Stat &stat,int fps,bool inv){
    int a;
    string s;

    s = to_string(fps);
    SDL_Surface *tmp = TTF_RenderText_Solid(police,s.c_str(), couleur);
    T_Stat[4] =  SDL_CreateTextureFromSurface(rendu,tmp);
    SDL_Rect rfps = {0,1000,tmp->w,tmp->h};
    SDL_RenderCopy(rendu,T_Stat[4],NULL,&rfps);

    rfps.x = 50,rfps.y = 15;
    SDL_QueryTexture(T_Stat[11],NULL,NULL,&rfps.w,&rfps.h);
    rfps.w *= 0.75; rfps.h *= 0.75;
    if (inv) a = 12; else a = 11;
    SDL_RenderCopy(rendu,T_Stat[a],NULL,&rfps);

    s = to_string(stat.getFerraille());
    tmp = TTF_RenderText_Solid(police,s.c_str(), couleur);
    T_Stat[4] =  SDL_CreateTextureFromSurface(rendu,tmp);

    SDL_Rect rIcone = {270,20,80,80};
    SDL_Rect rBarre = {rIcone.x + rIcone.w +20,rIcone.y + (rIcone.h - tmp->h)/2,tmp->w,tmp->h};
    SDL_Rect rBarref = {0,0,200+6,14};

    SDL_RenderCopy(rendu,T_Stat[5],NULL,&rIcone);
    SDL_RenderCopy(rendu,T_Stat[4],NULL,&rBarre);

    s = to_string(stat.getNbPerso());
    s+= string("/");
    s+= to_string(stat.getNbPersoMax());
    tmp = TTF_RenderText_Solid(police,s.c_str(), couleur);
    T_Stat[4] =  SDL_CreateTextureFromSurface(rendu,tmp);

    rIcone = {rIcone.x+200,20,80,80};
    rBarre = {rIcone.x + rIcone.w +20,rIcone.y + (rIcone.h - tmp->h)/2,tmp->w,tmp->h};

    SDL_RenderCopy(rendu,T_Stat[6],NULL,&rIcone);
    SDL_RenderCopy(rendu,T_Stat[4],NULL,&rBarre);

    rIcone = {rIcone.x+220,20,80,80};
    rBarre = {rIcone.x + rIcone.w +5,rIcone.y + (rIcone.h - 10)/2,int(stat.getEnergie())/5,10};
    rBarref.x = rBarre.x - 3; rBarref.y = rBarre.y - 2;
    if(stat.getBenergie()) a = 1;
    else a= 2;
    SDL_RenderCopy(rendu,T_Stat[7],NULL,&rIcone);
    SDL_RenderCopy(rendu,T_Stat[0],NULL,&rBarref);
    SDL_RenderCopy(rendu,T_Stat[a],NULL,&rBarre);

    rIcone = {rIcone.x+312,20,80,80};
    rBarre = {rIcone.x + rIcone.w +5,rIcone.y + (rIcone.h - 10)/2,int(stat.getEau())/5,10};
    rBarref.x = rBarre.x - 3; rBarref.y = rBarre.y - 2;
    if(stat.getBeau()) a = 1;
    else a= 2;
    SDL_RenderCopy(rendu,T_Stat[8],NULL,&rIcone);
    SDL_RenderCopy(rendu,T_Stat[0],NULL,&rBarref);
    SDL_RenderCopy(rendu,T_Stat[a],NULL,&rBarre);

    rIcone = {rIcone.x+312,20,80,80};
    rBarre = {rIcone.x + rIcone.w +5,rIcone.y + (rIcone.h - 10)/2,int(stat.getNourriture())/5,10};
    rBarref.x = rBarre.x - 3; rBarref.y = rBarre.y - 2;
    if(stat.getBnourriture()) a = 1;
    else a= 2;
    SDL_RenderCopy(rendu,T_Stat[9],NULL,&rIcone);
    SDL_RenderCopy(rendu,T_Stat[0],NULL,&rBarref);
    SDL_RenderCopy(rendu,T_Stat[a],NULL,&rBarre);

    rIcone = {rIcone.x+312,20,80,80};
    rBarre = {rIcone.x + rIcone.w +5,rIcone.y + (rIcone.h - 10)/2,int(stat.getJoie())/5,10};
    rBarref.x = rBarre.x - 3; rBarref.y = rBarre.y - 2;
    if(stat.getBjoie()) a = 1;
    else a= 2;
    SDL_RenderCopy(rendu,T_Stat[10],NULL,&rIcone);
    SDL_RenderCopy(rendu,T_Stat[0],NULL,&rBarref);
    SDL_RenderCopy(rendu,T_Stat[a],NULL,&rBarre);
}

void Graphisme::Afficher_perso(vector<Personnage*> v,Mouvement &mouv){
    int value = 0;
    for (long unsigned int it = 0; it < v.size(); it++) {
        SDL_Rect r = {int(v[it]->getX()),int(v[it]->getY())+rFond.y,int(v[it]->getW()),int(v[it]->getH())};
        if (v[it]->getTexture()==PERSO) {
            V_perso.push_back(CreateTexturePerso(v[it]));
            v[it]->setTexture(V_perso.size());
        }
        SDL_RenderCopy(rendu,V_perso[v[it]->getTexture()-1],&sPerso[v[it]->getSprite()],&r);
        value++;
    }
    Personnage * p;
    for (long unsigned int i = 0; i<mouv.getPerso().size(); i++) {
        p = mouv.getPerso()[i];
        if(!(p->getDeplacement())) {
            SDL_Rect r = {int(p->getX()),int(p->getY())+rFond.y,int(p->getW()),int(p->getH())};
            p->nextSprite();
            SDL_RenderCopy(rendu,V_perso[p->getTexture()-1],&sPerso[p->getSprite()],&r);
        }
    }
}
void Graphisme::Afficher_caracteristique(Personnage *p){
    if(p->getId_caract()<0) {
        caract.push_back(sautligne(p->getStringCaract(),false));
        p->setId_caract(caract.size()-1);
    }
    SDL_Rect dim2;
    SDL_QueryTexture(caract[p->getId_caract()],NULL,NULL,&dim2.w,&dim2.h);
    dim2.w *= 0.5; dim2.h *= 0.5;
    dim2.x  = int(p->getX()-(dim2.w-p->getW())/2); dim2.y = int(p->getY())-dim2.h+rFond.y;
    SDL_RenderCopy(rendu,caract[p->getId_caract()],NULL,&dim2);
}

SDL_Texture * Graphisme::CreateTexturePerso(Personnage * p){
    SDL_Texture *tmp = SDL_CreateTexture(rendu, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,1024,164*3);
    SDL_SetRenderTarget(rendu,tmp);
    SDL_SetTextureBlendMode(tmp,SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawBlendMode(rendu, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(rendu, 0,0,0,0);
    SDL_RenderClear(rendu);
    SDL_RenderCopy(rendu,T_Perso[0],NULL,NULL);
    if(p->getTexHaut() == -1) p->setTexHaut(rand()%3+1);
    if(p->getTexBas() == -1) p->setTexBas(rand()%2+4);
    if(p->getTexTete() == -1) p->setTexTete(rand()%2+6);
    SDL_RenderCopy(rendu,T_Perso[p->getTexHaut()],NULL,NULL);
    SDL_RenderCopy(rendu,T_Perso[p->getTexBas()],NULL,NULL);
    SDL_RenderCopy(rendu,T_Perso[p->getTexTete()],NULL,NULL);
    SDL_SetRenderTarget(rendu,NULL);
    return tmp;

}
SDL_Texture* Graphisme::sautligne(string str,bool taille_fixe){
    vector<string> vstr;
    vector<SDL_Surface*> vsur;
    SDL_Texture *tmp = nullptr;
    SDL_Texture *tmp2 = nullptr;
    SDL_Rect r;

    int n = str.size();
    int ntmp = 0;
    for(int i = 0; i<n; i++) {
        if(str[i]=='/') {
            vstr.push_back(str.substr(ntmp,i-ntmp));
            ntmp = i+1;
        }
    }
    vstr.push_back(str.substr(ntmp,n-ntmp));
    for(long unsigned int i = 0; i<vstr.size(); i++) {
        vsur.push_back(TTF_RenderText_Solid(police,vstr[i].c_str(), couleur));
    }
    n = 0;
    for(long unsigned int i = 0; i<vsur.size(); i++) {
        if(vsur[i]->w > vsur[n]->w) {
            n = i;
        }
    }
    if(taille_fixe) {
        tmp = SDL_CreateTexture(rendu, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,335,150);
        r = {0,0,335,150};
    }else{
        tmp = SDL_CreateTexture(rendu, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,vsur[n]->w+20,vsur.size()*vsur[n]->h);
        r = {0,0,vsur[n]->w+20,int(vsur.size())*vsur[n]->h};
    }
    SDL_SetRenderTarget(rendu,tmp);
    SDL_SetRenderDrawColor(rendu,0,0,0,0);
    SDL_RenderFillRect(rendu,NULL);
    SDL_RenderCopy(rendu,T_Decor[PANNEAU],NULL,&r);
    for(long unsigned int i = 0; i<vsur.size(); i++) {
        r.x = 10;
        r.y = 5+(vsur[n]->h-3)*i;
        r.h = vsur[i]->h+4;
        r.w = vsur[i]->w;
        tmp2 = SDL_CreateTextureFromSurface(rendu,vsur[i]);
        SDL_RenderCopy(rendu,tmp2,NULL,&r);
    }
    SDL_SetRenderTarget(rendu,NULL);
    return tmp;
}
void Graphisme::Afficher_alerte(){
    if(alerte->getNombre()>0) {
        if(alerte->getChange()) {
            SDL_DestroyTexture(T_alerte);
            T_alerte = StringToTexture(alerte->getAlerte());
            SDL_QueryTexture(T_alerte, NULL, NULL, &rAlerte.w, &rAlerte.h);
            rAlerte.x = (1920-rAlerte.w )/2;
            rAlerte.y = (1080-rAlerte.h )/2;
        }
        SDL_RenderCopy(rendu,T_alerte,NULL,&rAlerte);
    }
}
SDL_Texture* Graphisme::StringToTexture(string str){
    TTF_Font *pAlerte = TTF_OpenFont("data/img/MYTYPE.ttf", 50);
    SDL_Color cAlerte = {255,20,20};
    return SDL_CreateTextureFromSurface(rendu,TTF_RenderText_Solid(pAlerte,str.c_str(), cAlerte));
}
void Graphisme::Afficher_inventaire(Inventaire& inv){
    SDL_Rect r={0,200,0,0};
    for(int i =0; i<inv.getNombre(); i++) {
        if(inv.getEquipement(i)->getTexture()<0) {
            V_inv.push_back(sautligne(inv.getString(i),true));
            inv.getEquipement(i)->setTexture(V_inv.size()-1);
        }
        SDL_QueryTexture(V_inv[inv.getEquipement(i)->getTexture()],NULL,NULL,&r.w,&r.h);
        r.w = r.w*0.75; r.h = r.h*0.75;
        SDL_RenderCopy(rendu,V_inv[inv.getEquipement(i)->getTexture()],NULL,&r);
        r.y += r.h;

    }
}
void Graphisme::Afficher_choix(){
    SDL_Rect r; r.x = 0; r.y = 0; r.h = 1080; r.w = 1920;
    SDL_RenderCopy(rendu,T_Decor[CHOIX],NULL,&r);
}
void Graphisme::Afficher_cursor(int y, int x){
    rCursor.x = x; rCursor.y = y;
    SDL_RenderCopy(rendu,T_Decor[CURSOR],NULL,&rCursor);
}
SDL_Rect& Graphisme::getRFond(){
    return rFond;
}
void Graphisme::clear(){
    V_perso.clear();
    caract.clear();

}

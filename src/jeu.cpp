#include "jeu.h"

Jeu::Jeu(SDL_Renderer* _rendu) : graphisme(_rendu){
    rendu = _rendu;
    piece_selection = nullptr;
    menu_construction = false;
    pieces = new Piece* [9*17];
    for (int j = 0; j<9; ++j) {
        for(int i = 0; i<17; ++i) {
            tab[j*17+i].x =288+96*(i); tab[j*17+i].y =2700-270*(1+j) - 15;
            pieces[j*17+i] = nullptr;
        }
    }
    alerte = new Alerte();
    extPerso = nullptr;
    time = 0; time2 = 0;
    stat.setPtr(pieces,alerte);
    graphisme.setPtr(pieces,alerte);
    mouv.setPtr(pieces,alerte);
    inv.setPtr(alerte);
    p_sel = nullptr; rCoo = {0,0,0,0};
    rp = {0,0,0,0}; ext = true; extPerso = 0;
    binv = false;
    equip = -1;
}

int Jeu::Boucle(int& save){
    cout<<"save : "<< save<<endl;
    stat.setStat(save,tab);
    batiment.setPtr(pieces,alerte);
    graphisme.setTexturePersonnage();
    fps = 0;
    frame = 0;
    equip = -1;
    time = SDL_GetTicks();
    int ret = -1;
    graphisme.Affichage_jeu(batiment,tab);
    SDL_RenderPresent(rendu);
    SDL_Event events;
    bool quitter = false;
    // tant que ce n'est pas la fin ...
    while (!quitter) {
        // tant qu'il y a des evenements à traiter (cette boucle n'est pas bloquante)
        while (SDL_PollEvent(&events)) {
            if (events.type == SDL_QUIT) quitter = true;
            if (events.type == SDL_KEYDOWN) {
                switch (events.key.keysym.sym) {
                    case SDLK_ESCAPE: quitter = true; ret = 0; break;
                    case SDLK_SPACE:  break;
                    case SDLK_s: stat.save(save); break;
                    case SDLK_k: audio.skip(); break;
                }
            }
            if (events.type == SDL_KEYUP) {
                switch (events.key.keysym.sym) {
                    case SDLK_SPACE: break;
                }
            }
            if(events.type == SDL_MOUSEWHEEL) {
                if(events.wheel.y > 0 && graphisme.getRFond().y < 0) {
                    graphisme.getRFond().y += 50;
                    if(graphisme.getRFond().y> 0) graphisme.getRFond().y = 0;
                }
                else if(events.wheel.y < 0 && graphisme.getRFond().y > 1080-2700) {
                    graphisme.getRFond().y -= 50;
                    if(graphisme.getRFond().y < 1080-2700) graphisme.getRFond().y = 1080-2700;
                }
            }
            if (events.type == SDL_MOUSEBUTTONDOWN) {
                GetClique();
                cout<<"clique en :"<<rclique.y<<" "<<rclique.x<<endl;
                SetClique();
            }
        }
        SDL_GetMouseState(&rC.x,&rC.y);
        update();
        Affichage();
        SDL_Delay(15);
        frame++;
    }
    clear();
    return ret;
}

void Jeu::GetClique(){
    int x,y;
    int i = 0;
    int j = 0;
    SDL_GetMouseState(&x,&y);
    rCoo.x = x; rCoo.y = y-graphisme.getRFond().y;
    while (x > tab[i*17+j].x && j < 17) {
        j++;
    }
    if (j<17) rclique.x = j-1;
    else rclique.x = 16;

    while (y - graphisme.getRFond().y  < tab[i*17].y && i < 9 ) {
        i++;
    }
    if (i<9) rclique.y = i;
    else rclique.y = -1;
    if(rclique.x==-1) {
        for (int k=1; k<12; ++k) {
            if (y<= 90*k) {rclique.y = -13+k; break;}
        }
    }
    for (long unsigned int u = 0; u<vperso.size(); u++) {
        if (vperso[u]->estSelect(rCoo.y,rCoo.x)
            && stat.getNbPerso() < stat.getNbPersoMax()) {
            p_sel = vperso[u];
            if (vperso.size()>1) extPerso = vperso[1-u];
            else extPerso = nullptr;
            rclique.x = -2; rclique.y = -2;
        }
    }
}
void Jeu::SetClique(){
    if(mouv.getFin()) {
        SDL_Rect f; f.y = 370*1.5; f.x = 315*1.5; f.h = 60*1.5; f.w = 250*1.5;
        SDL_Rect e; e.y = 370*1.5; e.x = 745*1.5; e.h = 60*1.5; e.w = 250*1.5;
        int x = rCoo.x; int y = rCoo.y + graphisme.getRFond().y;
        if(x>f.x && x<f.x+f.w&& y>f.y&&y<f.y+f.h) {
            stat.setFeraille(stat.getFerraille()+mouv.getFer());
            mouv.setFin(false);
        }else if(x>e.x && x<e.x+e.w&& y>e.y&&y<e.y+e.h) {
            if (inv.getNombre()<int(stat.getTailleInv())) {
                inv.addEquipement();
                mouv.setFin(false);
            }
            else alerte->addAlerte("Inventaire plein !",19);
        }
        return;
    }
    if(piece_selection == nullptr && rclique.x == -1 && !menu_construction) {
        int y = rCoo.y + graphisme.getRFond().y;
        if(binv) {
            if (rclique.y ==-11 || rclique.y ==-12) {
                binv = false;
                if(p_sel!=nullptr) {
                    if (inv.getNombre()<int(stat.getTailleInv())-1) {
                        inv.recupererEquipement(p_sel->enleverArme());
                        inv.recupererEquipement(p_sel->enleverArmure());
                        binv = true;
                    }else alerte->addAlerte("Inventaire plein !",19);
                }
            }
            for (int u = 0; u<inv.getNombre(); u++) {
                if (y>200+150*u && y<200+150*(u+1)) equip = u;
            }
            cout<<"équipement select : "<<equip<<"\n";
        }else{
            if (rclique.y ==-11 || rclique.y ==-12) {
                binv = true;
                if(p_sel!=nullptr) {
                    if (inv.getNombre()<int(stat.getTailleInv())-1) {
                        inv.recupererEquipement(p_sel->enleverArme());
                        inv.recupererEquipement(p_sel->enleverArmure());
                        binv = true;
                    }else alerte->addAlerte("Inventaire plein !",19);
                }
            }
        }
    }
    else if(equip >= 0) {
        cout<<"rentre dans if equip\n";
        if (rclique.x > -1 && rclique.y >-1 && pieces[rclique.y*17+rclique.x]!= nullptr) {
            cout<<"equip piece valide\n";
            Personnage *tmp = pieces[rclique.y*17+rclique.x]->persoPresent(rCoo.y,rCoo.x);
            if (tmp != nullptr) {
                cout<<"équipement ajouté\n";
                if(tmp->ajouterEquipement(inv.getEquipement(equip)))
                    inv.supEquipement(equip);
            }
        }
        equip = -1;
    }
    if(piece_selection !=nullptr && piece_selection->getType()==MILICE ) {
        SDL_Rect b = tab[piece_selection->getY()*17+piece_selection->getX()];
        if(rCoo.x > b.x && rCoo.x < b.x + int(piece_selection->getDimX())*96 &&
           rCoo.y + 50 > b.y && rCoo.y < b.y) {
            for (unsigned int i = 0; i < piece_selection->getNbPerso(); i++) {
                if (piece_selection->getPerso(i)->getDeplacement() == false) {
                    mouv.addExplo(piece_selection->getPerso(i),piece_selection);
                    alerte->addAlerte(to_string(piece_selection->getNbPerso())+" personne.s envoye.s en exploration !",2);
                }
            }
        }
    }
    if(p_sel !=nullptr &&rclique.y > -1 && rclique.x > -1) {
        if(pieces[rclique.y*17+rclique.x]!=nullptr
           && pieces[rclique.y*17+rclique.x]->getNbPerso()<pieces[rclique.y*17+rclique.x]->getNiveau()
           && stat.getNbPerso() <= stat.getNbPersoMax()) {
            Piece *p = pieces[rclique.y*17+rclique.x];
            if(ext && stat.getNbPerso() < stat.getNbPersoMax()) {
                std::cout<<"perso exterieur\n";
                mouv.addPerso(p_sel,p,ext,0,0,rclique.y,rclique.x,tab[rclique.y*17+rclique.x].y,tab[rclique.y*17+p->getX()].x);
                vperso.clear();
                if (extPerso != nullptr) {
                    vperso.push_back(extPerso);
                    vperso.back()->setCo(190-75*(vperso.size()-1));
                }
            }
            else if (!ext) {
                std::cout<<"perso interieur\n";
                mouv.addPerso(p_sel,p,ext,rp.y,rp.x,rclique.y,rclique.x,tab[rclique.y*17+rclique.x].y,tab[rclique.y*17+p->getX()].x);
                ext = true;
            }
            p_sel = nullptr;
        }else{
            if(pieces[rclique.y*17+rclique.x]!=nullptr) {
                alerte->addAlerte("Nombre de personnes max deja atteinte !",1);
            }
            if(!ext) ext = true;
            p_sel = nullptr;
        }
        return;
    }
    if (menu_construction) {
        batiment.nouvelle_piece(rconstruire.y,rconstruire.x,rclique.y,audio,stat.getObjFerraille());
    }
    else if(piece_selection!=nullptr) {
        if (piece_selection->getSelection()==1) {
            if (rclique.y <= -10) piece_selection->setSelection(2);
            else if (rclique.y <=-7) piece_selection->setSelection(3);
            else if (rclique.y <= -4) {
                piece_selection->setSelection(0);
                audio.stop_sound_piece(piece_selection->getType());
                piece_selection =nullptr;
            }
        }
        else if (piece_selection->getSelection()==2) {
            if (rclique.y >= -6 && rclique.y <= -4) piece_selection->setSelection(1);
        }
        else if (piece_selection->getSelection()==3) {
            if (rclique.y >= -6 && rclique.y <= -4) piece_selection->setSelection(1);
            else if (rclique.y >= -9 && rclique.y <= -7) {
                batiment.Agrandir(piece_selection,audio,stat.getObjFerraille());
                piece_selection->setSelection(0);
                audio.stop_sound_piece(piece_selection->getType());
                piece_selection =nullptr;
            }
            else if (rclique.y <= -10) {
                batiment.destruction(piece_selection,audio);
                if (piece_selection!=nullptr) {
                    piece_selection->setSelection(0);
                    audio.stop_sound_piece(piece_selection->getType());
                }
                piece_selection = nullptr;
            }
        }
    }
    if( rclique.x>-1 && rclique.y>-1 && pieces[17*rclique.y+rclique.x]!=nullptr) {
        menu_construction = false;
        if(pieces[17*rclique.y+rclique.x]->getSelection()==0) {
            if (piece_selection!=nullptr) {
                piece_selection->setSelection(0);
                audio.stop_sound_piece(piece_selection->getType());
            }
            p_sel = pieces[17*rclique.y+rclique.x]->persoPresent(rCoo.y,rCoo.x);
            rp.x = rclique.x; rp.y = rclique.y;
            ext = false;
            if(p_sel == nullptr) {
                std::cout<<"perso selectionné\n";
                pieces[17*rclique.y+rclique.x]->setSelection(1);
                piece_selection = pieces[17*rclique.y+rclique.x];
                batiment.estAgrandissable(piece_selection,stat.getFerraille());
                batiment.estDestructible(piece_selection);
                audio.play_sound_piece(piece_selection->getType());
                ext = true;
            }
        }
        else{
            piece_selection->setSelection(0);
            audio.stop_sound_piece(piece_selection->getType());
            piece_selection = nullptr;
        }
    }
    else{
        menu_construction = batiment.estConstrcutible(rclique.y,rclique.x);
        if(menu_construction) {
            if (piece_selection!=nullptr) {
                piece_selection->setSelection(0);
                audio.stop_sound_piece(piece_selection->getType());
                piece_selection = nullptr;
            }
            batiment.setAchetable(rclique.y,rclique.x,stat.getFerraille());
            rconstruire.x = rclique.x; rconstruire.y = rclique.y;
        }
    }
}
void Jeu::Affichage(){
    graphisme.Affichage_jeu(batiment,tab);
    graphisme.Afficher_perso(vperso,mouv);
    if (mouv.getPerso().size()>0) graphisme.Afficher_contour(batiment,tab);
    graphisme.Afficher_selection(piece_selection,tab);
    if(binv) graphisme.Afficher_inventaire(inv);
    graphisme.Afficher_stat(stat,fps,binv);
    if (menu_construction) graphisme.Afficher_menu_construction(batiment);
    else if (piece_selection!=nullptr) graphisme.Afficher_menu_piece(piece_selection,batiment);
    if (p_sel != nullptr) graphisme.Afficher_caracteristique(p_sel);
    graphisme.Afficher_alerte();
    if (mouv.getFin()) graphisme.Afficher_choix();
    graphisme.Afficher_cursor(rC.y,rC.x);
    SDL_RenderPresent(rendu);
}

void Jeu::update(){
    time = SDL_GetTicks();
    if (time-stat.getLastUpdate()>1000) {
        stat.update(mouv.getNb(),int(inv.getNombre()));
        stat.setLastUpdate(SDL_GetTicks());
        fps = frame;
        frame = 0;
        audio.update();
        alerte->update();
    }
    int ferraille = 0;
    mouv.update(ferraille);
    stat.setFeraille(stat.getFerraille()+ferraille);
    if (time - time2 < 10000 ) return;
    time2 = time;
    if(vperso.size()<2) {
        vperso.push_back(new Personnage());
        vperso.back()->setCo(190-75*(vperso.size()-1));
    }
}
void Jeu::clear(){
    Piece *p;
    int k = 0;
    for (int j = 0; j<9; ++j) {
        for(int i = 0; i<17; ++i) {
            p = pieces[j*17+i];
            if (p!=nullptr) {
                k = p->getDimX()-1;
                delete p;
                for(int u = 0; u <=k; u++) {
                    pieces[j*17+i+u] = nullptr;
                }
                i += k;
            }
        }
    }
    batiment.clear();
    graphisme.clear();
    mouv.clear();
    vperso.clear();
}

Audio& Jeu::getAudio(){
    return audio;
}

Jeu::~Jeu(){

}

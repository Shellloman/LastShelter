#include "menu.h"

Menu::Menu(SDL_Renderer *rendu_) : commencer(1,700,600,70,500),
    charger(2,700,750,70,500), option(3,700,900,70,500) {
    rendu = rendu_;
    texture = x = y = 0;
    select = nullptr;
    rCursor.x = 0; rCursor.y = 0; rCursor.w = 36; rCursor.h = 48;
    T_Menu = new SDL_Texture*[7];
    T_Menu[0] = Load("data/img/fond.png");
    T_Menu[1] = Load("data/img/b_commencer.png");
    T_Menu[2] = Load("data/img/b_charger.png");
    T_Menu[3] = Load("data/img/b_option.png");
    T_Menu[4] = Load("data/img/selection_piece3.png");
    T_Menu[5] = Load("data/img/titre.png");
    T_Menu[6] = Load("data/img/cursor.png");
}

int Menu::Boucle(int& save,Audio& audio){
    save = 1;
    int ret = -1;
    SDL_RenderPresent(rendu);
    SDL_Event events;
    bool quitter = false;
    t0 = t1 = 0;
    // tant que ce n'est pas la fin ...
    while (!quitter) {
        // tant qu'il y a des evenements à traiter (cette boucle n'est pas bloquante)
        while (SDL_PollEvent(&events)) {
            if (events.type == SDL_QUIT) quitter = true;
            if (events.type == SDL_KEYDOWN) {
                switch (events.key.keysym.sym) {
                    case SDLK_ESCAPE: quitter = true; break;
                    case SDLK_SPACE: ret = -1; quitter = true; break;
                    case SDLK_a: save = 1; break;
                    case SDLK_z: save = 2; break;
                    case SDLK_e: save = 3; break;
                    case SDLK_r: save = 4; break;
                }
            }
            if (events.type == SDL_MOUSEMOTION) {
                SDL_GetMouseState(&x,&y);
                if(commencer.is_highlight(x,y)) select = &commencer;
                else if(charger.is_highlight(x,y)) select = &charger;
                else if(option.is_highlight(x,y)) select = &option;
                else select = nullptr;

            }
            if (events.type == SDL_MOUSEBUTTONDOWN) {
                if (events.button.button == SDL_BUTTON_LEFT) {
                    if(commencer.is_highlight(x,y)) {quitter = true; ret = 1; break;}
                    else if(charger.is_highlight(x,y)) Charger();
                    else if(option.is_highlight(x,y)) Option();
                }
            }
        }
        t1 = SDL_GetTicks();
        if(t1-t0 > 1000) {
            audio.update();
            t0 = t1;
        }
        Affichage();
        SDL_RenderPresent(rendu);
        SDL_Delay(20);
    }
    return ret;
}

void Menu::Affichage(){
    SDL_Rect rf;
    rf.x = -(1920-1920)/2; rf.y= 1080-2700; rf.h= 2700; rf.w = 1920;
    SDL_RenderClear(rendu);
    SDL_RenderCopy(rendu,T_Menu[0],NULL,&rf);
    rf.x = 0; rf.y= 50; rf.h=450; rf.w = 1920;
    SDL_RenderCopy(rendu,T_Menu[5],NULL,&rf);
    SDL_RenderCopy(rendu,T_Menu[commencer.Texture()],NULL,&(commencer.Co()));
    SDL_RenderCopy(rendu,T_Menu[charger.Texture()],NULL,&(charger.Co()));
    SDL_RenderCopy(rendu,T_Menu[option.Texture()],NULL,&(option.Co()));
    if(select != nullptr) SDL_RenderCopy(rendu,T_Menu[4],NULL,&(select->Co()));
    rCursor.x = x; rCursor.y = y;
    SDL_RenderCopy(rendu,T_Menu[6],NULL,&rCursor);
}

SDL_Texture* Menu::Load(const char* chemin){
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

void Menu::Charger(){
    std::cout<<"charger"<<endl;
}

void Menu::Option(){
    std::cout<<"option"<<endl;
}

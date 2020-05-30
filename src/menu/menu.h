#ifndef MENU_H
#define MENU_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "bouton.h"
#include "../outils/audio.h"

using namespace std;

class Menu {
private:
    SDL_Renderer *rendu;
    int texture,x,y;
    SDL_Texture **T_Menu;
    Bouton commencer, charger, option, *select;
    unsigned int t0,t1;
    SDL_Rect rCursor;

public:
    Menu(SDL_Renderer * rendu_);
    int Boucle(int &save,Audio &audio);
    void Affichage();
    SDL_Texture * Load(const char* chemin);
    void Charger();
    void Option();
};

#endif

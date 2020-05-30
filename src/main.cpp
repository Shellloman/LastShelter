#include "jeu.h"
#include "menu/menu.h"

const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

int main(int argc, const char * argv[]){
    // initialisation de la SDL
    if( SDL_Init( SDL_INIT_VIDEO |SDL_INIT_AUDIO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    TTF_Init();

    //création de la fenetre
    SDL_Window* fenetre = SDL_CreateWindow( "UPTOWER", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN|SDL_WINDOW_ALLOW_HIGHDPI|SDL_WINDOW_FULLSCREEN);
    SDL_Renderer* rendu = SDL_CreateRenderer(fenetre,-1,SDL_RENDERER_ACCELERATED);
    SDL_ShowCursor(SDL_DISABLE);
    // initialisation des classes principales
    Jeu jeu(rendu);
    Menu menu(rendu);

    // si aucun argument n'est donné on saute le menu en développement
    bool Continue = true;
    int ret = 0;
    int save = 1;
    // boucle entre le jeu et le menu sauf si on demande de sortir du programme
    while(Continue) {
        switch(ret) {
            case 0: ret = menu.Boucle(save,jeu.getAudio()); break;
            case 1: ret = jeu.Boucle(save); break;
            case -1: Continue = false; std::cout <<"Sortie du programme"<<std::endl; break;
            default: ret = -1; std::cout<<"mauvaise valeur de retour\n"; break;
        }
    }

    // on libère la mémoire de la SDL avant de quitter
    IMG_Quit();
    SDL_Quit();
    return 0;
}

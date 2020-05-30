#ifndef BUTTON_H
#define BUTTON_H

#include <SDL2/SDL.h>

class Bouton{
public:
    Bouton(unsigned int tex, int _x, int _y, int _h, int _w);
    SDL_Rect &Co();
    unsigned int Texture()const;
    void setCo(int _x, int _y, int _h = 0, int _w =0);
    void Select(bool sel);
    bool is_highlight(int x,int y)const;
private :
    bool select;
    unsigned int texture;
    int nb_clip;
    SDL_Rect co;

};
#endif

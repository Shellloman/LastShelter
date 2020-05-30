#include "bouton.h"

Bouton::Bouton(unsigned int tex, int _x, int _y, int _h, int _w){
    select = false;
    texture = tex;
    co = {_x,_y,_w,_h};
}
SDL_Rect &Bouton::Co(){
    return co;
}
void Bouton::setCo(int _x, int _y, int _h , int _w){
    co.x = _x; co.y = _y;
    if (_h != 0) co.h = _h;
    if (_w != 0) co.w = _w;
}
void Bouton::Select(bool sel){
    select = sel;
}
bool Bouton::is_highlight(int x,int y)const{
    return ( x >= co.x && x <= co.x + co.w && y >= co.y && y <= co.y + co.h );
}
unsigned int Bouton::Texture()const{
    return texture;
}

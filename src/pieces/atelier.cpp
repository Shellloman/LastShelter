#include "atelier.h"

Atelier::Atelier(int y_,int x_,unsigned int niveau_,bool asc_ ) : Piece(y_,x_,niveau_,asc_){
    switch (niveau_) {
        case 1: Texture = ATELIER1S; break;
        case 2: Texture = ATELIER2S; break;
        case 3: Texture = ATELIER3S; break;
        default: break;
    }
    type = ATELIER;
}

Atelier::~Atelier()
{
}

void Atelier::setTexture(unsigned int tex){
    switch (tex) {
        case 1: Texture = ATELIER1S; break;
        case 4: Texture = ATELIER1M; break;
        case 7: Texture = ATELIER1L; break;
        case 2: Texture = ATELIER2S; break;
        case 5: Texture = ATELIER2M; break;
        case 8: Texture = ATELIER2L; break;
        case 3: Texture = ATELIER3S; break;
        case 6: Texture = ATELIER3M; break;
        case 9: Texture = ATELIER3L; break;
        default: break;
    }
}

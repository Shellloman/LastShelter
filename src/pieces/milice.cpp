#include "milice.h"

Milice::Milice(int y_,int x_,unsigned int niveau_,bool asc_ ) : Piece(y_,x_,niveau_,asc_){
    switch (niveau_) {
        case 1: Texture = MILICE1; break;
        case 2: Texture = MILICE2; break;
        case 3: Texture = MILICE3; break;
        default: break;
    }
    type = MILICE;
    prix[0] = 200; prix[1] = 300; prix[2] = 500;
}

Milice::~Milice()
{
}


void Milice::setTexture(unsigned int tex){
    switch (tex) {
        case 1: Texture = MILICE1; break;
        case 2: Texture = MILICE2; break;
        case 3: Texture = MILICE3; break;
        default: break;
    }
}

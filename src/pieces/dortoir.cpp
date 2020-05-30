#include "dortoir.h"

Dortoir::Dortoir(int y_,int x_,unsigned int niveau_,bool asc_ ) : Piece(y_,x_,niveau_,asc_){
    switch (niveau_) {
        case 1: Texture = DORTOIR1; break;
        case 2: Texture = DORTOIR2; break;
        case 3: Texture = DORTOIR3; break;
        default: break;
    }
    type = DORTOIR;
}

Dortoir::~Dortoir()
{
}

unsigned int Dortoir::getProduction() const {
    return niveau*3;
}

void Dortoir::setTexture(unsigned int tex){
    switch (tex) {
        case 1: Texture = DORTOIR1; break;
        case 2: Texture = DORTOIR2; break;
        case 3: Texture = DORTOIR3; break;
        default: break;
    }
}

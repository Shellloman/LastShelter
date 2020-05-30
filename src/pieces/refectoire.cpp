#include "refectoire.h"

Refectoire::Refectoire(int y_,int x_,unsigned int niveau_,bool asc_ ) : Piece(y_,x_,niveau_,asc_){
    switch (niveau_) {
        case 1: Texture = SELF1; break;
        case 2: Texture = SELF2; break;
        case 3: Texture = SELF3; break;
        default: break;
    }
    type = SELF;
}

Refectoire::~Refectoire()
{
}

unsigned int Refectoire::getProduction() const {
    unsigned int prod = 0;
    for(unsigned int i=0; i<NbPerso; i++)
    {
        if(tab[i]->getSociabilite()>5) {
            prod += 2;
        }
        else{
            prod += 1;
        }
        if(tab[i]->getAgilite()>5) {
            prod += 2;
        }
        else{
            prod += 1;
        }
    }
    return prod;
}

void Refectoire::setTexture(unsigned int tex){
    switch (tex) {
        case 1: Texture = SELF1; break;
        case 2: Texture = SELF2; break;
        case 3: Texture = SELF3; break;
        default: break;
    }
}

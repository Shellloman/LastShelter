#include "eaupotable.h"

Eaupotable::Eaupotable(int y_,int x_,unsigned int niveau_,bool asc_ ) : Piece(y_,x_,niveau_,asc_){
    switch (niveau_) {
        case 1: Texture = EAU1; break;
        case 2: Texture = EAU2; break;
        case 3: Texture = EAU3; break;
        default: break;
    }
    type = EAU;
}

Eaupotable::~Eaupotable()
{
}

unsigned int Eaupotable::getProduction() const {
    unsigned int prod = 0;
    for(unsigned int i=0; i<NbPerso; i++)
    {
        if(tab[i]->getConcentration()>5)
        {
            prod += 4;
        }
        else
        {
            prod  += 3;
        }
    }
    return prod;
}

void Eaupotable::setTexture(unsigned int tex){
    switch (tex) {
        case 1: Texture = EAU1; break;
        case 2: Texture = EAU2; break;
        case 3: Texture = EAU3; break;
        default: break;
    }
}

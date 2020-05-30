#include "salon.h"

Salon::Salon(int y_,int x_,unsigned int niveau_,bool asc_ ) : Piece(y_,x_,niveau_,asc_){
    switch (niveau_) {
        case 1: Texture = SALON1; break;
        case 2: Texture = SALON2; break;
        case 3: Texture = SALON3; break;
        default: break;
    }
    type = SALON;
}

Salon::~Salon()
{
}

unsigned int Salon::getProduction() const {
    unsigned int prod = 0;
    for(unsigned int i=0; i<NbPerso; i++)
    {
        if(tab[i]->getCharme()>5) {
            prod +=2;
        }
        else{
            prod += 1;
        }
        if(tab[i]->getSociabilite()>5) {
            prod  += 2;
        }
        else{
            prod += 1;
        }
    }
    return prod;
}

void Salon::setTexture(unsigned int tex){
    switch (tex) {
        case 1: Texture = SALON1; break;
        case 2: Texture = SALON2; break;
        case 3: Texture = SALON3; break;
        default: break;
    }
}

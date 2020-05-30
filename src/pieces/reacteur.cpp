#include "reacteur.h"

Reacteur::Reacteur(int y_,int x_,unsigned int niveau_,bool asc_ ) : Piece(y_,x_,niveau_,asc_){
    switch (niveau_) {
        case 1: Texture = REACTEUR1; break;
        case 2: Texture = REACTEUR2; break;
        case 3: Texture = REACTEUR3; break;
        default: break;
    }
    type = REACTEUR;
}

Reacteur::~Reacteur()
{
}

unsigned int Reacteur::getProduction() const {
    unsigned int prod = 0;
    for(unsigned int i=0; i<NbPerso; i++)
    {
        if(tab[i]->getIntelligence()>5)
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

void Reacteur::setTexture(unsigned int tex){
    switch (tex) {
        case 1: Texture = REACTEUR1; break;
        case 2: Texture = REACTEUR2; break;
        case 3: Texture = REACTEUR3; break;
        default: break;
    }
}

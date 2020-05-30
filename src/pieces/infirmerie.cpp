#include "infirmerie.h"

Infirmerie::Infirmerie(int y_,int x_,unsigned int niveau_,bool asc_ ) : Piece(y_,x_,niveau_,asc_){
    switch (niveau_) {
        case 1: Texture = INFIRM1; break;
        case 2: Texture = INFIRM2; break;
        case 3: Texture = INFIRM3; break;
        default: break;
    }
    type = INFIRM;
}

Infirmerie::~Infirmerie(){
}

void Infirmerie::Soigne(){
    Personnage* Bart;
    int a;
    for(unsigned int i=0; i<NbPerso; i++){
        Bart = getPerso(i);
        if (false == Bart->getSante())
        {
            a = rand() % 3;
            if (a==1){
                Bart->setSante(true);
            }
        }
    }
}

void Infirmerie::setTexture(unsigned int tex){
    switch (tex) {
        case 1: Texture = INFIRM1; break;
        case 2: Texture = INFIRM2; break;
        case 3: Texture = INFIRM3; break;
        default: break;
    }
}
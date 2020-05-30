#include "events.h"

events::events(){
    piece = nullptr;
    XP = 100;
    blessure = false;
}

events::events(Piece* piece_,int XP_,bool blessure_){
    piece = piece_;
    XP = XP_;
    blessure = blessure_;
}

bool events::isBless(){
    return blessure;
}

int events::GetXP(){
    return XP;
}

void events::SetXP(int XP_){
    XP = XP_;
}

void events::rendreMaladeRand(){
    int nbr = piece->getNbPerso();
    Personnage* Bart;
    for (int i=0; i<nbr; i++){
        Bart = piece->getPerso(i);
        Bart->setSante(false);
    } 
}

void events::panne(){
    int a = rand() % 20;
    if(a==1){
        //piece->setAllumer(false);
    }
}

void events::reparer(){
    int a = rand() % 5;
    if(a==1){
        //piece->setAllumer(true);
    }
}

void events::invasionNuisibleRand(){
    int a = rand() % 20;
    if(a==1){
       // piece->setAllumer(false);
        rendreMaladeRand();
    }
}

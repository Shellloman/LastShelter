#ifndef EVENTS_H
#define EVENTS_H

#include <iostream>
#include <cstdlib>
#include <time.h>
#include "pieces/piece.h"


using namespace std;

/** \class events [events.h]
 *  \brief events regroupe tout les differents evenements aléatoire du jeu*/
class events {

private:

    Piece* piece;
    bool blessure;
    int XP;

public:
    events();
    events(Piece* piece_,int XP_ = 100,bool blessure_ = false);
    bool isBless();
    int GetXP();
    void SetXP(int XP_);
    void rendreMaladeRand();
    void panne();
    void reparer();
    void invasionNuisibleRand();
};

#endif
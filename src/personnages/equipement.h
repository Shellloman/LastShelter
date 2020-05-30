#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H

#include <cstring>
#include <experimental/random>
#include "../constante.h"

/** \class Equipement [equipement.h]
 *  \brief Mouvement gère le déplacement des personnages.
 *
 * cette classe utilise plusieurs vectors pour récupèrer temporairement les
 * pointeurs de personnages et gérer leur déplacement */
class Equipement {

private:
    std::string nom;
    int degatMin,degatMax,armure;
    int type;
    int texture;

public:
    Equipement(std::string n,int dmin,int dmax,int a, int t);

    std::string getNom() const;
    std::string getString() const;

    void setTexture(int value);

    int getDegat() const;
    int getArmure() const;
    int getType() const;
    int getTexture() const;
};

#endif

#ifndef INVENTAIRE_H
#define INVENTAIRE_H

#include "../outils/alerte.h"
#include "equipement.h"
#include <vector>

/** \class Equipement [equipement.h]
 *  \brief Mouvement gère le déplacement des personnages.
 *
 * cette classe utilise plusieurs vectors pour récupèrer temporairement les
 * pointeurs de personnages et gérer leur déplacement */
class Inventaire {

private:
    vector<Equipement*> equip;
    std::string nomsArme[5];
    std::string nomsArmure[3];
    Alerte * alerte;

public:
    Inventaire();

    void addEquipement();
    void supEquipement(int i);
    void recupererEquipement(Equipement * e);
    void setPtr(Alerte * alerte_);

    std::string getString(int i);
    Equipement* getEquipement(int i);
    int getNombre();
};

#endif

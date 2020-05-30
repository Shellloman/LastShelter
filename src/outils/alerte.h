#ifndef ALERTE_H
#define ALERTE_H

#include <stdio.h>
#include <iostream>
#include <list>
#include "../constante.h"

using namespace std;
/** \class Alerte [alerte.h]
 *  \brief Alerte affiche les messages d'alerte
 *
 * cette classe affiche différent messages que le jeu va donner pour le joueur, exemple :
 * "Achat de 'Réacteur' pour 100 férrailles" ou encore "Trop peu d'argent pour acheter cette pièce" */

class Alerte {
private:
    list<string> messages;
    bool changement;
    int duree,nombre,last_id;

public:
    Alerte();
    void addAlerte(string msg,int id);
    void update();

    string getAlerte();

    bool getChange() const;
    void setChange(bool value);

    int getNombre();

};

#endif

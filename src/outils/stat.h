#ifndef STAT_H
#define STAT_H

#include <fstream>
#include <sstream>
#include "../pieces/dortoir.h"
#include "../pieces/salon.h"
#include "../pieces/milice.h"
#include "../pieces/infirmerie.h"
#include "../pieces/eaupotable.h"
#include "../pieces/reacteur.h"
#include "../pieces/refectoire.h"
#include "../pieces/atelier.h"
#include "alerte.h"
#include "../constante.h"
#include <SDL2/SDL_rect.h>


/** \class Stat [stat.h]
 *  \brief gère les statistiques de la partie
 *
 * cette classe gère les différentes statistiques du jeu, eau ,energie , ect ainsi
 * que le nombre maximum de joueurs et les sauvegardes. */
class Stat {
private:
    Piece **pieces;
    Alerte* alerte;

    int ferraille;
    int eau;
    int energie;
    int nourriture;
    int joie;
    int nbPerso;
    int nbPersoMax;
    int lastUpdate;
    int taille_inv;
    bool beau,benergie,bnourriture,bjoie;

public:
    Stat();

    /** @brief fonction appelé dans la boucle principal toutes les secondes. Elle baisse ou augmentes
     * Les statistiques en fonctions du nombre de personnages et de la production de chaque piece
     * @param perso_mouv : nombre de personnages en mouvement */
    void update(int perso_mouv,int t_inv);

    /** @brief Mutatuer : récupère le pointeur du tableau de pieces créé dans jeu
     * @param pieces_ : pointeur du tableau de pieces */
    void setPtr(Piece **pieces_,Alerte* alerte_);

    /** @brief récupère la sauvegarde à partir d'un fichier
     * @param save : numéro de la sauvegarde à utiliser*/
    void setStat(int save,SDL_Rect tab[9*17]);

    /** @brief sauvegarde la partie actuelle dans le fichier numéro 'save' */
    void save(int save);

    int getFerraille() const;
    int &getObjFerraille();
    int getEau() const;
    int getEnergie() const;
    int getNourriture() const;
    int getJoie() const;
    int getNbPerso() const;
    int getNbPersoMax() const;
    int getLastUpdate() const;
    int getTailleInv() const;

    bool getBeau() const;
    bool getBenergie() const;
    bool getBnourriture() const;
    bool getBjoie() const;

    void setFeraille(int value);
    void setLastUpdate(int value);
    void setNbPerso(int value);
    void setNbPersoMax(int value);

    void afficher() const;
};

#endif

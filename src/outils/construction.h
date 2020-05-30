#ifndef CONSTRUCTION_H
#define CONSTRUCTION_H

#include <SDL2/SDL_mixer.h>
#include "../pieces/dortoir.h"
#include "../pieces/salon.h"
#include "../pieces/milice.h"
#include "../pieces/infirmerie.h"
#include "../pieces/eaupotable.h"
#include "../pieces/reacteur.h"
#include "../pieces/refectoire.h"
#include "../pieces/atelier.h"
#include "alerte.h"

#include "audio.h"
#include "../constante.h"
#include "Liste.h"

/** \class Construction [construction.h]
 *  \brief gère les différentes pieces
 *
 * cette classe gère la construction , desctruction et aggrandissement
 * de toute les pieces */
class Construction {

private:
//Liste chantier;
    Piece **pieces;
    Liste chantier;
    Alerte *alerte;
    bool pieces_achetable[9];

public:
    Construction();

    /** @brief Mutatuer : récupère le pointeur du tableau de pieces créé dans jeu
     * @param pieces_ : pointeur du tableau de pieces */
    void setPtr(Piece **pieces_,Alerte* alerte_);

    /** @brief créé une nouvelle piece sur le tas.
     * @param x et y : coordonnées de la piece
     * @param audio : classe Audio pour jouer des songs
     * @param ferraille : données membres de la classe stats.*/
    void nouvelle_piece(int y, int x,int k,Audio &audio, int& ferraille);

    /** @brief getter : retourne la premiere cellule de la liste des positions construisible*/
    Cellule* getPtrPrem() const;

    /** @brief retourne true si une piece est construisible au coordonnées x, y*/
    bool estConstrcutible(int y,int x) const;

    /** @brief retourne true si là ieme piece est construisible.
    * @param i : utilise le type de la piece, voir constante.h*/
    bool estAchetable(int i) const;

    /** @brief retourne true si la piece est construisible*/
    bool estAgrandissable(Piece *p, int ferraille) const;

    /** @brief retourne true si la piece est destructible*/
    bool estDestructible(Piece *p) const;

    /** @brief détruit la piece
     * @param p : pointeur de la piece à détruire*/
    void destruction(Piece *&p,Audio &audio);

    /** @brief aggrandis la piece
     * @param p : pointeur vers la piece à agrandir*/
    void Agrandir(Piece *&p,Audio &audio, int& ferraille);

    /** @brief créée une piece sur le tas en fonctions de l'endroit cliqué dans le menu */
    void choix_piece(int y,int x,int k);

    /** @brief retourne 1 si la piece va de gauche à droite, -1 si de droite à gauche , 0 si impossible
     * @param y et x : coordonnées de la piece
     * @param k : niveau de la piece*/
    int pieceConstructible(int y,int x,int k) const;

    /** @brief  vérifie la possibilité de construire chaque type de piece */
    void setAchetable(int y,int x, int ferraille);

    /** @brief  vide les données contenue dans chantier */
    void clear();

    ~Construction();

};
#endif

#ifndef MOUVEMENT_H
#define MOUVEMENT_H

#include "../pieces/piece.h"
#include "../outils/alerte.h"
#include <vector>

/** \class Mouvement [mouvement.h]
 *  \brief Mouvement gère le déplacement des personnages.
 *
 * cette classe utilise plusieurs vectors pour récupèrer temporairement les
 * pointeurs de personnages et gérer leur déplacement */
class Mouvement {

private:
    vector<Personnage*> perso;
    vector<Piece *> piece;
    vector<int> etape;
    vector<vector<int> > y;
    vector<vector<int> > x;
    //vector<deplacement> dpl;
    Piece **pieces;
    vector<Personnage *>perso_explo;
    vector<Piece *>piece_explo;
    vector<int>temps_restant;

    bool finexplo;
    int fer;

    Alerte* alerte;

public:
    Mouvement();
    /** @brief fonction interne : remplis les vectors par le trajet à faire pour le personnage
     * @param yd et xd : coordonnées de départ du personnage
     * @param ya et xa : coordonnées d'arrivé du personnage
     * @param x et y : vector remplis par la fonction contenant le chemin*/
    bool pathFinding(int yd, int xd,int ya, int xa,vector<int> &x,vector<int> &y);

    /** @brief Mutatuer : récupère le pointeur du tableau de pieces créé dans jeu
     * @param pieces_ : pointeur du tableau de pieces */
    void setPtr(Piece **pieces_,Alerte* alerte_);

    /** @brief Getter  : récupère le nombre de personnage actuellement en déplacement */
    int getNb() const;

    bool getFin() const;
    int getFer() const;
    void setFin(bool value);

    /** @brief update la position des personnages, et les explorations
     * @param ferraille: donnée membre de Stat récupère en mode donnée résultat */
    void update(int &ferraille);

    /** @brief Mutatuer : ajoute un personnage pour le faire se déplacer */
    bool addPerso(Personnage* personnage,Piece *p,bool ext,int yd, int xd,int ya,int xa,int yp,int xp);

    /** @brief Mutatuer : récupère le vector contenant les pointeurs de personnages*/
    vector<Personnage *> getPerso();

    /** @brief ajoute un personnage à l'exploration */
    void addExplo(Personnage *p,Piece *piece);

    void clear();
};

#endif

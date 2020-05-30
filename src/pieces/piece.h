#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include "../constante.h"
#include "../personnages/Personnage.h"

using namespace std;

/** \class Piece [piece.h]
 *  \brief pieces composant le jeu
 *
 * cette classe est une "piece" qui contient des personnages, des Id de texture,
 * et des mutateurs pour afficher les différentes pieces qui vont apparaitre dans le jeu*/
class Piece
{
protected:
/**
 * @brief position verticale et horizontale de la piece
 */
    int y,x,anim;
/**
 * @brief niveau de la piece
 */
    unsigned int niveau;
/**
 * @brief tableau de pointeur contenant les personnages de la piece
 */
    Personnage **tab;
/**
 * @brief largeur de la piece
 */
    unsigned int DimX;
/**
 * @brief nombre de personnage dans la piece
 */
    unsigned int NbPerso;
/**
 * @brief texture dae la piece (utilise: constante.h)
 */
    unsigned int Texture;
/**
 * @brief entier positif representent la selecetion du menu de contruction
 */
    unsigned int selection;
/**
 *  @brief booleen destructible (True = la piece est destructible)
 *  booleen agrandissable (True = la piece est agrandissable)
 *  booleen asc (True = est un ascenseur);
 *  booleen allumer (True = la piece est allumer)
 */
    bool allumer,asc,destructible,agrandissable;
/**
 * @brief entier positif qui exprime le type production de la piece (utilise: constante.h)
 */
    unsigned int type;

    unsigned int prix[3];

public:
/**
 * @brief Constructeur par defaut de la classe:
 */
    Piece();
/**
 * @brief Constructeur de la classe initialise la position de la piece son niveau et
 * le booléen asc en false car la piece basique n'est pas un ascenseur
 * @param y_ : nouvelle position verticale
 * @param x_ : nouvelle position horizontale
 * @param niveau_ : nouveau niveau de la piece (par defaut 1)
 * @param asc_ : nouvelle valeur de asc (par default false)
 */
    Piece(int y_,int x_,unsigned int niveau_ = 1,bool asc_ = false);
/**
 * @brief Mutateur : modifie l'etat d'alimentation
 * @param elec : nouvelle etat
 */
    void setAllumer(bool elec);

/** @brief procedure qui ajoute un personnage à tab
 *  @warning pas plus de personnage que perso max
 *  @param p : pointeur sur le personnage à ajouter
 */
    void addPerso(Personnage * p,int py,int px);

/**  @brief Accesseur : recupere le pointeur d'un personnage
 * @param i : ième personnage à récuperer */
    Personnage* getPerso(int i);

/**  @brief Accesseur : recupere le pointeur d'un personnage si x et y sont
 * sur le personnage.
 * retourne nullptr si aucun personnage.
 * @param y et x : coordonnées du clique. */
    Personnage * persoPresent(int y,int x);

/**  @brief Mutatuer : supprime le pointeur d'un personnage de la piece
 * @param p : pointeur du personnage à supprimer */
    void suppPerso(Personnage*p);
/**
 * @brief Accesseur : recupere la texture de la piece
 */
    unsigned int getTexture() const;
/**
 * @brief Mutateur : modifie la texture de la piece
 * @param tex : nouvelle texture de la piece
 */
    virtual void setTexture(unsigned int tex);
/**
 * @brief Mutateur : modifie la selection du menu
 *  @param s : nouvelle selection de la piece
 */
    void setSelection(unsigned int s);
/**
 * @brief Accesseur : recupere la selection du menu
 */
    unsigned int getSelection() const;
/**
 * @brief Mutateur : modifie la position de la piece
 * @param y_ : nouvelle position verticale de la piece
 * @param x_ : nouvelle position horizontale de la piece
 */
    void setYX(int y_,int x_);
/**
 * @brief Accesseur : retourne la position verticale de la piece
 */
    int getX() const;
/**
 * @brief Accesseur : retourne la position horizontale de la piece
 */
    int getY() const;
/**
 * @brief Accesseur : retourne le niveau de la piece
 */
    unsigned int getNiveau() const;
/**
 * @brief Mutateur : modifie le niveau de la piece
 * @param niv : nouveau niveau de la piece
 */
    void setNiveau(unsigned int niv);
/**
 * @brief Accesseur : retourne la largeur de la piece
 */
    unsigned int getDimX() const;
/**
 * @brief Mutateur : modifie la largeur de la piece
 * @param DimX_ : nouvelle largeur de la piece de la piece
 */
    void setDimX(unsigned int DimX_);
/**
 * @brief Accesseur : retourne la production de piece (utilie pour stat)
 */
    virtual unsigned int getProduction() const;
/**
 * @brief Accesseur : retourne true si la piece est un ascenceur
 */
    bool isAsc() const;
/**
 * @brief la piece devient un ascenseur
 */
    void setAsc();
/**
 * @brief Mutateur : modifie l'etat de destruction de la piece
 * @param b : nouvelle letat de destruction de la piece
 */
    void setDest(bool b);
/**
 * @brief Accesseur : retourne l'etat de destruction de la piece
 * (si elle est destructible ou non)
 */
    bool getDest() const;
/**
 * @brief Mutateur : modifie l'etat agrandissemnt de la piece
 * @param b : nouvelle etat d'agrandissemnt de la piece
 */
    void setAgran(bool b);
/**
 * @brief Accesseur : retourne l'etat d'agrandissement de la piece
 * (si elle est agrandissable ou non)
 */
    bool getAgran() const;
/**
 * @brief Accesseur : retourne le type de production de la piece
 * (ref. constante.h)
 */
    unsigned int getType() const;
/**
 * @brief Accesseur : retourne le nbr de personnage dans la piece
 */
    unsigned int getNbPerso() const;
/**
 * @brief Mutateur : modifie le nombre de perso present dans piece
 * @param value: nouveau nombre de personnage
 */
    void setNbPerso(unsigned int value);

/** @brief modifie la valeur du paramètre Animation
   @param value: entier */
    void setAnim(int value);

/** @brief récupère la valeur de Animation */
    int getAnim() const;

/** @brief récupère le prix de la piece
   @param value: niveau de la piece dont on veut récupérer le prix */
    unsigned int getPrix(int value) const;

/**
 * @brief Destructeur de la classe
 */
    virtual ~Piece();

/**
 * @brief procedure pour test
 */
    void testRegressionPiece();
};

#endif

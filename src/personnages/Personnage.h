#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <iostream>
#include <cstdlib>
#include "../constante.h"
#include "equipement.h"

using namespace std;

/** \class Personnage [Personnage.h]
 *  \brief Personnage regroupe toutes les caracteristiques et fonctions nécéssaire
 * à un personnage dans le jeu */
class Personnage {

private:

    unsigned int id_caract,sprite,frame,direction;

    int texture,coef,texture_haut,texture_bas,texture_tete;
    unsigned int x,y,w,h;
/**  @brief le statut du personnage (enfant ou adulte)*/
    bool statut;

/** @brief entier positif correspondant à l'age du personnage (temps_Vie->en secondes, temps en jeu avant qu'il meurt (stat cache))*/
    unsigned int age;

/** @brief booleen exprimant l'etat de sante du perosnnage (False = blesse, True = en bonne sante) */
    bool sante;

/** @brief booleen exprimant l'etat de vie du perosnnage (False = mort, True = en vie)*/
    bool vie;

/** @brief entier positif exprimant le niveau de joie du personnage*/
    unsigned int force;

/** @brief entier positif exprimant l'intelligence du personnage (caracteristique)*/
    unsigned int intelligence;

/** @brief entier positif exprimant la sociabilite du personnage (caracteristique)*/
    unsigned int sociabilite;

/** @brief entier positif exprimant le charme du personnage (caracteristique)*/
    unsigned int charme;

/** @brief entier positif exprimant l'agilite du personnage (caracteristique)*/
    unsigned int agilite;

/** @brief entier positif exprimant la concentration du personnage (caracteristque)*/
    unsigned int concentration;

/** @brief booleen exprimant l'etat de deplacement du personnage (False = statique, True = en mouvement)*/
    bool deplacement;

/** @brief booleen exprimant l'etat d'activite au travail du personnage (False = repos, True = travail)*/
    bool activite;

    string caract;

    Equipement *arme,*armure;

public:

/** @brief Constructeur par defaut de la classe:*/
    Personnage();
    Personnage(int th,int tb,int tt, bool _enfant, unsigned int _age, bool _sante,bool _vie,
               unsigned int _force, unsigned int _int, unsigned int _soc, unsigned int _charme,
               unsigned int _agi,  unsigned int _conc);

    bool ajouterEquipement(Equipement * e);
    bool aArme() const;
    bool aArmure() const;
    Equipement* enleverArme();
    Equipement* enleverArmure();
    int getDegats() const;
    int getArmure() const;

    unsigned int getX();
    unsigned int getY();
    unsigned int getW();
    unsigned int getH();
    int getTexture() const;
    void setTexture(int value);
    bool estSelect(int cy,int cx) const;
    Personnage * getPtr();

    void setCo(unsigned int _x = 0,unsigned int _y = 0,unsigned int _w = 0,unsigned int _h = 0);
/** @brief Accesseur : recupere la force du personnage*/
    unsigned int getForce();

/** @brief Accesseur : recupere l'intelligence du personnage*/
    unsigned int getIntelligence();

/** @brief Accesseur : recupere la sociabilite du personnage*/
    unsigned int getSociabilite();

/** @brief Accesseur : recupere le charme du personnage*/
    unsigned int getCharme();

/** @brief Accesseur : recupère l'agilite du personnage*/
    unsigned int getAgilite();

/** @brief Accesseur : recupère la concentration du personnage*/
    unsigned int getConcentration();

/** @brief Affiche sur la console les caracteristiques du personnage*/
    void afficheCaract();

    bool getVie() const;
/** @brief Mutateur : modifie l'etat de sante du personnage
 * @param Sante : nouvelle etat du booleen sante*/
    void setSante(bool Sante);
    bool getSante() const;

/** @brief Mutateur : modifie l'etat de deplacement du personnage
 * @param Dpl : nouvelle etat du deplacement */
    void setDeplacement(bool Dpl);
    bool getDeplacement() const;

/** @brief Mutateur : modifie l'etat d'activite au travail du personnage
 * @param Act : nouveau etat du booleen d'activite*/
    void setActivite(bool Act);

/** @brief Mutateur : modifie le statut du personnage
 * @param stt : nouveau statut du personnage*/
    void setStatut(bool stt);

/** @brief Getter : récupère le statut d'un personnage.*/
    bool getStatut() const;

/** @brief procedure appelee toutes les minutes qui gere le statut du personnage et son etat de vie*/
    void duree_Vie();

/** @brief Getter : récupère l'age d'un personnage.*/
    unsigned int getAge() const;

/** @brief Getter : récupère un string contenant les caractéristiques d'un personnage.*/
    string getStringCaract() const;

/** @brief Mutateur : donne un Id qui lie le personnage à la textures de ses caractéristiques*/
    void setId_caract(int value);

/** @brief Getter : récupère l'id de la texture des caracteristque d'un personnage.*/
    int getId_caract() const;

/** @brief Setter : Passe au sprite suivant.*/
    void nextSprite();

    /** @brief Setter : remet le spite à celui par défaut 0.*/
    void resetSprite();

    /** @brief Getter : récupère le numéro du sprite à afficher.*/
    unsigned int getSprite() const;
/** @brief entier : utiliser pour le dépaclement d'un personnage, j'ai eu la flemme des
 * getter et setter après avoir fait le projet seul :/ ...*/

    int getTexBas() const;

    void setTexBas(int value);

    int getTexHaut() const;

    void setTexHaut(int value);

    int getTexTete() const;

    void setTexTete(int value);

    void setDirection(unsigned int value);
    int dpl;

};


#endif

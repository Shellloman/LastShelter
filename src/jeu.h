#ifndef JEU_H
#define JEU_H

#include <iostream>
#include "pieces/piece.h"
#include "outils/construction.h"
#include "outils/graphisme.h"
#include "outils/stat.h"
#include "outils/audio.h"
#include "personnages/mouvement.h"
#include "outils/alerte.h"
#include "personnages/inventaire.h"

using namespace std;

/** \class Jeu [jeu.h] [jeu]
 *  \brief classes principales faisant tourner le jeu
 *
 * cette clase à 2 objectifs, faire le lien entre le jeu et l'utilisateur en utilisant la SDL
 * mais aussi gérer le jeu en controllant différentes classes crées*/
class Jeu {

private:
    SDL_Renderer* rendu;
    SDL_Rect tab[9*17],rclique,rconstruire,rCoo,rp,rC;

    Piece **pieces,*piece_selection;
    Construction batiment;
    Graphisme graphisme;
    Stat stat;
    Personnage *p_sel,*extPerso;
    Mouvement mouv;
    Audio audio;
    Alerte* alerte;
    Inventaire inv;

    int fps,frame,equip;
    bool menu_construction,ext,binv;
    unsigned int time,time2;

    vector<Personnage*> vperso;

public:
/** constructeur de la classe
 * \param _rendu : pointeur vers un SDL_Renderer pour afficher les images*/
    Jeu(SDL_Renderer* _rendu);
    ~Jeu();

/** \brief boucle principales du jeu
 * \details la boucle gère les inputs du joueurs et s'occupe
 * d'appeler régulièrement l'affichage et l'update du jeu.
 * la bouvle renvoie un int en fonction de si vous voulez quitter le jeu ou revenir au menu*/
    int Boucle(int &save);

    void update();
/** \brief S'occupe de  récuperer les coordonnées du clique et attribut a rclique
 * des coordonnées plus simple correspondant à tab[9*17] */

    void Affichage();

    void GetClique();

/** \brief utilise rclique pour savoir où à cliquer l'utilisiteur est appeler
 * la bonne fonction en conséquance*/
    void SetClique();


/** \brief récupère la Classe Audio*/
    Audio& getAudio();

/** \brief libère la mémoires des pieces et d'autre classes*/
    void clear();


};

#endif

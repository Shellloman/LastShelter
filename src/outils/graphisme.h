#ifndef GRAPHISME
#define GRAPHISME

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "../pieces/piece.h"
#include "../constante.h"
#include "construction.h"
#include "stat.h"
#include "../personnages/mouvement.h"
#include "alerte.h"
#include "../personnages/inventaire.h"
#include <vector>

/** \class Graphisme [graphisme.h]
 *  \brief affiche toutes les textures
 *
 * cette classe créée et affiche toutes les textures des différentes classes*/
class Graphisme {
private:
    SDL_Texture **T_Pieces,**T_Select,**T_Decor,**T_Stat,**T_Perso;
    SDL_Texture **ttf, *T_alerte;
    vector<SDL_Texture*> caract,V_perso,V_inv;
    SDL_Renderer *rendu;
    SDL_Rect rFond,rPiece,rCarte,rttf[14],sPerso[17],rAlerte,rCursor;
    Piece ** pieces;
    SDL_Color couleur;
    TTF_Font *police;
    Alerte* alerte;

public:
    Graphisme(SDL_Renderer *rendu_);

    /** @brief Mutatuer : récupère le pointeur du tableau de pieces créé dans jeu
     * @param pieces_ : pointeur du tableau de pieces */
    void setPtr(Piece **pieces_,Alerte* alerte_);

    void setTexturePersonnage();
    /** @brief Mutatuer : créé une texture à partir d'une image
     * @param chemin : chemin vers l'image */
    SDL_Texture* Load(const char* chemin);

    /** @brief Affiche les salles et les personnages à l'interieur
     * @param tab : tableau de coordonnées du batiment*/
    void Affichage_jeu(Construction &batiment,SDL_Rect *tab);

    /** @brief Affiche le menu de la piece sélectionnée
     * @param tmp : piece dont le menu doit être affiché*/
    void Afficher_menu_piece(Piece* tmp, Construction &batiment);

    /** @brief Affiche les salles qui construisible en bleu et non construisible
     * en rouge */
    void Afficher_menu_construction(Construction &batiment);

    /** @brief Affiche les stats en haut de l'écran
     * @param stat : classe Stat*/
    void Afficher_stat(Stat &stat,int fps,bool inv);

    /** @brief Affiche les contours de chaque piece*/
    void Afficher_contour(Construction &batiment,SDL_Rect *tab);

    /** @brief Affiche un coutour rouge sur la piece selectionnée
     * @param p : pointeur vers la piece selectionnée*/
    void Afficher_selection(Piece *p,SDL_Rect *tab);

    /** @brief Affiche les personnages dehors et en mouvement*/
    void Afficher_perso(vector<Personnage*> v,Mouvement &mouv);

    /** @brief Affiche les caracteristiques d'un personnage
     * @param p_sel : pointeur vers le personnage dont on veut afficher les caracteristiques*/
    void Afficher_caracteristique(Personnage *p_sel);

    void Afficher_alerte();

    void Afficher_inventaire(Inventaire& inv);

    void Afficher_cursor(int y, int x);

    void Afficher_choix();

    /** @brief retourne une texture à partir d'un string ajouter un '/' pour sauter une ligne */
    SDL_Texture* sautligne(string str,bool taille_fixe);

    SDL_Texture* StringToTexture(string str);

    /** @brief créer une texture aléatoire (parmis plusieurs choix) pour un personnage*/
    SDL_Texture * CreateTexturePerso(Personnage * p);

    /** @brief retorune le SDL_Rect Rfond */
    SDL_Rect& getRFond();

    void clear();

};

#endif

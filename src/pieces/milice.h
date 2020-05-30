#ifndef MILICE_H
#define MILICE_H

#include "piece.h"
/** \class Milice [milice.h]
 *  \brief Milice est un piece, qui permet d'envoyer des personnages en explorations
 *  pour gagner de la férrailles, monnaie du jeu
 *
 * cette classe hérite de Piece, certain mutateurs sont surchargés pour afficher
 * les bonnes textures et ajouter les fonctionnalités spécifique à la piece*/
class Milice : public Piece
{
public:
    Milice(int y_,int x_,unsigned int niveau_ = 1,bool asc_ = false);
    ~Milice();
    void setTexture(unsigned int tex);
};

#endif

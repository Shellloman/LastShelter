#ifndef ATELIER_H
#define ATELIER_H

#include "piece.h"

/** \class Atelier [atelier.h]
 *  \brief Atelier est un piece.
 *
 * cette classe hérite de Piece, certain mutateurs sont surchargés pour afficher
 * les bonnes textures et ajouter les fonctionnalités spécifique à la piece*/
class Atelier : public Piece
{
public:
    Atelier(int y_,int x_,unsigned int niveau_ = 1,bool asc_ = false);
    ~Atelier();
    void setTexture(unsigned int tex);
};

#endif

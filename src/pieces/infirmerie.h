#ifndef INFIRMERIE_H
#define INFIRMERIE_H

#include "piece.h"
/** \class Infirmerie [infirmerie.h]
 *  \brief Infirmerie est un piece, qui permet de soigner les bléssées
 *
 * cette classe hérite de Piece, certain mutateurs sont surchargés pour afficher
 * les bonnes textures et ajouter les fonctionnalités spécifique à la piece*/
class Infirmerie : public Piece
{
public:
    Infirmerie(int y_,int x_,unsigned int niveau_ = 1,bool asc_ = false);
    ~Infirmerie();
    void Soigne();
    void setTexture(unsigned int tex);
};

#endif
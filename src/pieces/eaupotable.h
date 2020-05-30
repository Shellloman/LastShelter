#ifndef EAUPOTABLE_H
#define EAUPOTABLE_H

#include "piece.h"
/** \class Eaupotable [eaupotable.h]
 *  \brief Eaupotable est un piece, qui permet la production d'eau potable
 *
 * cette classe hérite de Piece, certain mutateurs sont surchargés pour afficher
 * les bonnes textures et ajouter les fonctionnalités spécifique à la piece*/
class Eaupotable : public Piece
{
public:
    Eaupotable(int y_,int x_,unsigned int niveau_ = 1,bool asc_ = false);
    ~Eaupotable();
    unsigned int getProduction() const;
    void setTexture(unsigned int tex);
};

#endif

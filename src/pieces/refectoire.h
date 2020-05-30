#ifndef REFECTOIRE_H
#define REFECTOIRE_H

#include "piece.h"
/** \class Refectoire [refectoire.h]
 *  \brief Refectoire est un piece, qui permet de produire de la nourriture
 *
 * cette classe hérite de Piece, certain mutateurs sont surchargés pour afficher
 * les bonnes textures et ajouter les fonctionnalités spécifique à la piece*/
class Refectoire : public Piece
{
public:
    Refectoire(int y_,int x_,unsigned int niveau_ = 1,bool asc_ = false);
    ~Refectoire();
    unsigned int getProduction() const;
    void setTexture(unsigned int tex);
};

#endif

#ifndef REACTEUR_H
#define REACTEUR_H

#include "piece.h"
/** \class Reacteur [reacteur.h]
 *  \brief Reacteur est un piece, qui permet de produire de l'énérgie
 *
 * cette classe hérite de Piece, certain mutateurs sont surchargés pour afficher
 * les bonnes textures et ajouter les fonctionnalités spécifique à la piece*/
class Reacteur : public Piece
{
public:
    Reacteur(int y_,int x_,unsigned int niveau_ = 1,bool asc_ = false);
    ~Reacteur();
    unsigned int getProduction() const;
    void setTexture(unsigned int tex);
};

#endif

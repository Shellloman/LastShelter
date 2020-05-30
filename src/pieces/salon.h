#ifndef SALON_H
#define SALON_H

#include "piece.h"
/** \class Salon [salon.h]
 *  \brief Salon est un piece, qui permet de garder les personnages heureux
 *
 * cette classe hérite de Piece, certain mutateurs sont surchargés pour afficher
 * les bonnes textures et ajouter les fonctionnalités spécifique à la piece*/
class Salon : public Piece {
public:
    Salon(int y_,int x_,unsigned int niveau_ = 1,bool asc_ = false);
    ~Salon();
    unsigned int getProduction() const;
    void setTexture(unsigned int tex);
};

#endif

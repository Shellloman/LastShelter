#ifndef DORTOIR_H
#define DORTOIR_H

#include "piece.h"
/** \class Dortoir [dortoir.h]
 *  \brief Dortoir est un piece, qui permet d'accueillir des personnages dans l'abrie
 *
 * cette classe hérite de Piece, certain mutateurs sont surchargés pour afficher
 * les bonnes textures et ajouter les fonctionnalités spécifique à la piece*/
class Dortoir : public Piece {
public:
    Dortoir(int y_,int x_,unsigned int niveau_ = 1,bool asc_ = false);
    ~Dortoir();
    void setTexture(unsigned int tex);
    unsigned int getProduction() const;
};

#endif

#ifndef AUDIO_H
#define AUDIO_H

#include <stdio.h>
#include <iostream>
#include <irrKlang.h>
#include "conio.h"
#include <cstdlib>
#include <ctime>
#include "../constante.h"

using namespace irrklang;
/** \class Audio [audio.h]
 *  \brief Audio gère tout le song du jeu.
 *
 * cette classe met une musique en fond, parmis 5 de façon aléatoire. Elle met
 * aussi des bruitages sur différentes actions dans le jeu. */
class Audio {
private:
    ISoundSource **effet,**ambiance,*chantier,*self,*dortoir;
    ISoundSource **attente;
    ISoundEngine *engine;
    ISoundSource *last_song,*last_effet;
    int song,expl;

public:
    Audio();
    /** @brief fonction appelé dans la boucle principal, elle gère la musique*/
    void update();

    /** @brief joue une musique ne fonction du type de la piece sélectionné*/
    void play_sound_piece(int type);

    /** @brief arrete la musique relatif à la piece*/
    void stop_sound_piece(int type);

    /** @brief joue un song lors de la construction ou de l'agrandissement d'une piece*/
    void play_travaux();

    /** @brief passe à la chanson suivante, fonction au final inutile qui m'a rendu la touche compliqué pour rien ... mais elle marche*/
    void skip();
};

#endif

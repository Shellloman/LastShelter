#include "audio.h"

Audio::Audio(){
    engine = createIrrKlangDevice();
    if (!engine) {
        printf("Could not startup engine\n");
    }

    effet = new ISoundSource *[5];
    effet[0] = engine->addSoundSourceFromFile("data/audio/effet/vent2.mp3");
    effet[1] = engine->addSoundSourceFromFile("data/audio/effet/feu.mp3");
    effet[2] = engine->addSoundSourceFromFile("data/audio/effet/street.mp3");
    effet[3] = engine->addSoundSourceFromFile("data/audio/effet/vent.mp3");
    effet[4] = engine->addSoundSourceFromFile("data/audio/effet/explosion_lointaine.mp3");
    effet[0]->setDefaultVolume(0.2f);
    effet[1]->setDefaultVolume(0.15f);
    effet[2]->setDefaultVolume(0.1f);
    effet[3]->setDefaultVolume(0.1f);
    effet[4]->setDefaultVolume(0.3f);
    ambiance = new ISoundSource *[5];
    ambiance[0] = engine->addSoundSourceFromFile("data/audio/ambiance/a_journey_beyond_the_sky.mp3");
    ambiance[1] = engine->addSoundSourceFromFile("data/audio/ambiance/a_peaceful_sanctuary.mp3");
    ambiance[2] = engine->addSoundSourceFromFile("data/audio/ambiance/the_end_of_the_word.mp3");
    ambiance[3] = engine->addSoundSourceFromFile("data/audio/ambiance/the_first_colony.mp3");
    ambiance[4] = engine->addSoundSourceFromFile("data/audio/ambiance/time_of_solitude.mp3");
    ambiance[0]->setDefaultVolume(0.2f);
    ambiance[1]->setDefaultVolume(0.2f);
    ambiance[2]->setDefaultVolume(0.2f);
    ambiance[3]->setDefaultVolume(0.3f);
    ambiance[4]->setDefaultVolume(0.2f);
    chantier = engine->addSoundSourceFromFile("data/audio/effet/chantier.mp3");
    chantier->setDefaultVolume(0.15f);
    self = engine->addSoundSourceFromFile("data/audio/piece/self.mp3");
    self->setDefaultVolume(0.1f);
    dortoir = engine->addSoundSourceFromFile("data/audio/piece/dortoir.mp3");
    dortoir->setDefaultVolume(0.05f);

    attente = new ISoundSource *[5];
    attente[0] = ambiance[0]; attente[1] = ambiance[1]; attente[2] = ambiance[2];
    attente[3] = ambiance[3]; attente[4] = ambiance[4];
    song = 5;
    last_song = nullptr;
    std::srand(std::time(0));
    expl = 10;
}

void Audio::update(){
    if(last_song == nullptr ||(last_song != nullptr && !engine->isCurrentlyPlaying(last_song))) {
        int value = std::rand()%song;
        last_song = attente[value];
        engine->play2D(last_song);
        std::cout << "musique joué: "<<last_song->getName()<<"\n";
        song--;
        if(song == 0) {
            song = 5;
            attente[0] = ambiance[0]; attente[1] = ambiance[1]; attente[2] = ambiance[2];
            attente[3] = ambiance[3]; attente[4] = ambiance[4];
        }else{
            ISoundSource **tmp = new ISoundSource*[song];
            for(int i = 0; i<song; i++) {
                if (i < value) tmp[i] = attente[i];
                else {
                    tmp[i] = attente[i+1];
                }
            }
            attente = tmp;
        }
    }
    if(last_effet == nullptr ||(last_effet != nullptr && !engine->isCurrentlyPlaying(last_effet))) {
        int value2 = std::rand()%4;
        last_effet = effet[value2];
        engine->play2D(last_effet);
        std::cout<<"effet joué: "<<last_effet->getName()<<std::endl;
    }
    if(expl ==  0) {
        engine->play2D(effet[4]);
        expl = std::rand()%180 + 30;
        std::cout<<"expl : "<<expl<<std::endl;
    }
    expl--;

}
void Audio::skip(){
    std::string path = last_song->getName();
    engine->removeSoundSource(last_song);
    if(path.compare("data/audio/ambiance/a_journey_beyond_the_sky.mp3")==0) {
        ambiance[0] = engine->addSoundSourceFromFile("data/audio/ambiance/a_journey_beyond_the_sky.mp3");
        ambiance[0]->setDefaultVolume(0.2f);
    }
    else if(path.compare("data/audio/ambiance/a_peaceful_sanctuary.mp3")==0) {
        ambiance[1] = engine->addSoundSourceFromFile("data/audio/ambiance/a_peaceful_sanctuary.mp3");
        ambiance[1]->setDefaultVolume(0.2f);
    }
    else if(path.compare("data/audio/ambiance/the_end_of_the_word.mp3")==0) {
        ambiance[2] = engine->addSoundSourceFromFile("data/audio/ambiance/the_end_of_the_word.mp3");
        ambiance[2]->setDefaultVolume(0.2f);
    }
    else if(path.compare("data/audio/ambiance/the_first_colony.mp3")==0) {
        ambiance[3] = engine->addSoundSourceFromFile("data/audio/ambiance/the_first_colony.mp3");
        ambiance[3]->setDefaultVolume(0.3f);
    }
    else if(path.compare("data/audio/ambiance/time_of_solitude.mp3")==0) {
        ambiance[4] = engine->addSoundSourceFromFile("data/audio/ambiance/time_of_solitude.mp3");
        ambiance[4]->setDefaultVolume(0.2f);
    }
}
void Audio::play_sound_piece(int type){
    switch (type) {
        case ASC: break;
        case DORTOIR: engine->play2D(dortoir,true); break;
        case REACTEUR: break;
        case EAU:  break;
        case SELF: engine->play2D(self,true); break;
        case ATELIER:  break;
        case SALON: break;
        case INFIRM: break;
        case MILICE: break;
        default: break;
    }
}
void Audio::stop_sound_piece(int type){
    switch (type) {
        case ASC: break;
        case DORTOIR: engine->removeSoundSource(dortoir);
            dortoir = engine->addSoundSourceFromFile("data/audio/piece/dortoir.mp3");
            dortoir->setDefaultVolume(0.05f); break;
        case REACTEUR: break;
        case EAU:  break;
        case SELF: engine->removeSoundSource(self);
            self = engine->addSoundSourceFromFile("data/audio/piece/self.mp3");
            self->setDefaultVolume(0.1f); break;
        case ATELIER:  break;
        case SALON: break;
        case INFIRM: break;
        case MILICE: break;
        default: break;
    }
}
void Audio::play_travaux(){
    engine->play2D(chantier);
    std::cout<<"effet joué: "<<chantier->getName()<<std::endl;
}

#include "alerte.h"


Alerte::Alerte(){
    changement = true;
    duree = 3;
    last_id = 0;
}

void Alerte::addAlerte(string msg,int id){
    messages.push_back(msg);
    last_id = id;
}

bool Alerte::getChange() const {
    return changement;
}
void Alerte::setChange(bool value){
    changement = value;
}
string Alerte::getAlerte(){
    changement = false;
    return messages.front();
}
int Alerte::getNombre(){
    return int(messages.size());
}
void Alerte::update(){
    if(messages.size()<=0) return;
    if(duree<=0) {
        changement = true;
        messages.pop_front();
        duree = 3;
    }
    duree--;
}

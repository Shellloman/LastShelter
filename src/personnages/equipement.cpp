#include "equipement.h"

Equipement::Equipement(std::string n,int dmin,int dmax,int a, int t){
    nom = n;
    degatMin = dmin;
    degatMax = dmax;
    armure = a;
    type = t;
    texture = -1;
}

std::string Equipement::getNom() const {
    return nom;
}
std::string Equipement::getString() const {
    std::string tmp;
    tmp = nom+"/degats : "+std::to_string(degatMin)+"-"+std::to_string(degatMax)+
          "/armure : "+std::to_string(armure);
    return tmp;
}
int Equipement::getDegat() const {
    return std::experimental::randint(degatMin,degatMax);
}
int Equipement::getArmure() const {
    return armure;
}
int Equipement::getType() const {
    return type;
}
int Equipement::getTexture() const {
    return texture;
}
void Equipement::setTexture(int value){
    texture = value;
}

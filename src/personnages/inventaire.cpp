#include "inventaire.h"

Inventaire::Inventaire(){
    nomsArme[0] = "Pistolet";
    nomsArme[1] = "Revolver";
    nomsArme[2] = "Fusil rouille";
    nomsArme[3] = "Machette";
    nomsArme[4] = "Babouche";

    nomsArmure[0] = "Kevlar";
    nomsArmure[1] = "bouclier";
    nomsArmure[2] = "Croks";

}
void Inventaire::setPtr(Alerte * alerte_){
    alerte = alerte_;
}
std::string Inventaire::getString(int i){
    string str;
    if(i>=0 && i<int(equip.size())) {
        str  = equip[i]->getString();
    }
    return str;
}
Equipement* Inventaire::getEquipement(int i){
    Equipement * tmp;
    if(i>=0 && i<int(equip.size())) {
        tmp =  equip[i];
    }else{
        tmp = nullptr;
    }
    return tmp;
}
void Inventaire::recupererEquipement(Equipement * e){
    if(e !=nullptr) {
        equip.push_back(e);
    }
}
void Inventaire::supEquipement(int i){
    if(i>=0 && i<int(equip.size())) {
        equip.erase(equip.cbegin()+i);
    }
}
int Inventaire::getNombre(){
    return equip.size();
}
void Inventaire::addEquipement(){
    int type;
    int dmin = 0;
    int dmax = 0;
    int ar = 0;
    std::string nom;
    if(std::rand()%2) {
        type = ARME;
        dmin = std::experimental::randint(1,5);
        dmax = dmin + std::experimental::randint(0,2);
        nom = nomsArme[std::experimental::randint(0,4)];
    }else{
        type = ARMURE;
        ar = std::experimental::randint(1,5);
        nom = nomsArmure[std::experimental::randint(0,2)];
    }
    equip.push_back(new Equipement(nom,dmin,dmax,ar,type));
}

#include "Personnage.h"

Personnage::Personnage() {

    force= rand() % 10+1;
    intelligence= rand() % 10+1;
    sociabilite = rand() % 10+1;
    charme = rand() % 10+1;
    agilite = rand() % 10+1;
    concentration = rand() % 10+1;

    statut = true;
    age = rand() % 9001+1000;  // le personnage arrive avec un age entre 1000 et 10000 secondes
    sante = true;
    vie = true;

    activite = false;
    deplacement = false;

    x = 100; y = 2523; w= 70; h = 164;
    texture = PERSO;
    id_caract = -1;
    dpl = sprite = frame = 0;
    direction = 1; coef = 1;
    texture_bas = -1; texture_haut = -1; texture_tete = -1;
    caract ="force : "+to_string(force)+"/charme : "+to_string(charme)+"/agilite : "+
             to_string(agilite)+"/sociabilite : "+to_string(sociabilite)+"/intelligence : "+
             to_string(intelligence)+"/concentration : "+to_string(concentration);
    armure = nullptr; arme = nullptr;
}

Personnage::Personnage(int th,int tb,int tt, bool _enfant, unsigned int _age, bool _sante,bool _vie,
                       unsigned int _force, unsigned int _int, unsigned int _soc, unsigned int _charme,
                       unsigned int _agi,  unsigned int _conc){
    force= _force;
    intelligence= _int;
    sociabilite = _soc;
    charme = _charme;
    agilite = _agi;
    concentration = _conc;

    statut = _enfant;
    age = _age;
    sante = _sante;
    vie = _vie;

    activite = false;
    deplacement = false;

    x = 100; y = 2523; w= 70; h = 164;
    texture = PERSO; texture_tete =tt; texture_bas = tb; texture_haut = th;
    id_caract = -1;
    dpl = sprite = frame = 0;
    direction = 1; coef = 1;
    caract ="force : "+to_string(force)+"/charme : "+to_string(charme)+"/agilite : "+
             to_string(agilite)+"/sociabilite : "+to_string(sociabilite)+"/intelligence : "+
             to_string(intelligence)+"/concentration : "+to_string(concentration);
    arme = nullptr; armure = nullptr;
}
bool Personnage::estSelect(int cy,int cx) const {
    return (cy >= int(y) && cy <= int(y + h) && cx >= int(x) && cx <= int(x + w));
}

bool Personnage::ajouterEquipement(Equipement * e){
    if(e->getType()==ARME) {
        if (arme!=nullptr) {
            return false;
        }else{
            arme = e;
        }
    }else{
        if(armure !=nullptr) {
            return false;
        }else{
            armure = e;
        }
    }
    caract +="/"+e->getString();
    id_caract = -1;
    return true;
}
Equipement* Personnage::enleverArme(){
    Equipement* tmp = arme;
    arme = nullptr;
    caract ="force : "+to_string(force)+"/charme : "+to_string(charme)+"/agilite : "+
             to_string(agilite)+"/sociabilite : "+to_string(sociabilite)+"/intelligence : "+
             to_string(intelligence)+"/concentration : "+to_string(concentration);
    id_caract = -1;
    return tmp;
}
Equipement* Personnage::enleverArmure(){
    Equipement* tmp = armure;
    armure = nullptr;
    caract ="force : "+to_string(force)+"/charme : "+to_string(charme)+"/agilite : "+
             to_string(agilite)+"/sociabilite : "+to_string(sociabilite)+"/intelligence : "+
             to_string(intelligence)+"/concentration : "+to_string(concentration);
    id_caract = -1;
    return tmp;
}
bool Personnage::aArme() const {
    return arme !=nullptr;
}
bool Personnage::aArmure() const {
    return armure !=nullptr;
}
int Personnage::getDegats() const {
    int d;
    if (arme != nullptr) d = arme->getDegat() + 1;
    else d = 1;
    return d;
}
int Personnage::getArmure() const {
    int a;
    if (armure != nullptr) a = armure->getArmure();
    else a = 0;
    return a;
}
Personnage * Personnage::getPtr(){
    return this;
}

unsigned int Personnage::getForce() {
    return force;
}

unsigned int Personnage::getIntelligence() {
    return intelligence;
}

unsigned int Personnage::getSociabilite() {
    return sociabilite;
}
unsigned int Personnage::getCharme() {
    return charme;
}
unsigned int Personnage::getAgilite() {
    return agilite;
}

unsigned int Personnage::getConcentration() {
    return concentration;
}

void Personnage::afficheCaract() {
    cout << "Force : " << force<< "/10" << endl;
    cout << "Intellignece : " << intelligence << "/10" << endl;
    cout << "Sociabilité : " << sociabilite << "/10" << endl;
    cout << "Charme : " << charme << "/10" << endl;
    cout << "Agilité : " << agilite << "/10" << endl;
    cout << "Concentration : " << concentration << "/10" << endl;

}

unsigned int Personnage::getX(){
    return x;
}
unsigned int Personnage::getY(){
    return y;
}
unsigned int Personnage::getW(){
    return w;
}
unsigned int Personnage::getH(){
    return h;
}
int Personnage::getTexture() const {
    return texture;
}
void Personnage::setTexture(int value){
    texture = value;
}
bool Personnage::getStatut() const {
    return statut;
}
bool Personnage::getSante() const {
    return sante;
}
bool Personnage::getVie() const {
    return vie;
}
unsigned int Personnage::getAge() const {
    return age;
}
void Personnage::setCo(unsigned int _x,unsigned int _y,unsigned int _w,unsigned int _h ){
    if (_x != 0) x = _x;
    if (_y != 0) y = _y;
    if (_w != 0) w = _w;
    if (_h != 0) h = _h;
}

void Personnage::setSante(bool Sante) {
    sante = Sante;
}

void Personnage::setDeplacement(bool Dpl) {
    deplacement = Dpl;
}
bool Personnage::getDeplacement() const {
    return deplacement;
}

void Personnage::setActivite(bool Act) {
    activite = Act;
}

void Personnage::setStatut(bool stt) {
    statut = stt;
}
string Personnage::getStringCaract() const {
    return caract;
}
void Personnage::setId_caract(int value){
    id_caract = value;
}
int Personnage::getId_caract() const {
    return id_caract;
}
void Personnage::nextSprite(){
    if(frame == 5 || sprite == 0) {
        frame = 0;
        if (direction == 0) {
            if (sprite >= 8) {
                // coef = -1;
                sprite = 0;
            }
            // else if(sprite <= 1) {
            //     coef = 1;
            // }
            sprite += coef;
        }else if (direction==1) {
            if (sprite <= 9) {
                coef = 1;
                sprite = 9;
            }
            else if (sprite >= 16) {
                // coef = -1;
                sprite = 8;
            }
            sprite += coef;
        }
    }else{
        frame++;
    }
}
void Personnage::setDirection(unsigned int value){
    direction = value;
}
void Personnage::resetSprite(){
    sprite = 0; frame = 0;
    direction = 1;
}

unsigned int Personnage::getSprite() const {
    return sprite;
}
int Personnage::getTexBas() const {
    return texture_bas;
}

void Personnage::setTexBas(int value){
    texture_bas = value;
}

int Personnage::getTexHaut() const {
    return texture_haut;
}

void Personnage::setTexHaut(int value){
    texture_haut = value;
}

int Personnage::getTexTete() const {
    return texture_tete;
}

void Personnage::setTexTete(int value){
    texture_tete = value;
}

void Personnage::duree_Vie() { //proc�dure � appeller toutes les minutes

    age += 60; // le perso grandit

    if (age < 1000) // le perso est enfant
    {
        setStatut("enfant");
    }

    if (age >= 1000)  // le perso est adulte (et peut travailler)
    {
        setStatut("adulte");
    }

    if (age >= 15000) {  // le perso meurt
        vie = false;
    }

}

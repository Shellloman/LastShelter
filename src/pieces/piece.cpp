#include "piece.h"
#include <assert.h>

Piece::Piece(int y_,int x_,unsigned int niveau_,bool asc_){
    niveau = niveau_;
    switch(niveau) {
        case 0: DimX = 1; break;
        case 1: DimX = 3; break;
        case 2: DimX = 4; break;
        case 3: DimX = 6; break;
        default: break;
    }
    setTexture(niveau);
    asc = asc_;
    selection = 0;
    y = y_;
    x = x_;
    destructible = true;
    agrandissable = false;
    type = NONE;
    if(asc_) type = ASC;
    tab = new Personnage*[3];
    NbPerso = 0; anim = 0;
    prix[0] = 100; prix[1] = 150; prix[2] = 250;
}

Piece::Piece(){
    y = 0; x = 0;
    niveau = 1;
    DimX = 3;
    Texture= DORTOIR1;
    asc = false;
    selection = 0;
    anim = 0;
    tab = new Personnage*[3];
    prix[0] = 100; prix[1] = 150; prix[2] = 250;
}
Piece::~Piece(){

}
void Piece::addPerso(Personnage * p,int py,int px){
    p->setCo(px +50+ 200*NbPerso,py+95);
    cout<<" add perso "<<NbPerso<<endl;
    tab[NbPerso] = p;
    NbPerso++;
}
Personnage* Piece::getPerso(int i){
    return tab[i];
}
Personnage * Piece::persoPresent(int y,int x){
    for(unsigned int i = 0; i<NbPerso; i++) {
        if(tab[i]->estSelect(y,x)) return tab[i];
    }
    return nullptr;
}
void Piece::suppPerso(Personnage*p){
    if(tab[0]==p) {
        int j=0;
        for(unsigned int i = 1; i<NbPerso; i++) {
            tab[i-1] = tab[i];
            j= i;
        }
        tab[j] = nullptr;
    }
    else if(tab[1]==p) {
        int j=1;
        for(unsigned int i = 2; i<NbPerso; i++) {
            tab[i-1] = tab[i];
            j= i;
        }
        tab[j] = nullptr;
    }
    else if(tab[2]==p) {
        tab[2] = nullptr;
    }else{
        std::cout<<"erreur le perso n'appartient pas à la piece !\n";
    }
    NbPerso--;
}

bool Piece::isAsc() const {
    return asc;
}
void Piece::setAsc(){
    asc = true;
    Texture = ASC;
    niveau = 0;
    DimX = 1;
    type = ASC;
}
unsigned int Piece::getTexture() const {
    return Texture;
}
void Piece::setTexture(unsigned int tex){
    Texture = tex;
}
void Piece::setAllumer(bool elec){
    allumer=elec;
}
unsigned int Piece::getNiveau() const {
    return niveau;
}
void Piece::setNiveau(unsigned int niv){
    niveau = niv;
}
void Piece::setSelection(unsigned int s){
    selection = s;
}
unsigned int Piece::getSelection() const {
    return selection;
}
int Piece::getX() const {
    return x;
}
int Piece::getY() const {
    return y;
}
void Piece::setYX(int y_,int x_){
    y = y_;
    x = x_;
}
unsigned int Piece::getDimX() const {
    return DimX;
}
void Piece::setDimX(unsigned int DimX_){
    DimX = DimX_;
}

void Piece::setDest(bool b){
    destructible = b;
}
bool Piece::getDest() const {
    return destructible;
}

void Piece::setAgran(bool b){
    agrandissable = b;
}
bool Piece::getAgran() const {
    return agrandissable;
}

unsigned int Piece::getProduction() const {
    return 0;
}
unsigned int Piece::getType() const {
    return type;
}
unsigned int Piece::getNbPerso() const {
    return NbPerso;
}
void Piece::setNbPerso(unsigned int value){
    NbPerso = value;
}
void Piece::setAnim(int value){
    anim = value;
}
int Piece::getAnim() const {
    return anim;
}
unsigned int Piece::getPrix(int value) const {
    if (value < 1 || value >3) return 0;
    else return prix[value-1];
}

void Piece::testRegressionPiece(){
    //TEST: Piece type
    Personnage* Bart=new Personnage();
    //Bart->testRegression();
    Piece test=Piece(4,2);
    assert(test.y==4 && test.x==2 && test.niveau==1 && test.asc ==false);
    cout<<"constructeur piece OK";
    test.addPerso(Bart,1,1);
    assert(test.NbPerso==1);
    cout<<"OK add personnage dans piece";
    test.suppPerso(Bart);
    assert(test.NbPerso==0);
    cout<<"OK supp personnage de piece";

    //TEST: Pointeur
    Piece* test1=&test;
    assert(test1->y==4 && test1->x==2 && test1->niveau==1 && test1->asc ==false);
    cout<<"constructeur OK";
    test1->addPerso(Bart,1,1);
    assert(test1->NbPerso==1);
    cout<<"OK add personnage";
    test1->suppPerso(Bart);
    assert(test1->NbPerso==0);
    cout<<"OK supp personnage";
    delete Bart;
}
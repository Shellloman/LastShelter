#include "mouvement.h"

Mouvement::Mouvement(){
    pieces = nullptr;
    finexplo = false;
    fer = 0;
}
int Mouvement::getNb() const {
    return perso.size();
}
bool Mouvement::pathFinding(int yd, int xd,int ya, int xa,vector<int> &x,vector<int> &y){
    int dplx = xd; int dply = yd;
    if(dply != ya) {
        while(dplx<17 && !pieces[dplx+17*dply]->isAsc()) {
            x.push_back(dplx); y.push_back(dply);
            dplx++;
        }
        if (dplx==17) return false;
        while(dply<9 && pieces[dplx+17*dply]->isAsc() && dply != ya) {
            x.push_back(dplx); y.push_back(dply);
            if(dply < ya) dply++;
            else dply--;
        }
        if(dply != ya) return false;
        while(dplx != xa) {
            x.push_back(dplx); y.push_back(dply);
            if(dplx<xa) dplx++;
            else dplx--;
        }
        x.push_back(dplx); y.push_back(dply);
    }
    else{
        while(dplx != xa) {
            x.push_back(dplx); y.push_back(dply);
            if(dplx<xa) dplx++;
            else dplx--;
        }
        x.push_back(dplx); y.push_back(dply);
    }
    return true;
}
void Mouvement::setPtr(Piece **pieces_,Alerte* alerte_){
    pieces = pieces_;
    alerte = alerte_;
}
void Mouvement::update(int &ferraille){
    for(long unsigned int i = 0; i<perso.size(); i++) {
        if(perso[i]->dpl == 0) {
            if(etape[i] == int(x[i].size())-2) {
                perso[i]->resetSprite();
                piece[i]->addPerso(perso[i],y[i].back(),x[i].back());
                perso.erase(perso.cbegin()+i);
                piece.erase(piece.cbegin()+i);
                etape.erase(etape.cbegin()+i);
                x.erase(x.cbegin()+i);
                y.erase(y.cbegin()+i);
                return;
            }
            if (x[i][etape[i]]< x[i][etape[i]+1]) {
                perso[i]->setDeplacement(false);
                perso[i]->setDirection(1);
                perso[i]->dpl = 24;
            }else if(x[i][etape[i]]> x[i][etape[i]+1]) {
                perso[i]->setDeplacement(false);
                perso[i]->setDirection(0);
                perso[i]->dpl = -24;
            }else if(y[i][etape[i]]< y[i][etape[i]+1]) {
                perso[i]->dpl = 90;
            }else if(y[i][etape[i]]> y[i][etape[i]+1]) {
                perso[i]->dpl = -90;
            }
            etape[i]++;
            cout<<"étape deplacement : "<<etape[i]<<"sur "<<x[i].size()<<endl;
            cout<<"dpl : "<<perso[i]->dpl<<endl;
        }
        else{
            if (perso[i]->dpl>78 ) perso[i]->dpl--;
            else if (perso[i]->dpl>24) {
                if (perso[i]->dpl == 78 ) perso[i]->setDeplacement(true);
                perso[i]->setCo(0,perso[i]->getY()-5);
                if(perso[i]->dpl == 25 ) perso[i]->dpl = 0;
                else perso[i]->dpl--;
            }
            else if(perso[i]->dpl>0) {
                perso[i]->setCo(perso[i]->getX()+4);
                perso[i]->dpl--;
            }
            else if (perso[i]->dpl<-78) perso[i]->dpl++;
            else if (perso[i]->dpl<-24) {
                if (perso[i]->dpl == -78 ) perso[i]->setDeplacement(true);
                perso[i]->setCo(0,perso[i]->getY()+5);
                if(perso[i]->dpl == -25 ) perso[i]->dpl = 0;
                else perso[i]->dpl++;
            }
            else if(perso[i]->dpl<0) {
                perso[i]->setCo(perso[i]->getX()-4);
                perso[i]->dpl++;
            }
        }
    }
    for(long unsigned int i = 0; i<perso_explo.size(); i++) {
        if (temps_restant[i]<=0) {
            if(rand()%25 > int(perso_explo[i]->getForce() + perso_explo[i]->getAgilite()+
                               perso_explo[i]->getDegats()+perso_explo[i]->getArmure())) {
                piece_explo[i]->suppPerso(perso_explo[i]);
                alerte->addAlerte("L'exploration à echoue !",14);
            }else{
                perso_explo[i]->setDeplacement(false);
                fer = perso_explo[i]->getConcentration()*10 + 100;
                finexplo = true;
            }
            perso_explo.erase(perso_explo.cbegin()+i);
            piece_explo.erase(piece_explo.cbegin()+i);
            temps_restant.erase(temps_restant.cbegin()+i);
        }else
            temps_restant[i] -= 1;
    }
}
bool Mouvement::addPerso(Personnage* personnage,Piece *p,bool ext,int yd, int xd,int ya,int xa,int yp,int xp){
    vector<int> x2; vector<int> y2;
    if (!pathFinding(yd,xd,ya,xa,x2,y2)) {
        std::cout<<"pas de chemin trouvé\n";
        return false;
    }
    x2.push_back(xp); y2.push_back(yp);
    if(ext) personnage->setCo(308,2520);
    else{
        pieces[yd*17+xd]->suppPerso(personnage);
    }
    std::cout<<"chemin suivie : ";
    for(int i =0; i<int(x2.size()); i++) {
        std::cout<<"("<<y2[i]<<" , "<<x2[i]<<" ) -> ";
    }
    std::cout<<"fin\n";
    perso.push_back(personnage);
    piece.push_back(p);
    etape.push_back(0);
    x.push_back(x2);
    y.push_back(y2);
    return true;
}
vector<Personnage*> Mouvement::getPerso(){
    return perso;
}
void Mouvement::addExplo(Personnage *p,Piece *piece){
    p->setDeplacement(true);
    perso_explo.push_back(p);
    piece_explo.push_back(piece);
    temps_restant.push_back(60*5);
}
void Mouvement::setFin(bool value){
    finexplo = value;
}
bool Mouvement::getFin() const {
    return finexplo;
}
int Mouvement::getFer() const {
    return fer;
}
void Mouvement::clear(){
    perso.clear();
    piece.clear();
    etape.clear();
    y.clear();
    x.clear();
    perso_explo.clear();
    piece_explo.clear();
    temps_restant.clear();
}

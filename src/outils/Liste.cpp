#include "Liste.h"
#include <iostream>

Liste::Liste(){
    prem = nullptr;
    last = nullptr;
    nbelement = 0;
}
Liste::~Liste(){
    Cellule* tmp;
    while (prem != nullptr) {
        tmp = prem->suivant;
        //std::cout << prem->info<<" supprimé\n";
        delete prem;
        prem = tmp;
    }
}
void Liste::afficherGaucheDroite () const {
    Cellule *tmp = prem;
    while(tmp != nullptr) {
        std::cout<<"L : "<<tmp->info.y<<" "<<tmp->info.x<<"\n";
        tmp = tmp->suivant;
    }
}
void Liste::afficherDroiteGauche () const {
    Cellule *tmp = last;
    while(tmp != nullptr) {
        std::cout<<"L : "<<tmp->info.y<<" "<<tmp->info.x<<"\n";
        tmp = tmp->precedent;
    }
}
bool Liste::estVide () const {
    return (prem == nullptr && last == nullptr);
}
void Liste::ajouterEnTete (co e){
    if (prem ==nullptr) {
        prem = new Cellule;
        prem->info = e;
        prem->precedent = nullptr;
        prem->suivant = nullptr;
        last = prem;
    }
    else{
        Cellule* tmp = new Cellule;
        tmp->info = e;
        tmp->precedent = nullptr;
        tmp->suivant = prem;
        prem->precedent = tmp;
        prem = tmp;
    }
    nbelement++;
}
void Liste::ajouterEnQueue (co e){
    if (last ==nullptr) {
        last = new Cellule;
        last->info.x = e.x;
        last->info.y = e.y;
        last->precedent = nullptr;
        last->suivant = nullptr;
        prem = last;
    }
    else{
        Cellule* tmp = new Cellule;
        tmp->info.x = e.x;
        tmp->info.y = e.y;
        tmp->precedent = last;
        tmp->suivant = nullptr;
        last->suivant = tmp;
        last = tmp;
    }
    nbelement++;

}
void Liste::supprimerTete (){
    if (prem!=nullptr) {
        Cellule* tmp = prem;
        prem = prem->suivant;
        prem->precedent = nullptr;
        delete tmp;
        nbelement--;
    }
}
void Liste::vider (){
    Cellule* tmp;
    while (prem != nullptr) {
        tmp = prem->suivant;
        //std::cout << prem->info<<" supprimé\n";
        delete prem;
        prem = tmp;
    }
    last = nullptr;
    nbelement = 0;
}

unsigned int Liste::nbElements () const {
    return nbelement;
}
co Liste::iemeElement (unsigned int indice) const {
    if (prem==nullptr || indice < 0) {
        return co({-1,-1});
    }else{
        Cellule * tmp;
        if (indice <= nbelement/2) {
            tmp =prem;
            for (unsigned int i = 0; i < indice; i++) {
                tmp = tmp->suivant;
            }
        }else{
            tmp =last;
            for (unsigned int i = nbelement-1; i > indice; i--) {
                tmp = tmp->precedent;
            }
        }
        return tmp->info;
    }
}

void Liste::modifierIemeElement (unsigned int indice, co e){
    Cellule * tmp;
    if (indice <= nbelement/2) {
        tmp =prem;
        for (unsigned int i = 0; i < indice; i++) {
            tmp = tmp->suivant;
        }
    }else{
        tmp =last;
        for (unsigned int i = nbelement-1; i > indice; i--) {
            tmp = tmp->precedent;
        }
    }
    tmp->info = e;
}
Liste& Liste::operator = (const Liste & l){
    vider();
    Cellule *tmp;
    tmp = l.prem;
    while(tmp !=nullptr) {
        ajouterEnQueue(tmp->info);
        tmp = tmp->suivant;
    }
    return *(this);
}
co Liste::dernier() const {
    return last->info;
}

void Liste::sup(co e){
    Cellule *tmp = prem;
    while(tmp != nullptr) {
        if(tmp->info.x == e.x && tmp->info.y == e.y) {
            if (tmp == prem) {
                prem = tmp->suivant;
                if(nbelement > 1) prem->precedent = nullptr;
                else last = prem;
            }
            else if (tmp==last) { last = last->precedent; last->suivant = nullptr;}
            else{
                Cellule *tmps = tmp->suivant; Cellule *tmpp=tmp->precedent;
                tmps->precedent = tmp->precedent; tmpp->suivant = tmp->suivant;
            }
            delete tmp;
            --nbelement;
            break;
        }
        else tmp = tmp->suivant;
    }
}

bool Liste::estConstrcutible(co e) const {
    Cellule *tmp = prem;
    bool test = false;
    for(unsigned int i = 0; i<nbelement; ++i) {
        if(tmp->info.x == e.x && tmp->info.y == e.y) {
            test = true;
            break;
        }
        else tmp = tmp->suivant;
    }
    return test;
}

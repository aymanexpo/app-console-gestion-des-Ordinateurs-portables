// héritage multiple.cpp : This file contains the 'main' function. Program execution begins and ends there.
//application console de gestion de stock des ordinateurs portable par héritage multiple

#include <iostream>
#include<math.h>

using namespace std;

class ObjetAssure {
protected: 
    float montant;
    char* type;
public:
    ObjetAssure(float mnt, char* tp) {
        strcpy(this->type, tp);
        this->montant = mnt;
    }
    void afficher() {
        cout << " montant: " << this->montant << endl; 
        cout << " type: " << this->type << endl;
    }
};

class Ordinateur : public ObjetAssure{
protected:
    int ram; 
    int hd;
public:
    Ordinateur(int rm, int h, float mn , char* tp) : ObjetAssure(mn , tp){
        this->ram = rm;
        this->hd = h;
        this->montant = mn;
        strcpy(this->type, tp);
    }
    void arfficher(){
        cout << "ram : " << this->ram << "hd : " << this->hd << endl;
        ObjetAssure::afficher();
    }
};

class Bagage : public ObjetAssure{
protected:
    char* types;
    float poids;
public:
    Bagage(char* tp,float pd,float mn ,char* ty) : ObjetAssure(mn, ty){
        strcpy(this->types, tp);
        strcpy(this->type, ty);
        this->montant = mn;
        this->poids = pd;
    }
    void afficher() {
        ObjetAssure::afficher();
        cout << "type :" << this->types << "poids: " << this->poids << endl;
    }
};

class OrdinateurPortable : public Ordinateur, public Bagage{
protected:
    float poids;
    float epaisseur;
public:
    OrdinateurPortable(float pds, float eps, int rm, int h, float mn, char* tp, char* tpBag, float pd, float mnBag, char* ty) : Ordinateur(rm, h, mn,  tp) , Bagage( tpBag,  pd,  mnBag, ty){
        //------------------const this
        this->poids = pds;
        this->epaisseur = eps;
        //------------------const ord
        this->ram = rm;
        this->hd = h;
        OrdinateurPortable::Ordinateur::montant = mn;
        strcpy(OrdinateurPortable :: Ordinateur ::type,tp);
        strcpy(OrdinateurPortable::Bagage::type, tpBag);
        OrdinateurPortable::Bagage::poids = pd;
        OrdinateurPortable::Bagage::montant = mnBag;
        strcpy(OrdinateurPortable::Bagage::types, ty);
    }
    void afficher() {
        Ordinateur::afficher();
        Bagage::afficher();
        cout << "poids : " << this->poids << "epaisseurs : " << this->epaisseur << endl;
    }
};

int main()
{
    // Aymane Talibi
}


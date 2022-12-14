#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//#include <map>
//#include "usefull.hh"

typedef enum Pos {BU, DG, DD, AG, AD} Pos;
typedef enum Pied {Gauche, Droit} Pied;

class Footballeur{
private :
    std::string _nom;
    std::string _nationalite;
    int _age;

//  Stat   
    int _GEN; // Note General
    int _PAC; // VITESSE
    int _SHO; // TIR
    int _PAS; // PASSE
    int _DRI; // DRIBLES
    int _DEF; // DEFENSE
    int _PHY; // PHYSIQUE
    Pied _Pied_FOrt;
    int Gestes_tech;
    int _Pied_Faible;

    static int n_footballeur;

public:
//  Constructeurs 
    Footballeur (const FILE &f);
    Footballeur (const std::string & str); 
    Footballeur (const Footballeur &f);
//  Destructeur
    ~Footballeur();
//  Méthodes
    std::string normalize() const;


};

class Attaquant : public Footballeur{

private : 
    Pos _POS; // Position
    static int n_attaquant;
public:
//  Constructeurs
    Attaquant (const std::string &str);
    Attaquant (const FILE &f);
//  Destructeurs
    ~Attaquant ();
// Méthodes
    POS get_POS();
    std::string toString();
};

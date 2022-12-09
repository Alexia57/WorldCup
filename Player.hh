#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//#include <map>
//#include "usefull.hh"

typedef enum POS {BU, DG, DD, AG, AD} POS;

class Footballeur{
private :
    std::string _nom;
    std::string _nationalite;
    int _age;
//  Stat   
    int _PAC; // VIT
    int _SHO; // TIR
    int _PAS; // PASSE
    int _DRI; // DRIBBLES
    int _DEF; // DEFENSE
    int _PHY; // PHYSIQUE

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
    POS _POS; // Position
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

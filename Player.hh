#pragma once

#include <string>
#include <vector>
#include <map>
#include "usefull.hh"

class Molecule{
public:
// Constructeurs 
    Molecule (const string &forme_eclate); 
// Destructeur
// Méthodes
    string normalize() const;

private:
    vector<string> vect_forme_eclate;
};

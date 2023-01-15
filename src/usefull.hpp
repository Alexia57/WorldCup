#pragma once

#include <list>
#include <iostream>
#include "Question.hpp"
#include "../lib/pugixml/pugixml.hpp"
#include <vector>

// compare si 2 listes sont identiques et return true si oui
bool compare_lists(std::list<std::string> lst1, std::list<std::string> lst2);

// fonction pour récupérer les données d'un fichier XML dans des variables de la classe Question
std::vector<Question> parseXML(const std::string& fileName);
#ifndef USEFUL_HPP
#define USEFUL_HPP

#include <iostream>
#include <vector>
#include <list>

#include <cmath> //round
#include <SFML/Graphics.hpp>

#include "Question.hpp"
#include "../lib/pugixml/pugixml.hpp"


// compare si 2 listes sont identiques et return true si oui
bool compare_lists(std::list<std::string> lst1, std::list<std::string> lst2);

// fonction pour récupérer les données d'un fichier XML dans des variables de la classe Question
void parseXML(const std::string& fileName, std::list<Question> &questions);

class Useful {
public:
    static void setTxt(sf::Text& txt, sf::String string, sf::Font& font, int charSize, int x, int y)
    {
        txt.setString(string);
        txt.setFont(font);
        txt.setCharacterSize(charSize);
        txt.setOrigin(round(txt.getGlobalBounds().width / 2.f), round(txt.getGlobalBounds().height / 2.f));
        txt.setPosition(sf::Vector2f(x,y));
    }
};


#endif /* USEFUL_HPP */
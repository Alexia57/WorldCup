#ifndef USEFUL_HPP
#define USEFUL_HPP

#include <iostream>
#include <vector>
#include <list>

#include <cmath> //round
#include <SFML/Graphics.hpp>
#include <sys/stat.h>

#include "Question.hpp"
#include "../lib/pugixml/pugixml.hpp"


// compare si 2 listes sont identiques et return true si oui
bool compare_lists(std::list<std::string> lst1, std::list<std::string> lst2);

// fonction pour récupérer les données d'un fichier XML dans des variables de la classe Question
void parseXML(const std::string& fileName, std::list<Question> &questions);

// Convertit un std::string codé en UTF8 en sf::String en UTF32
sf::String UTF8_to_UTF32(std::string str);

inline bool exists (const std::string& name) {
  struct stat buffer;   
  return (stat (name.c_str(), &buffer) == 0); 
}

class Useful {
public:
    static void setTxt(sf::Text& txt, std::string string, sf::Font& font, int charSize, int x, int y, sf::Vector2f &dimBox)
    {
        txt.setString(UTF8_to_UTF32(string));
        txt.setFont(font);
        txt.setCharacterSize(charSize);
        txt.setOrigin(round(txt.getGlobalBounds().width / 2.f), round(txt.getGlobalBounds().height / 2.f));
        txt.setPosition(sf::Vector2f(x,y));

        resizeTxt(txt, charSize, x, y, dimBox);
    }

    static void resizeTxt(sf::Text& txt, int charSize, int x, int y,sf::Vector2f &dimBox)
    {
        sf::FloatRect txtRect = txt.getGlobalBounds();
        int cSize = charSize;
        while(txtRect.left < 0 || txtRect.top < 0 || txtRect.top+txtRect.height > dimBox.y 
            || txtRect.left+txtRect.width > dimBox.x){
            cSize -= 3;
            if(cSize < 5)
                break;
            txt.setCharacterSize(cSize);
            txtRect = txt.getGlobalBounds();
            txt.setOrigin(round(txtRect.width / 2.f), round(txtRect.height / 2.f));
            txt.setPosition(sf::Vector2f(x,y));
        }
    }
};


#endif /* USEFUL_HPP */
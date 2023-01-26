#ifndef USEFUL_HPP
#define USEFUL_HPP

#include <iostream>
#include <vector>
#include <list>

#include <cmath> //round
#include <SFML/Graphics.hpp>
//#include <sys/stat.h>
#include <fstream>
#include <string>

#include "Question.hpp"
#include "../lib/pugixml/pugixml.hpp"


// This function compares two vectors of strings and returns true if they are identical
bool isEqual_vectString(std::vector<std::string> vect1, std::vector<std::string> vect2);

// This function retrieves data from an XML file and stores it in variables of the Question class
void parseXML(const std::string& fileName, std::list<Question> &questions);

// This function converts a string encoded in UTF8 to an sf::String encoded in UTF32
sf::String UTF8_to_UTF32(std::string str);

/* inline bool exists (const std::string& name) {
  struct stat buffer;   
  return (stat (name.c_str(), &buffer) == 0); 
} */

// this function check if a file with the given name exist.
inline bool exists (const std::string& name) {
    std::ifstream f(name.c_str());
    return f.good();
}

//  function that returns a vector of strings containing the names of files in a directory that match a specific pattern.
std::vector<std::string> getFileNames(const std::string &pathDir, const std::string &pattern);

// function that prints the properties of an SFML FloatRect object.
void printRect(sf::FloatRect rect);

class Useful {
public:
    // This function sets various properties of an SFML Text object, such as its string, font, character size, position, and color.
    static void setTxt(sf::Text& txt, std::string string, sf::Font& font, int charSize, int x, int y, 
                       sf::Vector2f &dimBox, const sf::Color& color = sf::Color(200,180,180))
    {
        txt.setString(UTF8_to_UTF32(string));
        txt.setFont(font);
        txt.setCharacterSize(charSize);
        txt.setOrigin(round(txt.getGlobalBounds().width / 2.f), round(txt.getGlobalBounds().height / 2.f));
        txt.setPosition(sf::Vector2f(x,y));
        txt.setFillColor(color);

        resizeTxt(txt, charSize, x, y, dimBox);
    }

    // This function resizes an SFML Text object until it fits within a specified box.
    static void resizeTxt(sf::Text& txt, int charSize, int x, int y,sf::Vector2f &dimBox)
    {
        sf::FloatRect txtRect = txt.getGlobalBounds();
        int cSize = charSize;
        while(txtRect.left < 0 || txtRect.top < 0 || txtRect.top+txtRect.height > dimBox.y 
            || txtRect.left+txtRect.width > dimBox.x*0.95){
            cSize -= 3;
            if(cSize < 5)
                break;
            txt.setCharacterSize(cSize);
            txtRect = txt.getGlobalBounds();
            txt.setOrigin(round(txtRect.width / 2.f), round(txtRect.height / 2.f));
            txt.setPosition(sf::Vector2f(x,y));
        }
    }

    // Return min of a & b
    static float min(float a, float b){
        return (a < b)? a : b;
    }

    // Return max of a & b
    static float max(float a, float b){
        return (a > b)? a : b;
    }
};


#endif /* USEFUL_HPP */
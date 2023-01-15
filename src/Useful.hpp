#ifndef USEFUL_HPP
#define USEFUL_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath> //round

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
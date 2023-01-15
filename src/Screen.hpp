#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <SFML/Graphics.hpp>


class Screen 
{
public:
    sf::Font *_font;
    Screen(sf::Font *font);
    virtual ~Screen(){};
    virtual Screen* HandleEvent(sf::RenderWindow& window, sf::Event &event) = 0;
    virtual void Update(sf::RenderWindow& window) = 0;
    virtual void Draw(sf::RenderWindow& window) = 0;
};

#endif /* SCREEN_HPP */
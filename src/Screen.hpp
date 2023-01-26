#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <SFML/Graphics.hpp>

/* Virtual class for all the screen of the application */
class Screen 
{
public:
    
    sf::Font *_font; // font used for the txt in the screen.

    // Constructor
    Screen(sf::Font *font);
    // Destructor
    virtual ~Screen(){};

    // This function handles events such as mouse clicks
    virtual void HandleEvent(sf::RenderWindow& window, sf::Event &event) = 0;
    // This function updates the logic of the screen
    virtual Screen* Update(sf::RenderWindow& window) = 0;
    // This function draws the elements of the screen
    virtual void Draw(sf::RenderWindow& window) = 0;
};

#endif /* SCREEN_HPP */
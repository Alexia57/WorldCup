#ifndef APPLICATION_HPP
#define APPLICATION_HPP

//#include <SFML/Graphics.hpp>
//#include "Screen.hpp"
#include <SFML/Graphics.hpp>
#include "Menu.hpp"
#include "Quizz.hpp"

class Application 
{
private:
    // Font used for text in the application
    sf::Font _font;
    // Texture for the background image
    sf::Texture _texture;
    // Sprite for the background image
    sf::Sprite _background;

    // constructor
    Application(sf::RenderWindow& window);
    
    // main game loop
    void Loop(sf::RenderWindow& window);
    // handle events
    void HandleEvent(sf::RenderWindow& window, Screen& currentScreen);
    // update the current screen
    Screen* Update(sf::RenderWindow& window, Screen& currentScreen);
    // draw the current screen
    void Draw(sf::RenderWindow& window, Screen& currentScreen);
    

public:
    //initialize the application
    static Application& initialize(sf::RenderWindow& window); 
    // run the application
    void Run(sf::RenderWindow& window);
};


#endif /* APPLICATION_HPP */
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
    sf::Font _font;
    

    Application(sf::RenderWindow& window);
    
    void Loop(sf::RenderWindow& window);
    void HandleEvent(sf::RenderWindow& window, Screen& currentScreen);
    Screen* Update(sf::RenderWindow& window, Screen& currentScreen);
    void Draw(sf::RenderWindow& window, Screen& currentScreen);
    

public:
    static Application& initialize(sf::RenderWindow& window); 
    void Run(sf::RenderWindow& window);

};


#endif /* APPLICATION_HPP */
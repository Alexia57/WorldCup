#include <iostream>
#include "Application.hpp"


int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "MENU");

    Application app = Application::initialize(window);


    app.Run(window);

    return 0;
}
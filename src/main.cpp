#include <iostream>
#include "Application.hpp"


int main()
{
    // create a window with a size of 1600x900 and a title of "MENU"
    sf::RenderWindow window(sf::VideoMode(1600, 900), "MENU");

    // initialize the application
    Application app = Application::initialize(window);

    // run the application
    app.Run(window);

    return 0;
}
#include "Page.hpp"


// initialiser page
void Page::initialize()
{
    _page.setVerticalSyncEnabled(true);
    _page.setPosition(sf::Vector2i(190,50));
    _page.setFramerateLimit(60);
    _page.clear(sf::Color::Black);
}

// afficher page
void Page::display()
{
    _page.display();
}

// fermer page
void Page::close()
{
    _page.close();
    
}
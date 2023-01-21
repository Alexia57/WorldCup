#ifndef MENU_HPP
#define MENU_HPP

#include "Screen.hpp"
#include "Button.hpp"

class Menu : public Screen
{
private:
    // Text object to display the menu title
    sf::Text _menuText;
    // Button object for the first option
    Button _option1;
    // Button object for the 2nd option
    Button _option2;

public:
    // constructor
    Menu(sf::RenderWindow& window, sf::Font *font);
    //destructor
    ~Menu() override;

    //overridden method to handle events for the menu screen
    void HandleEvent(sf::RenderWindow& window,sf::Event &event) override;
    //overridden method to update the menu screen
    Screen* Update(sf::RenderWindow& window) override;
    //overridden method to draw the menu screen
    void Draw(sf::RenderWindow& window) override;
};

#endif /* MENU_HPP */
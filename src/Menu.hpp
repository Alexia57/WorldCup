#ifndef MENU_HPP
#define MENU_HPP

#include "Screen.hpp"
#include "Button.hpp"

class Menu : public Screen
{
private:
    // Object to display the menu title
    sf::Text _menuText;
    sf::Text _introText;
    sf::Texture _texture;
    sf::Sprite _sprite;

    // Button object for the options
    Button _option1;
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
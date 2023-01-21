#ifndef MENU_HPP
#define MENU_HPP

#include "Screen.hpp"
#include "Button.hpp"

class Menu : public Screen
{
private:
    sf::Text _menuText;
    sf::Text _introText;
    Button _option1;
    Button _option2;

public:
    Menu(sf::RenderWindow& window, sf::Font *font);
    ~Menu() override;
    void HandleEvent(sf::RenderWindow& window,sf::Event &event) override;
    Screen* Update(sf::RenderWindow& window) override;
    void Draw(sf::RenderWindow& window) override;
};

#endif /* MENU_HPP */
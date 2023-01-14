#ifndef MENU_HPP
#define MENU_HPP

#include "Screen.hpp"
#include "Button.hpp"

class Menu : public Screen
{
private:
    int _selectedOption = 0;
    sf::Text _menuText;
    Button _option1;
    Button _option2;

public:
    Menu(sf::RenderWindow& window, sf::Font *font);
    ~Menu() override;
    Screen* HandleEvent(sf::RenderWindow& window,sf::Event &event) override;
    void Update(sf::RenderWindow& window) override;
    void Draw(sf::RenderWindow& window) override;
};

#endif /* MENU_HPP */
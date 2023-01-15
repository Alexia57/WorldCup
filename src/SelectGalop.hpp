#ifndef SELECTGALOP_HPP
#define SELECTGALOP_HPP

#include "Screen.hpp"
#include "Button.hpp"

class SelectGalop : public Screen
{
private:
    int _selectedOption = 0;
    sf::Text _Title;
    Button _galop[7];

public:
    SelectGalop(sf::RenderWindow& window, sf::Font *font);
    ~SelectGalop() override;
    void HandleEvent(sf::RenderWindow& window,sf::Event &event) override;
    Screen* Update(sf::RenderWindow& window) override;
    void Draw(sf::RenderWindow& window) override;
};

#endif /* SELECTGALOP_HPP */
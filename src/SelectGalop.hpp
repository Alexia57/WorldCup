#ifndef SELECTGALOP_HPP
#define SELECTGALOP_HPP

#include "Screen.hpp"
#include "Button.hpp"

class SelectGalop : public Screen
{
private:
    int _selectedOption = 0; // store the current selection (default Nothing)
    sf::Text _Title; // text Title
    Button _galop[7]; // button for the selection
    int _option; // stores the option passed in the constructor.

public:
    SelectGalop(sf::RenderWindow& window, sf::Font *font, int option);
    ~SelectGalop() override;

    // function to handle events
    void HandleEvent(sf::RenderWindow& window,sf::Event &event) override;
    // function to update the screen
    Screen* Update(sf::RenderWindow& window) override;
    // function to draw the elements on the screen
    void Draw(sf::RenderWindow& window) override;
};

#endif /* SELECTGALOP_HPP */
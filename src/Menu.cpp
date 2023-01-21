#include <iostream>
#include "Menu.hpp"
#include "SelectGalop.hpp"
#include "Useful.hpp"
#include <string>
#include <vector>

Menu::Menu(sf::RenderWindow& window, sf::Font *font) : Screen(font)
{
    // get the size of the window
    sf::Vector2f wSize(window.getSize().x,window.getSize().y);

    // set the title of the window to "Menu"
    window.setTitle("Menu");
    // set the text for the main menu title
    Useful::setTxt(_menuText, "Menu", *font, 60, wSize.x/2, wSize.y/5, wSize);

    // set the size and position of the buttons
    sf::Vector2f size(250.f,100.f);
    sf::Vector2f position1(wSize.x/4.f, wSize.y*3/5.f);
    sf::Vector2f position2(wSize.x*3/4.f, wSize.y*3/5.f);
    // set the default and hover colors for the buttons
    sf::Color    grey(150, 150, 150);
    sf::Color    red(255, 100, 100);

    // set the properties for the first button
    _option1.Setting(size, position1, grey, red, "Révision", *font);
    // set the properties for the 2nd button
    _option2.Setting(size, position2, grey, red, "QUIZZ", *font);

    //Useful::setTxt(_option1, "Option 1", *font, 40, wSize.x/4, wSize.y*3/5);
    //Useful::setTxt(_option2, "Option 2", *font, 40, wSize.x*3/4, wSize.y*3/5);
}

Menu::~Menu()
{
    // destructor
}

void Menu::HandleEvent(sf::RenderWindow& window,sf::Event &event)
{   
    // handle events for the buttons
    _option1.HandleEvent(event);
    _option2.HandleEvent(event);
}

Screen* Menu::Update(sf::RenderWindow& window)
{
    if(_option2.isHover()){
        // if the 2nd button is hovered, create a new SelectGalop screen with the quizz option
        SelectGalop* screen = new SelectGalop(window, _font, 2);
        return screen;
    }

     if(_option1.isHover()){
        // if the first button is hovered, create a new SelectGalop screen with the revision option
        SelectGalop* screen = new SelectGalop(window, _font, 1);
        return screen;
    }
    
    // if neither buttons are hovered, return the current screen
    return this;
}

void Menu::Draw(sf::RenderWindow& window)
{
    // draw the menu title
    window.draw(_menuText);
    // draw the first button
    _option1.Draw(window);
    // draw the 2nd button
    _option2.Draw(window);
}
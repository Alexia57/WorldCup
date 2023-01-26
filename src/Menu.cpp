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
    Useful::setTxt(_menuText, "Direction Coupe du Monde !", *font, 44, wSize.x*0.49, wSize.y*1/6, wSize);
    _menuText.setStyle(sf::Text::Bold);
    Useful::setTxt(_introText, "Obtenez votre galop 7 en un rien de temps :)", *font, 29, wSize.x/2, wSize.y*3/12, wSize);

    // set the size and position of the buttons
    sf::Vector2f size(250.f,100.f);
    sf::Vector2f position1(wSize.x/4.f, wSize.y*2/3.f);
    sf::Vector2f position2(wSize.x*3/4.f, wSize.y*2/3.f);

    // set the properties for the buttons
    _option1.Setting(size, position1, "Révision", *font);
    _option2.Setting(size, position2, "QUIZZ", *font);

    // set a sprite for the text
    _texture.loadFromFile("assets/images/pancarte.png");
    _sprite.setTexture(_texture);
    sf::FloatRect rect = _sprite.getLocalBounds();
    sf::Vector2f pos(wSize.x/2, wSize.y/6);
    _sprite.setScale(wSize.x*0.5/rect.width, wSize.y*0.35/rect.height);
    _sprite.setOrigin(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);
    _sprite.setPosition(pos);
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
    window.draw(_sprite);
    window.draw(_menuText);
    window.draw(_introText);
    
    // draw the first button
    _option1.Draw(window);
    // draw the 2nd button
    _option2.Draw(window);
}
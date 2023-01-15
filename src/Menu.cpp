#include <iostream>
#include "Menu.hpp"
#include "SelectGalop.hpp"
#include "Useful.hpp"
#include <string>
#include <vector>

Menu::Menu(sf::RenderWindow& window, sf::Font *font) : Screen(font)
{
    sf::Vector2f wSize(window.getSize().x,window.getSize().y);

    Useful::setTxt(_menuText, "Menu", *font, 60, wSize.x/2, wSize.y/5);

    sf::Vector2f size(250.f,100.f);
    sf::Vector2f position1(wSize.x/4.f, wSize.y*3/5.f);
    sf::Vector2f position2(wSize.x*3/4.f, wSize.y*3/5.f);
    sf::Color    grey(150, 150, 150);
    sf::Color    red(255, 100, 100);

    _option1.Setting(size, position1, grey, red, "Option 1", *font);
    _option2.Setting(size, position2, grey, red, "QUIZZ", *font);

    //Useful::setTxt(_option1, "Option 1", *font, 40, wSize.x/4, wSize.y*3/5);
    //Useful::setTxt(_option2, "Option 2", *font, 40, wSize.x*3/4, wSize.y*3/5);
}

Menu::~Menu()
{

}

void Menu::HandleEvent(sf::RenderWindow& window,sf::Event &event)
{   
    _option1.HandleEvent(event);
    _option2.HandleEvent(event);
    /* if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && _selectedOption > -1) {
        _selectedOption = 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && _selectedOption < 2) {
        _selectedOption = 2;
    } */
}

Screen* Menu::Update(sf::RenderWindow& window)
{
    //_option1.setFillColor(sf::Color::White);
    //_option2.setFillColor(sf::Color::White);
    if(_option2.isHover()){
        SelectGalop* screen = new SelectGalop(window, _font);
        return screen;
    }

    return this;
       
    /* switch (_selectedOption) {
        case 1:
            _option1.setFillColor(sf::Color::Red);
            break;
        case 2:
            _option2.setFillColor(sf::Color::Red);
            break;
        default:
            break;
    } */
}

void Menu::Draw(sf::RenderWindow& window)
{
    window.draw(_menuText);
    
    _option1.Draw(window);
    _option2.Draw(window);
    
    //window.draw(_option1);
    //window.draw(_option2);
}
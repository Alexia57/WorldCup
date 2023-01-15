#include "SelectGalop.hpp"
#include "Quizz.hpp"
#include "Useful.hpp"
#include <string>

SelectGalop::SelectGalop(sf::RenderWindow& window, sf::Font *font) : Screen(font)
{
    sf::Vector2f wSize(window.getSize().x,window.getSize().y);

    
    Useful::setTxt(_Title, "Sélection du Galop à tester :", *font, 60, wSize.x/2, wSize.y/7, wSize);

    sf::Vector2f size(200.f,80.f);
    sf::Color    grey(150, 150, 150);
    sf::Color    red(255, 100, 100);

    for(int row = 0; row < 2; row++){
        for(int col = 0; col < 3; col++){
            sf::Vector2f position1(wSize.x*(col+1)/4.f, wSize.y*(row+2)/5.f);
            _galop[row*3+col].Setting(size, position1, grey, red, "Galop "+std::to_string(row*3+col+1), *font);
        }
    }

    sf::Vector2f pos(wSize.x/2.f, wSize.y*4/5.f);
    _galop[6].Setting(size, pos, grey, red, "Galop 7", *font);
}

SelectGalop::~SelectGalop()
{

}

void SelectGalop::HandleEvent(sf::RenderWindow& window,sf::Event &event)
{   
    for(int i = 0; i < 7; i++)
        _galop[i].HandleEvent(event);
}

Screen* SelectGalop::Update(sf::RenderWindow& window)
{
    for(int i = 0; i < 7; i++){
        if(_galop[i].isHover()){
        
            Quizz* screen = new Quizz(window, _font, i+1);
            return screen;
        }
    }

    return this;
}

void SelectGalop::Draw(sf::RenderWindow& window)
{
    window.draw(_Title);

    for(int i = 0; i < 7; i++)
        _galop[i].Draw(window);
    
}
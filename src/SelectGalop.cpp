#include "SelectGalop.hpp"
#include "Quizz.hpp"
#include "Useful.hpp"

SelectGalop::SelectGalop(sf::RenderWindow& window, sf::Font *font) : Screen(font)
{
    sf::Vector2f wSize(window.getSize().x,window.getSize().y);

    Useful::setTxt(_Title, "Sélection du Galop à tester :", *font, 60, wSize.x/2, wSize.y/6);

    sf::Vector2f size(250.f,100.f);
    sf::Color    grey(150, 150, 150);
    sf::Color    red(255, 100, 100);

    for(int i = 0; i < 3; i++){
        sf::Vector2f position1(wSize.x/3.f, wSize.y*(i+2)/6.f);
        sf::Vector2f position2(wSize.x*2/3.f, wSize.y*(i+2)/6.f);
        _galop[i*2  ].Setting(size, position1, grey, red, "Galop "+std::to_string(i*2+1), *font);
        _galop[i*2+1].Setting(size, position2, grey, red, "Galop "+std::to_string(i*2+2), *font);
    }

    sf::Vector2f pos(wSize.x/2.f, wSize.y*5/6.f);
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
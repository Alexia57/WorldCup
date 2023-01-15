#include <iostream>
#include "Quizz.hpp"
#include "Useful.hpp"

Quizz::Quizz(sf::RenderWindow& window, sf::Font *font, sf::String question, sf::String *proposition, int sizeProp):Screen(font)
{
    _sizeProp = sizeProp;
    _proposition = new sf::Text[sizeProp];
    
    sf::Vector2f wSize(window.getSize().x,window.getSize().y);
    int nLine = _sizeProp/3 + (_sizeProp%3 != 0);
    
    Useful::setTxt(_question, question, *font, 60, wSize.x/2, wSize.y/(nLine+2));
    
    
    for(int line = 0; line < nLine; line++){
        
        int ncol = (line == nLine-1) ? _sizeProp%3 : 3;
        for(int i = 0; i < ncol; i++){
            Useful::setTxt(_proposition[line*3+i], proposition[line*3+i], *font, 40, wSize.x*(i+1)/(ncol+1), wSize.y*(line+2)/(nLine+2));
        }  
    }
}

Quizz::~Quizz()
{
    delete [] _proposition;
}

Screen* Quizz::HandleEvent(sf::RenderWindow& window,sf::Event &event)
{   
    //std::cout << "Quizz Event\n";
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && _selectedOption > 0) {
        _selectedOption = 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && _selectedOption < 2) {
        _selectedOption = 2;
    }
    return this;
}

void Quizz::Update(sf::RenderWindow& window)
{
    _question.setFillColor(sf::Color::White);
    
    for(int i = 0; i < _sizeProp; i++)
        _proposition[i].setFillColor(sf::Color::White);


    /* switch (_selectedOption) {
        case 1:
            option1.setFillColor(sf::Color::Red);
            break;
        case 2:
            option2.setFillColor(sf::Color::Red);
            break;
        default:
            break;
    } */
}

void Quizz::Draw(sf::RenderWindow& window)
{
    window.draw(_question);

    for(int i = 0; i < _sizeProp; i++)
        window.draw(_proposition[i]);
}
#include <iostream>
#include <list>
#include <vector>

#include "Quizz.hpp"
#include "Useful.hpp"



Quizz::Quizz(sf::RenderWindow& window, sf::Font *font, int galop) : Screen(font)
{
    _galop = galop;
    
    std::string pathQuestions= "assets/questions/g" + std::to_string(galop) + ".xml";
    parseXML(pathQuestions, _questions);


    //Print first question
    _sizeProp = _questions.front().get_propositions().size();
    _buttonProp = new Button[_sizeProp];

    sf::Vector2f wSize(window.getSize().x,window.getSize().y);

    if(_questions.front().isImage() == 0){
        int nLine = _sizeProp/2 + (_sizeProp%2 != 0);
        Useful::setTxt(_txtQuestion, _questions.front().get_question(), *font, 60, wSize.x/2, wSize.y/(nLine+2));
        
        sf::Vector2f size(250.f,100.f);
        sf::Color    grey(150, 150, 150);
        sf::Color    red(255, 100, 100);

        std::vector<std::string> *prop = &(_questions.front().get_propositions());

        for(int line = 0; line < nLine; line++){
            int ncol = (line == nLine-1 && _sizeProp%2!=0) ? _sizeProp%2 : 2;

            for(int i = 0; i < ncol; i++){
                sf::Vector2f pos(wSize.x*(i+1)/(ncol+1), wSize.y*(line+2)/(nLine+2));
                _buttonProp[line*2+i].Setting(size, pos, grey, red, (*prop)[line*2+i], *font);
            }  
        }
    }  
}

Quizz::~Quizz()
{
    delete [] _buttonProp;
}

void Quizz::HandleEvent(sf::RenderWindow& window,sf::Event &event)
{   
    for(int i = 0; i < _sizeProp; i++)
        _buttonProp[i].HandleEvent(event);
}

Screen* Quizz::Update(sf::RenderWindow& window)
{
    
    for(int i = 0; i < _sizeProp; i++){
        if(_buttonProp[i].isHover()){
            break;
            // Not implemented
        }
            
    }

    return this;
}

void Quizz::Draw(sf::RenderWindow& window)
{
    window.draw(_txtQuestion);

    for(int i = 0; i < _sizeProp; i++)
        _buttonProp[i].Draw(window);
}
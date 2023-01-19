#include <iostream>
#include <list>
#include <vector>
#include <string>

#include "Menu.hpp"
#include "Quizz.hpp"
#include "Useful.hpp"

Quizz::Quizz(sf::RenderWindow& window, sf::Font *font, int galop) : Screen(font)
{
    _galop = galop;
    _numQuestion = 1;
    
    std::string pathQuestions= "assets/questions/g" + std::to_string(galop) + ".xml";
    parseXML(pathQuestions, _questions);
    
    RunQuestion(window);
}

Quizz::~Quizz()
{
    delete [] _buttonProp;
}

void Quizz::RunQuestion(sf::RenderWindow& window)
{
    _sizeProp = _questions.front().get_propositions().size();
    if(_numQuestion != 1) { delete [] _buttonProp; }
    _buttonProp = new Button[_sizeProp];

    sf::Vector2f wSize(window.getSize().x,window.getSize().y);

    
    std::string imgPath = "assets/images/q" + std::to_string(_galop) + std::to_string(_numQuestion) + ".png";
    _isImg = exists(imgPath);

    if(_isImg){
        _imgTexture.loadFromFile(imgPath);
        _imgSprite.setTexture(_imgTexture);
    }

    if(_questions.front().isImage() == 0){
        /* int nLine = _sizeProp/2 + (_sizeProp%2 != 0);
        Useful::setTxt(_txtQuestion, _questions.front().get_question(), *_font, 60, wSize.x/2, wSize.y/(nLine+2), wSize);
        
        sf::Vector2f size(250.f,100.f);
        sf::Color    grey(150, 150, 150);
        sf::Color    red(255, 100, 100);

        std::vector<std::string> *prop = &(_questions.front().get_propositions());

        for(int line = 0; line < nLine; line++){
            int ncol = (line == nLine-1 && _sizeProp%2!=0) ? _sizeProp%2 : 2;

            for(int i = 0; i < ncol; i++){
                sf::Vector2f pos(wSize.x*(i+1)/(ncol+1), wSize.y*(line+2)/(nLine+2));
                _buttonProp[line*2+i].Setting(size, pos, grey, red, (*prop)[line*2+i], *_font);
            }  
        } */

        int nLine = _sizeProp + 1;
        Useful::setTxt(_txtQuestion, _questions.front().get_question(), *_font, 60, wSize.x/2, wSize.y*0.5/(nLine+1), wSize);
        
        sf::Vector2f size(wSize.x*0.65,wSize.y*0.65/(nLine+1));
        sf::Color    grey(150, 150, 150);
        sf::Color    red(255, 100, 100);

        std::vector<std::string> *prop = &(_questions.front().get_propositions());

        for(int i = 0; i < _sizeProp; i++){
            sf::Vector2f pos(wSize.x/2, wSize.y*(i+1.8)/(nLine+1));
            _buttonProp[i].Setting(size, pos, grey, red, (*prop)[i], *_font);
        }
    }
}

void Quizz::RunAnswer(sf::RenderWindow& window, bool goodAnswer)
{
    _isAnswer = 1;

    sf::Vector2f wSize(window.getSize().x,window.getSize().y);
    std::string txt;

    if(goodAnswer)
        txt = "Bravo !";
    else
        txt = "Mauvaise réponse : la solution est \"" + _questions.front().get_answer() + "\"";

    Useful::setTxt(_answer, txt, *_font, 40, wSize.x/2, wSize.y*(1.1)/(_sizeProp+2), wSize);
    
    sf::Vector2f size(wSize.x*0.14,wSize.y*0.5/(_sizeProp+2));
    sf::Vector2f pos(wSize.x*0.92, wSize.y*(_sizeProp+1.6)/(_sizeProp+2));
    sf::Color    grey(150, 150, 150);
    sf::Color    red(255, 100, 100);
    _next.Setting(size, pos, grey, red, "Suivant", *_font);
    _next.turnOn();
}

void Quizz::RunScore(sf::RenderWindow& window)
{
    _isScore = 1;
    _isImg = 0;

    //reset
    _next.turnOff();
    _next.turnOn();

    sf::Vector2f wSize(window.getSize().x,window.getSize().y);
    std::string txt = "Score : " + std::to_string(_score) + " bonne(s) réponse(s) sur ";
    txt += std::to_string(_numQuestion) + " questions";

    Useful::setTxt(_txtQuestion, "RESULTAT", *_font, 60, wSize.x/2, wSize.y/8, wSize);
    Useful::setTxt(_txtScore, txt, *_font, 40, wSize.x/2, wSize.y*3/8, wSize);
}

void Quizz::HandleEvent(sf::RenderWindow& window,sf::Event &event)
{   
    for(int i = 0; i < _sizeProp; i++)
        _buttonProp[i].HandleEvent(event);

    if(_isAnswer || _isScore)
        _next.HandleEvent(event);
}

Screen* Quizz::Update(sf::RenderWindow& window)
{
    if(_isAnswer == false && _isScore == false){
        for(int i = 0; i < _sizeProp; i++){
            if(_buttonProp[i].isHover()){
                if(_questions.front().get_propositions()[i] == _questions.front().get_answer()){
                    _buttonProp[i].setDefaultColor(sf::Color(100, 255, 100));
                    RunAnswer(window,1);
                    _score++;
                }else{
                    _buttonProp[i].setDefaultColor(sf::Color(255, 100, 100));
                    RunAnswer(window,0);
                }

                for(int j = 0; j < _sizeProp; j++)
                    _buttonProp[j].turnOff();

                break;
            }       
        }
    }else if(_isAnswer){

        if(_next.isHover()){
            _questions.pop_front();
            _isAnswer = false;

            if(_questions.size() != 0){
                _numQuestion++;
                RunQuestion(window);
                _next.turnOff();
            }else{
                RunScore(window);
            }
        }
    }else if(_isScore){

        if(_next.isHover()){
            Menu *screen = new Menu(window, _font);
            return screen;
        }
        
    }

    return this;
}

void Quizz::Draw(sf::RenderWindow& window)
{
    window.draw(_txtQuestion);

    if(_isImg)
        window.draw(_imgSprite);

    if(_isScore == 0){
        for(int i = 0; i < _sizeProp; i++)
        _buttonProp[i].Draw(window);

        if(_isAnswer){
            window.draw(_answer);
            _next.Draw(window);
        }
    }

    if(_isScore){
        _next.Draw(window);
        window.draw(_txtScore);
    }
}
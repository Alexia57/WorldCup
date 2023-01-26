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
    
    window.setTitle("Quizz");
    std::string pathQuestions= "assets/questions/g" + std::to_string(galop) + ".xml";
    parseXML(pathQuestions, _questions);
    
    _imgSprite = new sf::Sprite;
    RunQuestion(window);
}

Quizz::~Quizz()
{
    delete _imgSprite;
    delete [] _buttonProp;
}

void Quizz::RunQuestion(sf::RenderWindow& window)
{
    // Get the number of propositions for the current question
    _sizeProp = _questions.front().get_propositions().size();
    // If the current question is not the first question, delete the previous propositions buttons
    if(_numQuestion != 1) { delete [] _buttonProp; }
    // Create new buttons for the current question's propositions
    _buttonProp = new Button[_sizeProp];

    //Get the size of the window
    sf::Vector2f wSize(window.getSize().x,window.getSize().y);

    // Create the path for the image associated with the current question
    std::string imgPath = "assets/images/quizz/q" + std::to_string(_galop) + std::to_string(_numQuestion) + ".jpg";
    //Check if the image exists
    _isImg = exists(imgPath);

    if(_isImg){
        //Load the image and set it to be smooth
        _imgTexture.loadFromFile(imgPath);
        _imgTexture.setSmooth(true);

        //Delete the previous image sprite and create a new one with the current image
        delete _imgSprite;
        _imgSprite = new sf::Sprite;
        _imgSprite->setTexture(_imgTexture);
    }

    //Calculate the number of lines needed to display the question and propositions
    int nLine = _sizeProp + 1;
    //Create the text for the current question
    Useful::setTxt(_txtQuestion, _questions.front().get_question(), *_font, 60, wSize.x/2, wSize.y*0.5/(nLine+1), wSize);
    
    std::vector<std::string> *prop = &(_questions.front().get_propositions());
    sf::Color    grey(150, 150, 150);
    sf::Color    red(255, 100, 100);
    

    if(_isImg == 0){
        // If there is no image, the buttons are positioned in the center of the screen
        sf::Vector2f size(wSize.x*0.65,wSize.y*0.65/(nLine+1));

        for(int i = 0; i < _sizeProp; i++){
            sf::Vector2f pos(wSize.x/2, wSize.y*(i+1.8)/(nLine+1));
            _buttonProp[i].Setting(size, pos, (*prop)[i], *_font);
        }

    }else{
        // else, the buttons are positioned to the right of the image
        float space = wSize.y*0.03;

        sf::FloatRect Rect = _imgSprite->getLocalBounds();
        float scale = Useful::min(wSize.y*0.60/Rect.height,wSize.x*0.45/Rect.width);
        _imgSprite->setScale(scale, scale);
        _imgSprite->setOrigin(Rect.left + Rect.width / 2.0f, Rect.top + Rect.height / 2.0f);
        _imgSprite->setPosition(wSize.x/4, wSize.y*(1.8+(_sizeProp-1)+1.8)/2/(nLine+1) + space);
        sf::Vector2f size(wSize.x*0.4,wSize.y*0.65/(nLine+1));

        for(int i = 0; i < _sizeProp; i++){
            sf::Vector2f pos(wSize.x*3/4, wSize.y*(i+1.8)/(nLine+1) + space);
            _buttonProp[i].Setting(size, pos, (*prop)[i], *_font);
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

    // set the text of the answer
    Useful::setTxt(_answer, txt, *_font, 40, wSize.x/2, wSize.y*(1.1)/(_sizeProp+2), wSize);
    
    // create the next button
    sf::Vector2f size(wSize.x*0.14,wSize.y*0.45/6);
    sf::Vector2f pos(wSize.x*0.92, wSize.y*5.65/6);
    sf::Color    grey(150, 150, 150);
    sf::Color    red(255, 100, 100);
    _next.Setting(size, pos, "Suivant", *_font);
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

    //set the text of the score
    Useful::setTxt(_txtQuestion, "RESULTAT", *_font, 60, wSize.x/2, wSize.y/8, wSize);
    Useful::setTxt(_txtScore, txt, *_font, 40, wSize.x/2, wSize.y*3/8, wSize);
}

void Quizz::HandleEvent(sf::RenderWindow& window,sf::Event &event)
{   
    //handle event for each proposition button
    for(int i = 0; i < _sizeProp; i++)
        _buttonProp[i].HandleEvent(event);

    //handle event for next button if answer or score is shown
    if(_isAnswer || _isScore)
        _next.HandleEvent(event);
}

void Quizz::CheckAnswer(sf::RenderWindow& window)
{
    // if a button is hover => RunAnswer
    for(int i = 0; i < _sizeProp; i++){ 
        if(_buttonProp[i].isHover()){
            if(_questions.front().get_propositions()[i] == _questions.front().get_answer()){
                std::string path = "assets/images/panneau_vert.jpg";
                _buttonProp[i].setDefaultTexture(path);
                RunAnswer(window,1);
                _score++;
            }else{
                std::string path = "assets/images/panneau_rouge.jpg";
                _buttonProp[i].setDefaultTexture(path);
                RunAnswer(window,0);
            }

            for(int j = 0; j < _sizeProp; j++)
                _buttonProp[j].turnOff();

            break;
        }       
    }
}

Screen* Quizz::Update(sf::RenderWindow& window)
{
    if(_isAnswer == false && _isScore == false){
        CheckAnswer(window);

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
        window.draw(*_imgSprite);

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
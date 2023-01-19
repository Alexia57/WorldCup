#ifndef QUIZZ_HPP
#define QUIZZ_HPP

#include "Screen.hpp"
#include "Button.hpp"
#include "Question.hpp"


class Quizz : public Screen
{
private:
    int _galop;
    int _score = 0;
    int _numQuestion;
    std::list<Question> _questions;

    bool _isImg;
    sf::Texture _imgTexture;
    sf::Sprite *_imgSprite;
    
    sf::Text _txtQuestion;
    int _sizeProp;
    Button *_buttonProp;

    bool _isAnswer = 0;
    sf::Text _answer;
    Button _next;

    bool _isScore = 0;
    sf::Text _txtScore;

public:
    Quizz(sf::RenderWindow& window, sf::Font *font, int galop);
    ~Quizz() override;

    void RunQuestion(sf::RenderWindow& window);
    void RunAnswer(sf::RenderWindow& window, bool goodAnswer);
    void RunScore(sf::RenderWindow& window);
    void HandleEvent(sf::RenderWindow& window,sf::Event &event) override;
    Screen* Update(sf::RenderWindow& window) override;
    void Draw(sf::RenderWindow& window) override;
};

#endif /* QUIZZ_HPP */
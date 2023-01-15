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

    sf::Texture _imgTexture;
    sf::Sprite _imgSprite;
    bool _isImg;
    sf::Text _txtQuestion;
    Button *_buttonProp;
    int _sizeProp;

public:
    Quizz(sf::RenderWindow& window, sf::Font *font, int galop);
    ~Quizz() override;

    void RunQuestion(sf::RenderWindow& window);
    void HandleEvent(sf::RenderWindow& window,sf::Event &event) override;
    Screen* Update(sf::RenderWindow& window) override;
    void Draw(sf::RenderWindow& window) override;
};

#endif /* QUIZZ_HPP */
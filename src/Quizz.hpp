#ifndef QUIZZ_HPP
#define QUIZZ_HPP

#include "Screen.hpp"
#include "Button.hpp"
#include "Question.hpp"


class Quizz : public Screen
{
private:
    // The galop level of the quiz
    int _galop;
    // The current score
    int _score = 0;
    // The current question number
    int _numQuestion;
    // The list of questions for the quiz
    std::list<Question> _questions;

    // Whether or not the current question has an image
    bool _isImg;
    // The texture for the image
    sf::Texture _imgTexture;
    // The sprite for the image
    sf::Sprite *_imgSprite;
    
    // The text for the question
    sf::Text _txtQuestion;
    // The number of propositions for the current question
    int _sizeProp;
    // The buttons for the propositions
    Button *_buttonProp;

    // Whether or not an answer is being displayed
    bool _isAnswer = 0;
    // The text for the answer
    sf::Text _answer;
    // The button for going to the next question
    Button _next;

    // Whether or not the score is being displayed
    bool _isScore = 0;
    // The text for the score
    sf::Text _txtScore;

public:
    // Constructor
    Quizz(sf::RenderWindow& window, sf::Font *font, int galop);
    // Destructor
    ~Quizz() override;

    // Runs the current question
    void RunQuestion(sf::RenderWindow& window);
    // Runs the answer for the current question
    void RunAnswer(sf::RenderWindow& window, bool goodAnswer);
    // Runs the score display
    void RunScore(sf::RenderWindow& window);
    // Handles events for the Quizz class
    void HandleEvent(sf::RenderWindow& window,sf::Event &event) override;
    // Updates the Quizz class
    Screen* Update(sf::RenderWindow& window) override;
    // Draws the Quizz class
    void Draw(sf::RenderWindow& window) override;
};

#endif /* QUIZZ_HPP */
#ifndef QUIZZ_HPP
#define QUIZZ_HPP

#include "Screen.hpp"

class Quizz : public Screen
{
private:
    int _selectedOption = 0;
    sf::Image _img;
    sf::Text _question;
    sf::Text *_proposition;
    int _sizeProp;

public:
    Quizz(sf::RenderWindow& window, sf::Font *font, sf::String question, sf::String *proposition, int sizeProp);
    ~Quizz() override;
    Screen* HandleEvent(sf::RenderWindow& window,sf::Event &event) override;
    void Update(sf::RenderWindow& window) override;
    void Draw(sf::RenderWindow& window) override;
};

#endif /* QUIZZ_HPP */
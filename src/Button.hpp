#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>

class Button {
private:
    sf::RectangleShape _shape;
    sf::Text _text;
    sf::Color _defaultColor;
    sf::Color _hoverColor;
    bool _isHover = false;

public:
    Button(){}
    ~Button(){}

    void Setting(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color, 
           const sf::Color& hoverColor, const std::string& text, const sf::Font& font);
    bool isHover(){ return _isHover; }
    void HandleEvent(sf::Event event);
    void Update();
    void Draw(sf::RenderWindow& window);

};

#endif /* BUTTON_HPP */
#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>

class Button {
private:
    // shape of the button
    sf::RectangleShape _shape;
    // text on the button
    sf::Text _text;
    // default color of the button
    sf::Color _defaultColor;
    // color of the button when hovered over
    sf::Color _hoverColor;
    // whether the button is currently being hovered over
    bool _isHover = false;
    // whether the button is currently active
    bool _isActive = true;

    bool _imgVersion;
    sf::Texture _defaultTexture;
    sf::Texture _hoverTexture;
    sf::Sprite _sprite;

public:
    Button(){}
    ~Button(){}

    // set the properties of the button
    void Setting(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color, 
           const sf::Color& hoverColor, const std::string& text, const sf::Font& font);
    // set the properties of the button for img version
    void Setting(const sf::Vector2f& size, const sf::Vector2f& position, const std::string& text, 
            const sf::Font& font, const std::string& texture = "assets/images/panneau.jpg", 
            const std::string& textureHover = "assets/images/panneau_hover.jpg");
    // set the default color of the button
    void setDefaultColor(const sf::Color& color);
    // set the default texture of the button
    void setDefaultTexture(std::string& texture);
    // deactivate the button
    void turnOff();
    // activate the button
    void turnOn();
    // check if the button is currently being hovered over
    bool isHover(){ return _isHover; }
    // handle events for the button
    void HandleEvent(sf::Event event);
    // update the button
    void Update();
    // draw the button
    void Draw(sf::RenderWindow& window);

};

#endif /* BUTTON_HPP */
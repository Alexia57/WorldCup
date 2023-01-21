#include <iostream>
#include "Button.hpp"
#include "Useful.hpp"


void Button::Setting(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color, 
    const sf::Color& hoverColor, const std::string& text, const sf::Font& font)
{
    // set the default and hover color of the button
    _defaultColor = color;
    _hoverColor = hoverColor;
    // set the button as active
    _isActive = true;
    
    // set the size, position and color of the button's shape
    _shape.setSize(size);
    sf::FloatRect shapeRect = _shape.getLocalBounds();
    _shape.setOrigin(shapeRect.left + shapeRect.width / 2.0f, shapeRect.top + shapeRect.height / 2.0f);
    _shape.setPosition(position);
    _shape.setFillColor(color);
    
    // set the text, font, size and color of the button's text
    _text.setString(UTF8_to_UTF32(text));
    _text.setFont(font);
    _text.setCharacterSize(40);
    _text.setFillColor(sf::Color::White);
    
    // center the text
    sf::FloatRect textRect = _text.getLocalBounds();
    _text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    _text.setPosition(position.x, position.y);

    // Resize txt in box
    int charSize = _text.getCharacterSize();
    shapeRect = _shape.getGlobalBounds();
    shapeRect.left += shapeRect.width*0.05;
    shapeRect.width *= 0.90;
    textRect = _text.getGlobalBounds();
    // Reduce text size until it fits in the button
    while(!shapeRect.contains(textRect.left,textRect.top)){
        charSize -= 3;
        if(charSize < 10)
            break;
        
        _text.setCharacterSize(charSize);
        textRect = _text.getLocalBounds();
        _text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        _text.setPosition(position.x, position.y);
        textRect = _text.getGlobalBounds();
    }
}

void Button::setDefaultColor(const sf::Color& color){
    // set the default color of the button
    _defaultColor = color;
    _shape.setFillColor(color);
}

void Button::turnOff(){
    // deactivate the button
    _isActive = false;
    _isHover = false;
    _shape.setFillColor(_defaultColor);
}

void Button::turnOn(){
    // activate the button
    _isActive = true;
    _isHover = false;
}

void Button::HandleEvent(sf::Event event) {

    if(_isActive) {
        if (event.type == sf::Event::MouseMoved) {
        
            if (_shape.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y)) {
                // if the mouse is hovering over the button, change the color to the hover color
                _shape.setFillColor(_hoverColor);
            } else {
                // else, change the color back to the default color
                _shape.setFillColor(_defaultColor);
            }

        } else if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                
                if (_shape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    // if the button is clicked, set _isHover to true
                    _isHover = true;
                }
            }
        }
    }
}

void Button::Draw(sf::RenderWindow& window) {
    // draw the button's shape and text
    window.draw(_shape);
    window.draw(_text);
}
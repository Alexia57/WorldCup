#include <iostream>
#include "Button.hpp"
#include "Useful.hpp"

void printRect(sf::FloatRect rect){
    std::cout << "top = "<< rect.top << " | left = " << rect.left << " | height = " << rect.height << " | width = " << rect.width << std::endl;
}

void Button::Setting(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color, 
    const sf::Color& hoverColor, const std::string& text, const sf::Font& font)
{
    _defaultColor = color;
    _hoverColor = hoverColor;
    _isActive = true;
    
    _shape.setSize(size);
    sf::FloatRect shapeRect = _shape.getLocalBounds();
    _shape.setOrigin(shapeRect.left + shapeRect.width / 2.0f, shapeRect.top + shapeRect.height / 2.0f);
    _shape.setPosition(position);
    _shape.setFillColor(color);
    
    _text.setString(UTF8_to_UTF32(text));
    _text.setFont(font);
    _text.setCharacterSize(40);
    _text.setFillColor(sf::Color::White);
    
    sf::FloatRect textRect = _text.getLocalBounds();
    _text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    _text.setPosition(position.x, position.y);

    // Resize txt in box
    int charSize = _text.getCharacterSize();
    shapeRect = _shape.getGlobalBounds();
    shapeRect.left += shapeRect.width*0.05;
    shapeRect.width *= 0.90;
    textRect = _text.getGlobalBounds();
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
    _defaultColor = color;
    _shape.setFillColor(color);
}

void Button::turnOff(){
    _isActive = false;
    _shape.setFillColor(_defaultColor);
}

void Button::turnOn(){
    _isActive = true;
    _isHover = false;
}

void Button::HandleEvent(sf::Event event) {

    if(_isActive) {
        if (event.type == sf::Event::MouseMoved) {
        
            if (_shape.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y)) {
                _shape.setFillColor(_hoverColor);
            } else {
                _shape.setFillColor(_defaultColor);
            }

        } else if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                
                if (_shape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    _isHover = true;
                }
            }
        }
    }
}

void Button::Draw(sf::RenderWindow& window) {
    window.draw(_shape);
    window.draw(_text);
}
#include <iostream>
#include "Button.hpp"
#include "Useful.hpp"

void Button::ResizeTxt(const sf::Vector2f& position)
{
    // Resize txt in box
    int charSize = _text.getCharacterSize();
    sf::FloatRect textRect = _text.getGlobalBounds();
    sf::FloatRect shapeRect = (_imgVersion)? _sprite.getGlobalBounds() : _shape.getGlobalBounds();
    shapeRect.left += shapeRect.width*0.05;
    shapeRect.width *= 0.90;

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

void Button::Setting(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color, 
    const sf::Color& hoverColor, const std::string& text, const sf::Font& font)
{
    _imgVersion = false;
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

    ResizeTxt(position);
}


void Button::Setting(const sf::Vector2f& size, const sf::Vector2f& position, const std::string& text, 
            const sf::Font& font, const std::string& texture, 
            const std::string& textureHover)
{
    _imgVersion = true;
    _defaultTexture.loadFromFile(texture);
    _hoverTexture.loadFromFile(textureHover);
    _sprite.setTexture(_defaultTexture);

    // set the size, position and color of the button's shape
    sf::FloatRect Rect = _sprite.getLocalBounds();
    _sprite.setScale(size.x/Rect.width, size.y/Rect.height);
    _sprite.setOrigin(Rect.left + Rect.width / 2.0f, Rect.top + Rect.height / 2.0f);
    _sprite.setPosition(position);

    
    // set the text, font, size and color of the button's text
    _text.setString(UTF8_to_UTF32(text));
    _text.setFont(font);
    _text.setCharacterSize(40);
    _text.setFillColor(sf::Color::White);
    
    // center the text
    sf::FloatRect textRect = _text.getLocalBounds();
    _text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    _text.setPosition(position.x, position.y);

    ResizeTxt(position);
}


void Button::setDefaultColor(const sf::Color& color)
{
    // set the default color of the button
    _defaultColor = color;
    _shape.setFillColor(color);
}

void Button::setDefaultTexture(std::string& texture)
{
    // set the default color of the button
    _defaultTexture.loadFromFile(texture);
    _sprite.setTexture(_defaultTexture);
}

void Button::turnOff()
{
    // deactivate the button
    _isActive = false;
    _isHover = false;
    if (_imgVersion)
        _sprite.setTexture(_defaultTexture);
    else
        _shape.setFillColor(_defaultColor);
}

void Button::turnOn()
{
    // activate the button
    _isActive = true;
    _isHover = false;
}

void Button::HandleEvent(sf::Event event) 
{
    if(_isActive) {
        if (event.type == sf::Event::MouseMoved) {
            // if the mouse is hovering over the button, change the color to the hover color
            // else, change the color back to the default color
            if (_imgVersion){
                if(_sprite.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
                    _sprite.setTexture(_hoverTexture);
                else 
                    _sprite.setTexture(_defaultTexture);
            }else{
                if (_shape.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
                    _shape.setFillColor(_hoverColor);
                else
                    _shape.setFillColor(_defaultColor);
            }

        } else if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                // if the button is clicked, set _isHover to true
                if(_imgVersion){
                    if (_sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        _isHover = true;
                }else{
                    if (_shape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        _isHover = true;
                }           
            }
        }
    }
}

void Button::Draw(sf::RenderWindow& window) {
    // draw the button's shape and text
    if (_imgVersion)
        window.draw(_sprite);
    else
        window.draw(_shape);
    window.draw(_text);
    
}
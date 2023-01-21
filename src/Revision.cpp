#include <iostream>
#include <string>

#include "Revision.hpp"
#include "Menu.hpp"
#include "Useful.hpp"

Revision::Revision(sf::RenderWindow& window, sf::Font *font, int galop) : Screen(font)
{
    _galop = galop;
    _numSheet = 1;

    std::string pathDir = "assets/images/imagesLecons/";
    std::string format = "g" + std::to_string(_galop) + "_*.jpg";
    _pathImg = getFileNames(pathDir, format);

    
    _nSheet = _pathImg.size();
    _imgTexture = new sf::Texture[_nSheet];

    window.setTitle("Revision");

    sf::Vector2f wSize(window.getSize().x,window.getSize().y);
    sf::Color    grey(150, 150, 150);
    sf::Color    red(255, 100, 100);
    sf::Vector2f sizeMenu(wSize.x*0.09, wSize.y/12);
    sf::Vector2f posMenu(wSize.x*0.06, wSize.y*0.4/6);
    _menu.Setting(sizeMenu, posMenu, "Menu", *_font);

    sf::Vector2f sizePrev(wSize.x*0.14, wSize.y/12);
    sf::Vector2f posPrev(wSize.x*0.08, wSize.y*5.7/6);
    _previous.Setting(sizePrev, posPrev, "Précédent", *_font);

    sf::Vector2f sizeNext(wSize.x*0.14, wSize.y/12);
    sf::Vector2f posNext(wSize.x*0.92, wSize.y*5.7/6);
    _next.Setting(sizeNext, posNext, "Suivant", *_font);

    _imgSprite = new sf::Sprite;

    RunSheet(window);
}

Revision::~Revision()
{
    delete _imgSprite;
    delete [] _imgTexture;
}

void Revision::RunSheet(sf::RenderWindow& window)
{
    sf::Vector2f wSize(window.getSize().x,window.getSize().y);

    // set the text for the revision sheet
    Useful::setTxt(_txtRevision, "Galop "+std::to_string(_galop)+" : Fiche n°"+std::to_string(_numSheet), *_font, 50, wSize.x/2, wSize.y/22, wSize);

    // check if the 'previous' button should be displayed
    if(_numSheet > 1){
        _isPrevious = 1;
        _previous.turnOn();
    }else{
        _isPrevious = 0;
        _previous.turnOff();
    }
    
    // check if the 'next' button should be displayed
    if(_numSheet < _nSheet){
        _isNext = 1;
        _next.turnOn();
    }else{
        _isNext = 0;
        _next.turnOff();
    }

    // load the image for the current sheet if it has not been loaded yet
    if(_imgTexture[_numSheet-1].getSize() == sf::Vector2u(0,0)){
        //std::cout << "Load :" << _pathImg[_numSheet-1] << std::endl;
        std::string pathImg = "assets/images/imagesLecons/" + _pathImg[_numSheet-1];
        _imgTexture[_numSheet-1].loadFromFile(pathImg);
        _imgTexture[_numSheet-1].setSmooth(true);
    }
    
    // set the texture and position of the image sprite
    delete _imgSprite;
    _imgSprite = new sf::Sprite;

    
    _imgSprite->setTexture(_imgTexture[_numSheet-1]);
    
    sf::FloatRect Rect = _imgSprite->getLocalBounds();
    float scale = Useful::min(wSize.y*0.78/Rect.height,wSize.x*0.95/Rect.width);
    _imgSprite->setScale(scale, scale);
    _imgSprite->setOrigin(Rect.left + Rect.width / 2.0f, Rect.top + Rect.height / 2.0f);
    _imgSprite->setPosition(wSize.x/2, wSize.y*0.50);
    
}

void Revision::HandleEvent(sf::RenderWindow& window,sf::Event &event)
{   
    // handle event for menu, previous and next buttons
    _menu.HandleEvent(event);
    _previous.HandleEvent(event);
    _next.HandleEvent(event);
}   

Screen* Revision::Update(sf::RenderWindow& window)
{
    // if menu button is hovered, create new menu screen and return it
    if(_menu.isHover()){
        Menu *screen = new Menu(window, _font);
        return screen;
    }
    // if previous button is hovered, decrease the current sheet number and update the current sheet
    if(_previous.isHover()){
        _numSheet--;
        RunSheet(window);
    }
    // if next button is hovered, increase the current sheet number and update the current sheet
    if(_next.isHover()){
        _numSheet++;
        RunSheet(window);
    }
    // return the current screen
    return this;
}

void Revision::Draw(sf::RenderWindow& window)
{
    // draw the sheet number text
    window.draw(_txtRevision);

    // draw the current sheet image
    window.draw(*_imgSprite);

    // if there is a previous sheet, draw the previous button
    if(_isPrevious)
        _previous.Draw(window);

    // draw the menu button
    _menu.Draw(window);

    // if there is a next sheet, draw the next button
    if(_isNext)
        _next.Draw(window);
}
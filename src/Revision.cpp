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
    std::string format = "g" + std::to_string(_galop) + "_*.png";
    _pathImg = getFileNames(pathDir, format);

    /* std::cout << "size : " << _pathImg.size() << std::endl;
    for(auto it =_pathImg.begin(); it!=_pathImg.end(); it++)
        std::cout << (*it) << std::endl; */
    
    _nSheet = _pathImg.size();
    _imgTexture = new sf::Texture[_nSheet];

    window.setTitle("Revision");

    sf::Vector2f wSize(window.getSize().x,window.getSize().y);
    sf::Color    grey(150, 150, 150);
    sf::Color    red(255, 100, 100);
    sf::Vector2f sizeMenu(wSize.x*0.09, wSize.y/12);
    sf::Vector2f posMenu(wSize.x*0.06, wSize.y*0.4/6);
    _menu.Setting(sizeMenu, posMenu, grey, red, "Menu", *_font);

    sf::Vector2f sizePrev(wSize.x*0.14, wSize.y/12);
    sf::Vector2f posPrev(wSize.x*0.08, wSize.y*5.7/6);
    _previous.Setting(sizePrev, posPrev, grey, red, "Précédent", *_font);

    sf::Vector2f sizeNext(wSize.x*0.14, wSize.y/12);
    sf::Vector2f posNext(wSize.x*0.92, wSize.y*5.7/6);
    _next.Setting(sizeNext, posNext, grey, red, "Suivant", *_font);

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

    Useful::setTxt(_txtRevision, "Galop "+std::to_string(_galop)+" : Fiche n°"+std::to_string(_numSheet), *_font, 50, wSize.x/2, wSize.y/22, wSize);

    if(_numSheet > 1){
        _isPrevious = 1;
        _previous.turnOn();
    }else{
        _isPrevious = 0;
        _previous.turnOff();
    }
    
    if(_numSheet < _nSheet){
        _isNext = 1;
        _next.turnOn();
    }else{
        _isNext = 0;
        _next.turnOff();
    }

    if(_imgTexture[_numSheet-1].getSize() == sf::Vector2u(0,0)){
        //std::cout << "Load :" << _pathImg[_numSheet-1] << std::endl;
        std::string pathImg = "assets/images/imagesLecons/" + _pathImg[_numSheet-1];
        _imgTexture[_numSheet-1].loadFromFile(pathImg);
        _imgTexture[_numSheet-1].setSmooth(true);
    }
    
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
    _menu.HandleEvent(event);
    _previous.HandleEvent(event);
    _next.HandleEvent(event);
}   

Screen* Revision::Update(sf::RenderWindow& window)
{
    if(_menu.isHover()){
        Menu *screen = new Menu(window, _font);
        return screen;
    }
    if(_previous.isHover()){
        _numSheet--;
        RunSheet(window);
    }
    if(_next.isHover()){
        _numSheet++;
        RunSheet(window);
    }

    return this;
}

void Revision::Draw(sf::RenderWindow& window)
{
    window.draw(_txtRevision);

    window.draw(*_imgSprite);

    if(_isPrevious)
        _previous.Draw(window);

    _menu.Draw(window);

    if(_isNext)
        _next.Draw(window);
}
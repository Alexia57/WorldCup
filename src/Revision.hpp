#ifndef REVISION_HPP
#define REVISION_HPP

#include "Screen.hpp"
#include "Button.hpp"

class Revision : public Screen
{
private:
    int _galop;
    int _numSheet;

    sf::Text _txtRevision;

    int _nSheet;
    std::vector<std::string> _pathImg;
    sf::Texture *_imgTexture;
    sf::Sprite *_imgSprite;

    bool _isPrevious;
    Button _previous;
    Button _menu;
    bool _isNext;
    Button _next;


public:
    Revision(sf::RenderWindow& window, sf::Font *font, int galop);
    ~Revision() override;

    void RunSheet(sf::RenderWindow& window);
    void HandleEvent(sf::RenderWindow& window,sf::Event &event) override;
    Screen* Update(sf::RenderWindow& window) override;
    void Draw(sf::RenderWindow& window) override;
};

#endif /* REVISION_HPP */
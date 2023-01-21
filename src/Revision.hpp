#ifndef REVISION_HPP
#define REVISION_HPP

#include "Screen.hpp"
#include "Button.hpp"

class Revision : public Screen
{
private:
    // the level of the game
    int _galop;
    // current sheet number
    int _numSheet;

    // text to display the current sheet number
    sf::Text _txtRevision;

    // number of sheets
    int _nSheet;
    // vector to store the path of the images
    std::vector<std::string> _pathImg;
    // texture to store the image
    sf::Texture *_imgTexture;
    // sprite to display the image
    sf::Sprite *_imgSprite;

    // Whether or not the previous button is active
    bool _isPrevious;
    // button to go to the previous sheet
    Button _previous;
    // button to go back to the menu
    Button _menu;
    // Whether or not the next button is active
    bool _isNext;
    // button to go to the next sheet
    Button _next;


public:
    // Contructor
    Revision(sf::RenderWindow& window, sf::Font *font, int galop);
    // Destructor
    ~Revision() override;

    // function to run the current sheet
    void RunSheet(sf::RenderWindow& window);
    // function to handle events
    void HandleEvent(sf::RenderWindow& window,sf::Event &event) override;
    // function to update the screen
    Screen* Update(sf::RenderWindow& window) override;
    // function to draw the elements on the screen
    void Draw(sf::RenderWindow& window) override;
};

#endif /* REVISION_HPP */
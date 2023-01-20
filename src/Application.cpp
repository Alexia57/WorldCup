#include <iostream> 
#include "Application.hpp"
#include "Useful.hpp"

using namespace std;

Application::Application(sf::RenderWindow& window)
{
    _font.loadFromFile("assets/arial.ttf");
    _texture.loadFromFile("assets/images/background.png");
    _texture.setSmooth(true);
    _background.setTexture(_texture);

    sf::Vector2f wSize(window.getSize().x,window.getSize().y);
    sf::FloatRect Rect = _background.getLocalBounds();
    float scale = Useful::max(wSize.x/Rect.width,wSize.y/Rect.height);
    _background.setScale(scale,scale);
}

Application& Application::initialize(sf::RenderWindow& window)
{
    static Application app(window);
    return app;
}

void Application::HandleEvent(sf::RenderWindow& window, Screen& currentScreen)
{
    sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        currentScreen.HandleEvent(window, event);
    }
}

Screen* Application::Update(sf::RenderWindow& window, Screen& currentScreen)
{
    Screen* screen = &currentScreen;
    Screen* tmpScreen = screen->Update(window);
    if(tmpScreen != screen){
        delete screen;
        return tmpScreen;
    }
    return screen;
}

void Application::Draw(sf::RenderWindow& window, Screen& currentScreen)
{
    window.draw(_background);
    currentScreen.Draw(window);
}

void Application::Loop(sf::RenderWindow& window)
{
    Screen *currentScreen = new Menu(window, &_font);
    
    while (window.isOpen()) {
        HandleEvent(window, *currentScreen);
        currentScreen = Update(window, *currentScreen);
        window.clear(sf::Color::Black);
        Draw(window, *currentScreen);
        window.display();
    }

    delete currentScreen;
}

void Application::Run(sf::RenderWindow& window)
{
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    Loop(window);
}





#include <iostream> 
#include "Application.hpp"
#include "Useful.hpp"

using namespace std;

Application::Application(sf::RenderWindow& window)
{
    // Load font from file "assets/arial.ttf"
    _font.loadFromFile("assets/arial.ttf");
    _texture.loadFromFile("assets/images/background.jpg");
    // Enable texture smoothing
    _texture.setSmooth(true);
    _background.setTexture(_texture);

    // Get the size of the window and store it in wSize
    sf::Vector2f wSize(window.getSize().x,window.getSize().y);
    // Get the local bounds of the background sprite
    sf::FloatRect Rect = _background.getLocalBounds();
    // Calculate the scale factor to fit the background to the window
    float scale = Useful::max(wSize.x/Rect.width,wSize.y/Rect.height);
    // Set the scale of the background sprite
    _background.setScale(scale,scale);
}

Application& Application::initialize(sf::RenderWindow& window)
{
    // Create a static instance of the application
    static Application app(window);
    return app;
}

void Application::HandleEvent(sf::RenderWindow& window, Screen& currentScreen)
{
    // Process any pending events
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        // Pass the event to the current screen to handle
        currentScreen.HandleEvent(window, event);
    }
}

Screen* Application::Update(sf::RenderWindow& window, Screen& currentScreen)
{
    Screen* screen = &currentScreen;
    // Update the current screen
    Screen* tmpScreen = screen->Update(window);
    // If the screen has changed, delete the old screen
    if(tmpScreen != screen){
        delete screen;
        return tmpScreen;
    }
    return screen;
}

void Application::Draw(sf::RenderWindow& window, Screen& currentScreen)
{
    // Draw the background
    window.draw(_background);
    // Draw the current screen
    currentScreen.Draw(window);
}

void Application::Loop(sf::RenderWindow& window)
{
    // Create a new instance of the menu screen
    Screen *currentScreen = new Menu(window, &_font);
    
    while (window.isOpen()) {
        // Handle events, update, and draw the screen
        HandleEvent(window, *currentScreen);
        currentScreen = Update(window, *currentScreen);
        window.clear(sf::Color::Black);
        Draw(window, *currentScreen);
        window.display();
    }
    // Delete the current screen
    delete currentScreen;
}

void Application::Run(sf::RenderWindow& window)
{
    // Set vertical sync and frame rate limit
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    Loop(window);
}





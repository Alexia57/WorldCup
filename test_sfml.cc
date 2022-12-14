#include <iostream>
#include <SFML/Graphics.hpp>


#define WIDTH 800
#define HEIGHT 600


int main()
{   

    // create the window
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "My window");

    sf::Texture texture;
    sf::Sprite sprite;

    if (!texture.loadFromFile("logo_cheval.png", sf::IntRect(0, 0, HEIGHT, HEIGHT))){
        std::cout << "Erreur loading img\n";
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);
        window.draw(sprite);
        // draw everything here...
        // window.draw(...);

        // end the current frame
        window.display();
    }

    return 0;
}
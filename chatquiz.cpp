#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#define WIDTH 800
#define HEIGHT 600

// g++ chatquiz.cpp -o chatquiz -lsfml-graphics -lsfml-window -lsfml-system
// ./chatquiz

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Horse Quiz");
    window.setVerticalSyncEnabled(true);
    // modification of the widow position
    window.setPosition(sf::Vector2i(192, 0));
    window.setFramerateLimit(60);
    //
    sf::Texture texture;
    sf::Sprite sprite;

    if (!texture.loadFromFile("logo_cheval.png", sf::IntRect(0, 0, WIDTH / 2, HEIGHT / 2)))
    {
        std::cout << "Erreur loading img\n";
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    // Set up font
    sf::Font font;
    if (!font.loadFromFile("res/Poppins.ttf"))
    {
        std::cout << "Error loading font" << std::endl;
        return 1;
    }
    sprite.setPosition(450, 200);

    // colors
    sf::Color grey(80, 80, 80);
    sf::Color lightgrey(180, 180, 180);


    // Set up text
    sf::Text questionText("What is the scientific name for the horse?", font, 24);
    questionText.setPosition(100, 100);
    questionText.setColor(sf::Color::Black);

    sf::Text answerText1("Equus ferus", font, 24);
    answerText1.setPosition(120, 200);

    sf::Text answerText2("Canis lupus", font, 24);
    answerText2.setPosition(120, 270);

    sf::Text answerText3("Bos taurus", font, 24);
    answerText3.setPosition(120, 340);

    sf::Text answerText4("Panthera leo", font, 24);
    answerText4.setPosition(120, 410);

    // Set up rectangles for clicking on answers
    sf::RectangleShape answerRect1(sf::Vector2f(200, 50));
    answerRect1.setPosition(answerText1.getPosition().x -20, answerText1.getPosition().y -10);
    answerRect1.setFillColor(lightgrey);

    sf::RectangleShape answerRect2(sf::Vector2f(200, 50));
    answerRect2.setPosition(answerText2.getPosition().x -20, answerText2.getPosition().y -10);
    answerRect2.setFillColor(lightgrey);

    sf::RectangleShape answerRect3(sf::Vector2f(200, 50));
    answerRect3.setPosition(answerText3.getPosition().x -20, answerText3.getPosition().y -10);
    answerRect3.setFillColor(lightgrey);

    sf::RectangleShape answerRect4(sf::Vector2f(200, 50));
    answerRect4.setPosition(answerText4.getPosition().x -20, answerText4.getPosition().y -10);
    answerRect4.setFillColor(lightgrey);

    // Set up rectangles under answer rectangles
    sf::RectangleShape underRect1(sf::Vector2f(204, 54));
    underRect1.setPosition(answerText1.getPosition().x -22, answerText1.getPosition().y -12);
    underRect1.setFillColor(grey);

    sf::RectangleShape underRect2(sf::Vector2f(204, 54));
    underRect2.setPosition(answerText2.getPosition().x -22, answerText2.getPosition().y -12);
    underRect2.setFillColor(grey);

    sf::RectangleShape underRect3(sf::Vector2f(204, 54));
    underRect3.setPosition(answerText3.getPosition().x -22, answerText3.getPosition().y -12);
    underRect3.setFillColor(grey);

    sf::RectangleShape underRect4(sf::Vector2f(204, 54));
    underRect4.setPosition(answerText4.getPosition().x -22, answerText4.getPosition().y -12);
    underRect4.setFillColor(grey);

    // Set up "Correct" and "Incorrect" text and rectangle
    sf::Text correctText("Correct!", font, 24);
    correctText.setPosition(120, 500);
    correctText.setColor(sf::Color::Black);

    sf::RectangleShape correctRect(sf::Vector2f(200, 50));
    correctRect.setPosition(correctText.getPosition().x -20, correctText.getPosition().y -10);
    correctRect.setFillColor(sf::Color::Green);

    sf::Text incorrectText("Incorrect!", font, 24);
    incorrectText.setPosition(120, 500);
    incorrectText.setColor(sf::Color::Black);

    sf::RectangleShape inCorrectRect(sf::Vector2f(200, 50));
    inCorrectRect.setPosition(incorrectText.getPosition().x -20, incorrectText.getPosition().y -10);
    inCorrectRect.setFillColor(sf::Color::Red);


    // Set up flags to track whether the user has clicked on an answer and whether the correct or incorrect text should be
    std::size_t correct = -1;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            // resize widow
            if (event.type == sf::Event::Resized)
            {
                std::cout << "new width: " << event.size.width << std::endl;
                std::cout << "new height: " << event.size.height << std::endl;
            }
            // Check if the mouse button was pressed
            if (event.type == sf::Event::MouseButtonPressed)
            {
                // Check if the user clicked on an answer
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                std::cout << "posX" << mousePos.x << std::endl;
                std::cout << "posY" << mousePos.y << std::endl;
                if (answerRect1.getGlobalBounds().contains(mousePos.x, mousePos.y))
                {
                    // Check if the answer is correct
                    if (answerText1.getString() == "Equus ferus")
                    {
                        std::cout << "OUI1" << std::endl;
                        correct = 1;
                    }
                    else correct = 0;
                }
                else if (answerRect2.getGlobalBounds().contains(mousePos.x, mousePos.y))
                {
                    // Check if the answer is correct
                    if (answerText2.getString() == "Equus ferus")
                    {
                        correct = 1;
                        std::cout << "OUI2" << std::endl;
                    }
                    else correct = 0;
                }
                else if (answerRect3.getGlobalBounds().contains(mousePos.x, mousePos.y))
                {
                    // Check if the answer is correct
                    if (answerText3.getString() == "Equus ferus")
                    {
                        correct = 1;
                        std::cout << "OUI3" << std::endl;
                    }
                    else correct = 0;
                }
                else if (answerRect4.getGlobalBounds().contains(mousePos.x, mousePos.y))
                {
                    // Check if the answer is correct
                    if (answerText4.getString() == "Equus ferus")
                    {
                        correct = 1;
                        std::cout << "OUI4" << std::endl;
                    }
                    else correct = 0;
                }
            }
        }

        // Clear the window
        window.clear(sf::Color::White);
        window.draw(sprite);

        // Draw all the elements
        window.draw(questionText);

        window.draw(underRect1);
        window.draw(underRect2);
        window.draw(underRect3);
        window.draw(underRect4);


        window.draw(answerRect1);
        window.draw(answerRect2);
        window.draw(answerRect3);
        window.draw(answerRect4);
        window.draw(answerText1);
        window.draw(answerText2);
        window.draw(answerText3);
        window.draw(answerText4);

        if (correct == 1)
        {
            window.draw(correctRect);
            window.draw(correctText);
        }
        else if (correct == 0)
        {
            window.draw(inCorrectRect);
            window.draw(incorrectText);
        }

        window.display();
    }
    return 0;
}

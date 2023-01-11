#include "FenetreMenu.hpp"

void FenetreMenu::ajouterBouton(const std::string& texte, int x, int y,
                       const std::function<void()>& fonction)
{
    sf::Text bouton;
    bouton.setString(texte);
    bouton.setFont(m_font);
    bouton.setCharacterSize(24);
    bouton.setFillColor(sf::Color::Black);
    bouton.setPosition(x, y + 80 * m_boutons.size());
    sf::RectangleShape rectBouton(sf::Vector2f(150, 50));
    rectBouton.setPosition(bouton.getPosition().x -30, bouton.getPosition().y -10);
    rectBouton.setFillColor(sf::Color::Blue);

    m_boutons.push_back(bouton);
    m_rects.push_back(rectBouton);
    m_fonctions.push_back(fonction);
}

void FenetreMenu::afficherBoutons()
{
    for (std::size_t i = 0; i < m_boutons.size(); i++)
    {
        m_window.draw(m_rects[i]);
        m_window.draw(m_boutons[i]);
    }
}

void FenetreMenu::gererEvenements(sf::Event event) 
{
    // close window
    if (event.type == sf::Event::Closed)
    {
        //std::cout << "'croix' cliquée !" << std::endl;
        m_window.close();
    }
    // resize widow
    if (event.type == sf::Event::Resized)
    {
        std::cout << "new width: " << event.size.width << std::endl;
        std::cout << "new height: " << event.size.height << std::endl;
    }
    // Check if the mouse button was pressed
    if (event.type == sf::Event::MouseButtonPressed)
    {
        gererBoutons(event);
    }
}

void FenetreMenu::gererBoutons(sf::Event event)
{
    sf::Vector2i positionSouris = sf::Mouse::getPosition(m_window);

    for (std::size_t i = 0; i < m_boutons.size(); i++)
    {
        sf::FloatRect hitbox = m_boutons[i].getGlobalBounds();
        if (hitbox.contains(static_cast<float>(positionSouris.x),
                            static_cast<float>(positionSouris.y)))
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                m_fonctions[i]();
            m_boutons[i].setFillColor(sf::Color::Red);
            // si le bouton c'est "quitter" alors on ferme la fenetre
            if ( m_boutons[i].getString() == "Quitter")
                m_window.close();
            // si le bouton c'est "Quiz" alors on ouvre une fenetre quiz
            if ( m_boutons[i].getString() == "Quiz")
            {
                FenetreMenu quiz(800, 700, "Quiz");
                quiz.ajouterBouton("Galop 1", 180, 40, []{ std::cout << "Quiz Galop 1" << std::endl; });
                quiz.ajouterBouton("Galop 2", 180, 40,[]{ std::cout << "Quiz Galop 2" << std::endl; });
                quiz.ajouterBouton("Galop 3", 180, 40,[]{ std::cout << "Quiz Galop 3" << std::endl; });
                quiz.ajouterBouton("Galop 4", 180, 40,[]{ std::cout << "Quiz Galop 4" << std::endl; });
                quiz.ajouterBouton("Galop 5", 180, 40,[]{ std::cout << "Quiz Galop 5" << std::endl; });
                quiz.ajouterBouton("Galop 6", 180, 40,[]{ std::cout << "Quiz Galop 6" << std::endl; });
                quiz.ajouterBouton("Galop 7", 180, 40,[]{ std::cout << "Quiz Galop 7" << std::endl; });
                quiz.ajouterBouton("Quitter", 180, 40,[]{ std::cout << "Bouton 'Quitter' cliqué !" << std::endl; });
                while (quiz.estOuverte())
                {
                    sf::Event event;
                    while (quiz.isEvenement(event))
                    {
                        quiz.gererEvenements(event);
                    }
                    quiz.afficherBoutons();
                    quiz.afficher();
                }
            }
        }
        else
        {
            m_boutons[i].setFillColor(sf::Color::Black);
        }
    }
}

void FenetreMenu::clear(const sf::Color& couleur) 
{
    Fenetre::clear(couleur);
    m_boutons.clear();
    m_fonctions.clear();
}


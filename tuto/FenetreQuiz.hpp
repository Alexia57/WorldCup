#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "Fenetre.hpp"
/*
class FenetreQuiz : public Fenetre
{
public:
    // constructeur
    FenetreQuiz(int largeur, int hauteur, const std::string& titre)
        : Fenetre(largeur, hauteur, titre)
    {
        m_window.setVerticalSyncEnabled(true);
        // modification of the widow position
        m_window.setPosition(sf::Vector2i(192,0));
        m_window.setFramerateLimit(60);
        // texture et sprite
        if (!m_texture.loadFromFile("logo_cheval.png", sf::IntRect(0, 0, largeur / 2, hauteur / 2)))
        {
            std::cout << "Erreur loading img\n";
        }
        m_texture.setSmooth(true);
        m_sprite.setTexture(m_texture);
        // Set up font
        if (!m_font.loadFromFile("res/Poppins.ttf"))
        {
            std::cout << "Error loading font" << std::endl;
        }
        m_sprite.setPosition(450, 200);
    }
    // destructeur
    ~FenetreQuiz() {
        // Code de nettoyage, s'il y en a
    }

    // affiche question/réponses
    virtual void afficherQuestion(const std::string& question,
                          const std::vector<std::string>& reponses);
    
    void clear(const sf::Color& couleur);

    void gererEvenements(sf::Event event);

private:
    sf::Text m_question;
    std::vector<sf::Text> m_reponses;
};
*/
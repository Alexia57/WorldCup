#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <functional>
#include "Fenetre.hpp"

class FenetreMenu : public Fenetre
{
public:
    // constructeur
    FenetreMenu(int largeur, int hauteur, const std::string& titre)
        : Fenetre(largeur, hauteur, titre)
    {
        m_window.setVerticalSyncEnabled(true);
        // modification of the widow position
        m_window.setPosition(sf::Vector2i(192,0));
        m_window.setFramerateLimit(60);
        // Set up font
        if (!m_font.loadFromFile("res/Poppins.ttf"))
        {
            std::cout << "Error loading font" << std::endl;
        }
        // Set up text
        sf::Text text_tilte("MENU", m_font, 30);
        text_tilte.setPosition(100, 100);
        text_tilte.setFillColor(sf::Color::Black);
            }
    // destructeur
    ~FenetreMenu() {
        // Code de nettoyage, s'il y en a
    }

    // ajoute un bouton
    void ajouterBouton(const std::string& texte, int x, int y,
                       const std::function<void()>& fonction);
    // afficher boutons
    void afficherBoutons();
    // gérer les événements
    void gererEvenements(sf::Event event);
    // gérer les boutons
    void gererBoutons(sf::Event event); 
    
    void clear(const sf::Color& couleur);


private:
    std::vector<sf::Text> m_boutons;
    std::vector<sf::RectangleShape> m_rects;
    std::vector<std::function<void()>> m_fonctions;
};

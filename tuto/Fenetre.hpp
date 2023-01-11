#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Fenetre
{
public:
    // constructeur
    Fenetre(int largeur, int hauteur, const std::string& titre)
        : m_window(sf::VideoMode(largeur, hauteur), titre)
    {
        m_window.setVerticalSyncEnabled(true);
        // modification of the widow position
        m_window.setPosition(sf::Vector2i(190,50));
        m_window.setFramerateLimit(60);
        // Set up font
        if (!m_font.loadFromFile("res/Poppins.ttf"))
        {
            std::cout << "Error loading font" << std::endl;
        }
    }
    // destructeur
    ~Fenetre() {
        // Code de nettoyage, s'il y en a
    }

    // return true si la fenetre est ouverte et false sinon
    bool estOuverte() const;
    // permet de récupérer un événement de la file d'attente des événements de la fenêtre
    bool isEvenement(sf::Event& event);
    // gère les événements selon leurs type et dépendant de la fenetre
    virtual void gererEvenements(sf::Event event);
    // clear the window
    virtual void clear(const sf::Color& couleur);
    // dessiner elements
    void dessiner(const sf::Drawable& dessin);
    // dessiner les éléments présents
    virtual void toutDessiner();
    // afficher window
    void afficher();
    // close window
    void fermer();
    // obtenir la fenetre
    sf::RenderWindow* obtenirFenetre();
    // ajoute une image
    void ajouterImage(const std::string& texte, int hauteur, int largeur, int posx, int posy);
    // afficher images
    void afficherImages();


public:
    // Render window
    sf::RenderWindow m_window;

    int height;
    int width;
    std::string title;

    // Font
    sf::Font m_font;

    // Textures et sprites pour images
    //std::vector<sf::Texture> m_textures;
    //std::vector<sf::Sprite> m_sprites;
    sf::Texture m_texture;
    sf::Sprite m_sprite;
};
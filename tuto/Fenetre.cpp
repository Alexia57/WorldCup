#include "Fenetre.hpp"

bool Fenetre::estOuverte() const
{
    return m_window.isOpen();
}

bool Fenetre::isEvenement(sf::Event& event)
{
    return m_window.pollEvent(event);
}

void Fenetre::gererEvenements(sf::Event event)
{
    // close window
    if (event.type == sf::Event::Closed)
        m_window.close();
    // resize widow
    if (event.type == sf::Event::Resized)
    {
        std::cout << "new width: " << event.size.width << std::endl;
        std::cout << "new height: " << event.size.height << std::endl;
    }
}

void Fenetre::clear(const sf::Color& couleur) 
{
    m_window.clear(couleur);
}

void Fenetre::dessiner(const sf::Drawable& dessin) 
{
    m_window.draw(dessin);
}

void Fenetre::toutDessiner()
{
    std::cout << "tout est dessiné" << std::endl;
}

void Fenetre::afficher()
{
    m_window.display();
}

void Fenetre::fermer()
{
    m_window.close();
}

sf::RenderWindow* Fenetre::obtenirFenetre()
{
    return &m_window;
}

void Fenetre::ajouterImage(const std::string& texte, int posx, int posy, int hauteur, int largeur)
{
    //sf::Texture texture;
    //sf::Sprite sprite;
    if (!m_texture.loadFromFile(texte, sf::IntRect(0, 0, hauteur, largeur)))
    {
        std::cout << "Erreur loading img\n";
    }
    m_texture.setSmooth(true);
    m_sprite.setTexture(m_texture);
    m_sprite.scale(sf::Vector2f(0.5f, 0.5f));
    m_sprite.setPosition(posx, posy);

    //m_textures.push_back(texture);
    //m_sprites.push_back(sprite);
}

void Fenetre::afficherImages()
{
    m_window.draw(m_sprite);
    /*for (std::size_t i = 0; i < m_sprites.size(); i++)
    {
        m_window.draw(m_sprites[i]);
    }*/
}
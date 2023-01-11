#include <SFML/Graphics.hpp>
#include <functional>
#include <memory>
#include "Fenetre.hpp"
#include "FenetreQuiz.hpp"
#include "FenetreMenu.hpp"

#define WIDTH 800
#define HEIGHT 600

int main()
{
    FenetreMenu menu(WIDTH, HEIGHT, "Objectif : Coupe du Monde");
    //menu.clear(sf::Color::White);
    menu.ajouterImage("images/cheval_fond_noir3.png", 200, 300, 1000, 600);
    //std::cout << "image crée" << std::endl;
    menu.ajouterBouton("Reviser", 340, 120, []{ std::cout << "Bouton 'Reviser' cliqué !" << std::endl; });
    menu.ajouterBouton("Quiz", 340, 120, []{ std::cout << "Bouton 'Quiz' cliqué !" << std::endl; });
    //menu.ajouterBouton("Options", []{ std::cout << "Bouton 'Options' cliqué !" << std::endl; });
    menu.ajouterBouton("Quitter", 340, 120, []{ std::cout << "Bouton 'Quitter' cliqué !" << std::endl; });
    while (menu.estOuverte())
    {
        sf::Event event;
        while (menu.isEvenement(event))
        {
            menu.gererEvenements(event);
        }
        menu.afficherImages();
        //std::cout << "taille sprite: "<< menu.m_sprites.size() << std::endl;
        //menu.m_window.draw(*menu.m_sprites[0]);
        menu.afficherBoutons();
        menu.afficher();
    }

    return 0;   
}

/*
int main()
{
    FenetreMenu fenetreMenu(WIDTH, HEIGHT, "Mon menu");

    std::vector<std::tuple<std::string, std::vector<std::string>>> quizzes =
    {
        { "Qui est Bosty ?",
          {"Un cheval", "Une marque de sellerie", "Un cavalier", "Un nom de concours"} },
        { "Quelle est la plus grande hauteur jamais sautée par un cheval?",
          {"1m10", "1m47", "2m10", "2m47"} },
        { "Combien de mois dure la gestation d'une jument?",
          {"9", "10", "11", "12"} }
    };

    while (fenetreMenu.estOuverte())
    {
        sf::Event event;
        while (fenetreMenu.isEvenement(event))
        {
            fenetreMenu.gererEvenements(event);
        }
        fenetreMenu.dessiner();
        fenetreMenu.afficher();
    }

    return 0;
}*/

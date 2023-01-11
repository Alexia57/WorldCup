#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Page
{
public:
    // constructeur par copie
    Page(const Page& page)
    : _page(sf::VideoMode(page._height, page._width), page._title)
    {
        _height = page._height;
        _width = page._width;
        _title = page._title;
    }
    
    // constructeur par paramètres
    Page(int height, int width, const std::string& title)
    : _page(sf::VideoMode(height, width), title)
    {
        _height = height;
        _width = width;
        _title = title;
    }
    
    // destructeur
    ~Page()
    {
        
    }

    // initialiser page
    void initialize();

    // afficher page
    void display();

    // fermer page
    void close();
    
    
private:
    sf::RenderWindow _page;
    int _height;
    int _width;
    std::string _title;
};
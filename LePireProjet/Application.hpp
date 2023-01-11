#pragma once

#include <iostream>
#include <memory>

#include "Page.hpp"

class Application
{
public:
    // fonction principale qui lance l'app
    void run();

private:
    // initialise l'app
    void initialize();
    // ferme l'app
    void shutdown();
    // met à jour et dessine l'app
    void frame();
    
    bool _running = true;
    Page* _currentPage;
    
};
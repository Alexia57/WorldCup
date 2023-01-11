#include "Application.hpp"
#include <chrono>
#include <ctime>
#include <unistd.h>


// fonction principale qui lance l'app
void Application::run()
{
    std::cout << "Running" << std::endl;
    initialize();
    int count = 0;
    while (_running && count<100)
    {
        frame();
        count ++;
    }
    shutdown();
}


// initialise l'app
void Application::initialize()
{
    std::cout << "Initialisation" << std::endl;
    Page* pagetest = new Page(400, 200, "Tadaaaa");
    std::cout << "construit" << std::endl;
    _currentPage = pagetest;
    std::cout << "reset" << std::endl;
    _currentPage->initialize();
    std::cout << "initialise2" << std::endl;
}

// ferme l'app
void Application::shutdown()
{
    std::cout << "Shut down" << std::endl;
    _currentPage->close();
    std::cout << "Shut down en cours" << std::endl;
    delete _currentPage;
    std::cout << "Shut down fini" << std::endl;
    _currentPage = NULL;
}

// met à jour et dessine l'app
void Application::frame()
{
    //std::cout << "Frame" << std::endl;
    _currentPage->display();
    usleep(10000);
    
}



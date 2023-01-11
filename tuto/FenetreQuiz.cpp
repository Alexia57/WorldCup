#include "FenetreQuiz.hpp"

/*
void FenetreQuiz::afficherQuestion(const std::string& question,
                          const std::vector<std::string>& reponses)
{
    m_question.setString(question);
    m_question.setFont(m_font);
    m_question.setCharacterSize(24);
    m_question.setFillColor(sf::Color::Black);
    m_question.setPosition(20.0f, 20.0f);

    for (size_t i = 0; i < reponses.size(); i++)
    {
        sf::Text reponse;
        reponse.setString(reponses[i]);
        reponse.setFont(m_font);
        reponse.setCharacterSize(24);
        reponse.setFillColor(sf::Color::Black);
        reponse.setPosition(20.0f, 70.0f + 40.0f * i);
        m_reponses.push_back(reponse);
    }
}

void FenetreQuiz::gererEvenements(sf::Event event) 
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

void FenetreQuiz::clear(const sf::Color& couleur) 
{
    Fenetre::clear(couleur);
    m_reponses.clear();
}
*/
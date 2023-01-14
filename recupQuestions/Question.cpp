#include "Question.hpp"

// constructeurs
Question::Question(){}

Question::Question(std::string question, std::list<std::string> propositions, std::string reponse)
{
    this->_question = question;
    this->_reponse = reponse;
    this->_propositions = propositions;
}
Question::Question(std::string question, std::string p1, std::string p2, std::string p3, std::string p4, std::string reponse)
{
    this->_question = question;
    this->_reponse = reponse;
    this->_propositions = {p1, p2, p3, p4};
}


// fonctions
std::string Question::get_question()
{
    return this->_question;
}

std::list<std::string> Question::get_propositions()
{
    return this->_propositions;
}

std::string Question::get_reponse()
{
    return this->_reponse;
}

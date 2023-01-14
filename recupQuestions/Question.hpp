#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <sstream>

class Question
{
public:
    // constructeurs
    Question();
    Question(std::string question, std::list<std::string> propositions, std::string reponse);
    Question(std::string question, std::string p1, std::string p2, std::string p3, std::string p4, std::string reponse);

    // fonctions

    // return la question
    std::string get_question();
    // return la liste des propositions
    std::list<std::string> get_propositions();
    // return la reponse
    std::string get_reponse();

private:
    std::string _question;
    std::list<std::string> _propositions;
    std::string _reponse;
    // maybe size_t pour le nombre de props
    // un id de la question
};
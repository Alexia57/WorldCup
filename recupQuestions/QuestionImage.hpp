#pragma once
#include <iostream>
#include <vector>
#include <list>
#include "Question.hpp"

class QuestionImage : public Question
{
public:
    // constructeurs
    QuestionImage();
    QuestionImage(std::string question, std::list<std::string> propositions, std::string reponse);
    QuestionImage(std::string question, std::string p1, std::string p2, std::string p3, std::string p4, std::string reponse);

    // fonctions

    // return la question
    std::string get_question();
    // return la liste des propositions
    std::list<std::string> get_propositions();
    // return la reponse
    std::string get_reponse();

private:
    std::list<std::string> images; //nom de l'image + chemin
};
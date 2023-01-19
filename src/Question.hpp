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
    Question(std::string question, std::vector<std::string> propositions, std::string answer);
    Question(std::string question, std::string p1, std::string p2, std::string p3, std::string p4, std::string answer);

    // fonctions

    // return la question
    const std::string &get_question() const;
    // return le tableau des propositions
    std::vector<std::string> &get_propositions();
    // return la reponse
    const std::string &get_answer() const;

    

private:
    std::string _question;
    std::vector<std::string> _propositions;
    std::string _answer;

    
};
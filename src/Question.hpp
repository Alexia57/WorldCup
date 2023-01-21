#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <sstream>

class Question
{
private:
    std::string _question; // question
    std::vector<std::string> _propositions; // vector of propositions
    std::string _answer; // answer
public:
    /* Constructors */
    Question();
    Question(std::string question, std::vector<std::string> propositions, std::string answer);
    Question(std::string question, std::string p1, std::string p2, std::string p3, std::string p4, std::string answer);

    /* Accessor */
    // return the question
    const std::string &get_question() const;
    // return the propositions
    std::vector<std::string> &get_propositions();
    // return the answer
    const std::string &get_answer() const;

    /* Operator */
    Question &operator+(std::string proposition);
    friend std::ostream& operator<<(std::ostream& os, const Question& question);
};

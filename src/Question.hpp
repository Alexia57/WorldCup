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
    const std::vector<std::string> &get_propositions() const;
    // return la reponse
    const std::string &get_answer() const;

    // return le booleen de présence d'image
    const bool &isImage() const;
    // return le nom de l'image
    const std::string &get_image() const;
    // return le chemin de l'image
    const std::string &get_pathImage() const;
    
    const bool &isImageVertical() const;

private:
    std::string _question;
    std::vector<std::string> _propositions;
    std::string _answer;

    std::string _image; // nom de l'image 
    std::string _pathImage; // chemin de l'image
    bool _isVertical; // 1 si l'image est vertical et 0 si horizontal
    // un id de la question ?
};
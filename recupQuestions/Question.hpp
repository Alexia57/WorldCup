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

    // return le booleen de présence d'image
    std::string get_isImage();
    // return le nom de l'image
    std::string get_image();
    // return le chemin de l'image
    std::string get_chemin();

private:
    std::string _question;
    std::list<std::string> _propositions;
    std::string _reponse;
    bool isImage ; // 1 si il y a une image 0 sinon
    std::string image; // nom de l'image 
    std::string chemin; // chemin de l'image
    bool estVertical; // 1 si l'image est vertical et 0 si horizontal
    // un id de la question ?
};
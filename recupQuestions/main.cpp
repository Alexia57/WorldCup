#include "Question.hpp"
#include <iostream>
#include <list>
#include "usefull.hpp"
//#include "src/pugixml.hpp"

int main() {
    std::vector<Question> questions = parseXML("questions.xml");
    for (auto& question : questions) {
        std::cout << question.get_question() << std::endl;
        for (auto& prop : question.get_propositions()) {
            std::cout << prop << std::endl;
        }
        std::cout << question.get_reponse() << std::endl;
    }
    return 0;
}


/*
int main()
{
    std::list<std::string> propositions = {"Noire", "Grise", "Blanche", "Baie"};
    Question q1("Quelle est la couleur de la robe du cheval blanc d'Henri IV ?", propositions, "Grise");
    Question q2("Quelle est la capitale de France?", "Paris", "Marseille", "Lyon", "Toulouse", "Paris");

    std::cout << "Question : " << q1.get_question() << std::endl;
    std::cout << "Propositions : ";
    for(auto proposition : q1.get_propositions())
        std::cout << proposition << " ";
    std::cout << std::endl << "Réponse : " << q1.get_reponse() << std::endl;

    std::cout << "Question : " << q2.get_question() << std::endl;
    std::cout << "Propositions : ";
    for(auto proposition : q2.get_propositions())
        std::cout << proposition << " ";
    std::cout << std::endl << "Réponse : " << q2.get_reponse() << std::endl;

    return 0;
}*/
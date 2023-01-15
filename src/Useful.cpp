#include "Useful.hpp"

// compare si 2 listes sont identiques et return true si oui
bool compare_lists(std::list<std::string> lst1, std::list<std::string> lst2){
    if(lst1.size() != lst2.size()) return false;
    auto it1 = lst1.begin();
    auto it2 = lst2.begin();
    for(; it1 != lst1.end(); it1++, it2++){
        if(*it1 != *it2) return false;
    }
    return true;
}

// fonction pour récupérer les données d'un fichier XML dans des variables de la classe Question
std::vector<Question> parseXML(const std::string& fileName) {
    std::vector<Question> questions;
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(fileName.c_str());
    if (!result) {
        std::cerr << "Error parsing XML file: " << result.description() << std::endl;
        return questions;
    }
    pugi::xml_node questionsNode = doc.child("questions");
    for (pugi::xml_node questionNode : questionsNode.children("question")) {
        std::string question = questionNode.child_value("text");
        std::list<std::string> propositions;
        for (pugi::xml_node propNode : questionNode.children("proposition")) {
            propositions.push_back(propNode.child_value());
        }
        std::string reponse = questionNode.child("reponse").child_value();
        questions.push_back(Question(question, propositions, reponse));
    }
    return questions;
}
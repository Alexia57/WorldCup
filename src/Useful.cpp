#include "Useful.hpp"
#include <dirent.h>
#include <fnmatch.h>

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

std::vector<std::string> getFileNames(const std::string &pathDir, const std::string &pattern) {
    std::vector<std::string> files;
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(pathDir.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (fnmatch(pattern.c_str(), ent->d_name, 0) == 0) {
                files.push_back(ent->d_name);
            }
        }
        closedir(dir);
    } else {
        std::cout << "Could not open directory" << std::endl;
    }
    return files;
}

// fonction pour récupérer les données d'un fichier XML dans des variables de la classe Question
void parseXML(const std::string& fileName, std::list<Question> &questions) {

    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(fileName.c_str());

    if (!result) {
        std::cerr << "Error parsing XML file: " << result.description() << std::endl;
    }

    pugi::xml_node questionsNode = doc.child("questions");
    for (pugi::xml_node questionNode : questionsNode.children("question")) {
        std::string question = questionNode.child_value("text");
        
        std::vector<std::string> propositions;
        for (pugi::xml_node propNode : questionNode.children("proposition")) {
            propositions.push_back(propNode.child_value());
        }
        std::string reponse = questionNode.child("reponse").child_value();
        questions.push_back(Question(question, propositions, reponse));
    }
    
}

sf::String UTF8_to_UTF32(std::string str){
    return sf::String::fromUtf8(str.begin(),str.end());
}

void printRect(sf::FloatRect rect){
    std::cout << "top = "<< rect.top << " | left = " << rect.left << " | height = " << rect.height << " | width = " << rect.width << std::endl;
}
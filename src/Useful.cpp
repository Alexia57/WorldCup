#include "Useful.hpp"
#include <dirent.h>
#include <fnmatch.h>


bool isEqual_vectString(std::vector<std::string> vect1, std::vector<std::string> vect2){
    if(vect1.size() != vect2.size()) return false;

    std::vector<std::string>::const_iterator it1, it2; 
    for(it1 = vect1.begin(), it2 = vect2.begin(); it1 != vect1.end(); it1++, it2++){
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
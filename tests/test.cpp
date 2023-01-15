// Let Catch provide main():
#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include <list>
// your includes here
#include "../src/Question.hpp"
#include "../src/usefull.hpp"
//#include "../src/pugixml.hpp"


TEST_CASE("1: Class Question"){
  std::list<std::string> categories;
  categories.push_back("Nom");
  categories.push_back("Alias");

  std::list<std::string> propositions = {"Noire", "Grise", "Blanche", "Baie"};
  Question q1("Quelle est la couleur de la robe du cheval blanc d'Henri IV ?", propositions, "Grise");
  Question q2("Quelle est la capitale de France?", "Paris", "Marseille", "Lyon", "Toulouse", "Paris");

  CHECK(q1.get_question() == "Quelle est la couleur de la robe du cheval blanc d'Henri IV ?");
  CHECK(q1.get_reponse() == "Grise");
  CHECK(compare_lists(q1.get_propositions(), propositions));
  CHECK(compare_lists(q2.get_propositions(), {"Paris", "Marseille", "Lyon", "Toulouse"}));
}

TEST_CASE("2: Récupération des questions.xml"){
  std::vector<Question> questions = parseXML("questionstest.xml");
  // check si questions contient bien 3 questions 
  CHECK(questions.size() == 3);

  // check les éléments de la première question
  CHECK(questions[0].get_question() == "Quel est le nom de la partie n°10 de la selle?");
  CHECK(questions[0].get_reponse() == "Troussequin");
  CHECK(compare_lists(questions[0].get_propositions(), {"Quartier", "Pommeau", "Siège", "Troussequin"}));
}
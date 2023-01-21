// Let Catch provide main():
#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include <list>
// your includes here
#include "../src/Question.hpp"
//#include "../src/pugixml.hpp"
#include "../src/Useful.hpp"


TEST_CASE("1: Class Question"){
  
  /* Test constructeur */
  std::vector<std::string> propositions = {"Noire", "Grise", "Blanche", "Baie"};
  Question q1("Quelle est la couleur de la robe du cheval blanc d'Henri IV ?", propositions, "Grise");
  Question q2("Quelle est la capitale de France?", "Paris", "Marseille", "Lyon", "Toulouse", "Paris");

  /* Test allocation */
  Question *i_quest;
  for(int i = 0; i < 100; i++){
    i_quest = new Question(q1);
    delete i_quest;
  }

  /* Test Accessor */
  CHECK(q1.get_question() == "Quelle est la couleur de la robe du cheval blanc d'Henri IV ?");
  CHECK(isEqual_vectString(q1.get_propositions(), propositions));
  CHECK(q1.get_answer() == "Grise");
  CHECK(isEqual_vectString(q2.get_propositions(), {"Paris", "Marseille", "Lyon", "Toulouse"}));

  /* Test operator */
  Question q3 = q2 + "Montpellier";
  CHECK(isEqual_vectString(q3.get_propositions(), {"Paris", "Marseille", "Lyon", "Toulouse", "Montpellier"}));
  std::cout << q3;
}

TEST_CASE("2: Récupération des questions.xml"){

  /* Test Method parseXML */
  std::list<Question> questions;
  parseXML("questionstest.xml", questions);

  // check si questions contient bien 3 questions 
  CHECK(questions.size() == 3);

  // check les éléments de la première question
  CHECK(questions.front().get_question() == "Quel est le nom de la partie n°10 de la selle?");
  CHECK(questions.front().get_answer() == "Troussequin");
  CHECK(isEqual_vectString(questions.front().get_propositions(), {"Quartier", "Pommeau", "Siège", "Troussequin"}));

  /* Print result */
  std::cout << "Print questions :" << std::endl;
  int i = 1;
  for (std::list<Question>::iterator it = questions.begin(); it != questions.end(); it++, i++){
    std::cout << i << " - " << (*it);
  }
}
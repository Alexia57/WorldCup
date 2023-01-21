#include "Question.hpp"

Question::Question(){}

Question::Question(std::string question, std::vector<std::string> propositions, std::string answer)
{
    this->_question = question;
    this->_answer = answer;
    this->_propositions = propositions;
}
Question::Question(std::string question, std::string p1, std::string p2, std::string p3, std::string p4, std::string answer)
{
    this->_question = question;
    this->_answer = answer;
    this->_propositions = {p1, p2, p3, p4};
}

const std::string &Question::get_question() const
{
    return this->_question;
}

std::vector<std::string> &Question::get_propositions()
{
    return this->_propositions;
}

const std::string &Question::get_answer() const
{
    return this->_answer;
}

Question &Question::operator+(std::string proposition){
    this->_propositions.push_back(proposition);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Question& question)
{
    os << "Question : " << question.get_question() << std::endl;
    os << "Proposition :" << std::endl;
    for(std::vector<std::string>::const_iterator it = question._propositions.begin(); it != question._propositions.end(); it++){
        os << (*it) << std::endl;
    }
    os << "Réponse : " << question.get_answer() << std::endl;
    return os;
}

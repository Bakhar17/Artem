#include "Question.h"

Question::Question(std::string question_, int k_, bool qtype_, std::vector<std::string> answer_) : question(question_), k(k_), qtype(qtype_), answers(answer_)
{
}
Question::~Question()
{
}
void Question::SetQuestion(const std::string name) {
	this->question = name;
}
void Question::SetNumber(const int number) {
	this->k = number;
}
void Question::SetType(const bool type) {
	this->qtype = type;
}
void Question::SetAnswers(const std::vector<std::string>& temp) {
	this->answers = temp;
}

const std::string Question::GetQuestion()const {
	return this->question;
}
const int Question::GetNumber()const {
	return this->k;
}
const bool Question::GetType() const{
	return this->qtype;
}
const std::vector<std::string> Question::GetAnswers() const {
	return this->answers;
}
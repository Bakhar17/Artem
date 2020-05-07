#ifndef QUESTION_
#define QUESTION_
#include <string>
#include <vector>

class Question
{
public:
	Question(std::string,int,bool,std::vector<std::string>);
	void SetQuestion(const std::string);
	void SetNumber(const int);
	void SetType(const bool);
	void SetAnswers(const std::vector<std::string>&);
	const std::string GetQuestion()const;
	const int GetNumber()const ;
	const bool GetType()const;
	const std::vector<std::string> GetAnswers() const;
	~Question();

private:
	std::string question;
	int k;//number of answers
	bool qtype;//type of question 
	std::vector<std::string> answers;
};


#endif // !QUESTION_

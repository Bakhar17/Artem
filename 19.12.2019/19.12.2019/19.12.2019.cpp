#include <iostream>
#include <string>
using namespace std;
class Student
{
protected:
	int number;
public:
	Student(int value) : number(value) {	}
	virtual ~Student() {}	
	virtual const int getNumber() const {
		return this->number;
	}
};

class Wave1 : public Student
{
protected:
	string m_name;

public:
	Wave1(int value, string name) : Student(value), m_name(name) {	}
	const string& getName() { return m_name; }
};

class Wave2 : public Student
{
protected:
	std::string m_name;

public:
	Wave2(int value, string name) : Student(value), m_name(name) {	}
	const string& getName() { return m_name; }
};


class Wave3: public Student
{
protected:
	std::string m_name;

public:
	Wave3(int value, string name) : Student(value), m_name(name) {	}
	const string& getName() { return m_name; }
};


class Wave4 : public Student
{
protected:
	std::string m_name;

public:
	Wave4(int value, string name) : Student(value), m_name(name) {	}
	const string& getName() { return m_name; }
};
Student* getObject(int n)
{
	switch (n) {
	case(1): return new Wave1(n, "Serge"); break;
	case(2):return new Wave2(n, "Kesha"); break;
	case(3):return new Wave3(n, "GoodBoy"); break;
	case(4):return new Wave4(n, "Serzhant"); break;
	default:return new Student(1);
	}
}

int main()
{
	Student* p = getObject(3);
	Wave3* ch = dynamic_cast<Wave3*>(p);
	// используем dynamic_cast для конвертации указателя класса Parent в указатель класса Child
	if (ch) // выполняем проверку ch на нулевой указатель
		std::cout << "The number of the stage is: " << ch->getNumber() <<"\t"<<ch->getName()<< '\n';
	delete p;
	return 0;
}


#pragma once
#include <iostream>
#include <string>

class Train
{
public:
	Train();
	~Train();
	Train(std::string place,int number, char e);
	Train(const Train&);
	void WhereTo(std::string q);
	friend std::istream& operator>>(std::istream&, Train&);
	friend std::ostream& operator<<(std::ostream&, const Train&);
	const std::string GetPlace() const { return this->place; };
	bool If_E();
	//Train operator=(const Train tr) {
	//	this->place = tr.place;
	//	this->number = tr.number;
	//	this->e = tr.e;
	//	return *this;
	//}

private:
	std::string place;
	int number;
	bool e;
};
Train::Train() {

}
Train::Train(std::string place, int number, char e) : place(place), number(number), e(e)
{

}
Train::Train(const Train& obj) : place(obj.place), number(obj.number), e(obj.e) {

}
std::istream& operator>>(std::istream& in, Train& train)
{
	in >> train.place >> train.number >> train.e;
	return in;
}
std::ostream& operator<<(std::ostream& out, const Train& train)
{
	out << train.place <<" "<< train.number <<" "<< train.e << "\n";
	return out;
}
Train::~Train()
{
}

void Train::WhereTo(std::string q)
{
	if (this->place == q) 
	{
	std::cout<<*this;
	}

}

bool Train::If_E()
{
	return e != 0;
}
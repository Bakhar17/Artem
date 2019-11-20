#pragma once
#include <string>
#include <iostream>
class Animal
{
public:
	Animal();
	Animal(std::string name,std::string place,int number);
	~Animal();
	friend std::istream& operator>>(std::istream& in, Animal& an);
	friend std::ostream& operator<<(std::ostream& on, const Animal& an);
	Animal( const Animal& an) :name(an.name), place(an.place), number(an.number) {
	}
	bool operator<(const Animal _Right) const {
		return this->name < _Right.name;
	}
	std::string name, place;
	int number;
};

Animal::Animal()
{
}

Animal::~Animal()
{
}
Animal::Animal(std::string _name, std::string _place, int _number):name(_name),place(_place),number(_number) {

}
std::istream& operator>>(std::istream& in, Animal& an) {
	in >> an.name >> an.place >> an.number;
	return in;
}
std::ostream& operator<<(std::ostream& on,const Animal& an) {
	on<< an.name <<" "<< an.place<<" "<< an.number<<"\n";
	return on;
}
bool operator<(Animal& xn, Animal& an) {
	if (xn.name < an.name) {
		return true;
	}
	else
		return false;
}
#pragma once
#include <string>
#include <iostream>
#include <sstream>
using std::cin;
using std::cout;
using std::string;
class Flower
{
public:
	Flower() = default;
	virtual ~Flower();
	virtual std::ostream& Print();
	virtual void Read(std::istringstream&);
	friend std::ostream& operator<<(std::ostream&, Flower*);
	string GetName()const { return name; }
	string GetColour()const { return colour; }
	int GetDays()const { return days; }
	double GetPrice()const { return price; }
	void set_name(const string& new_name) { name = new_name; }
	bool operator<(const Flower* & a) const {
		return this->price < a->price;
	}
private:
	string name;
	string colour;
	int days;
	double price;
};
Flower::~Flower()
{
}
std::ostream& Flower::Print()
{
	cout << "name: " << name << " | " << "colour: " << colour << " | " << "days: " << days << " | " << "price: " << price;
	return cout;
}

void Flower::Read(std::istringstream& in)
{
	in >> name >> colour >> days >> price;
}
std::ostream& operator<<(std::ostream& out, Flower* sweet)
{
	(*sweet).Print();
	return out;
}
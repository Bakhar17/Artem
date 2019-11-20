#pragma once
#include <set>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
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
	friend std::string BigName(std::multiset<Animal>& b);
	friend std::string Areal(std::multiset<Animal>& a,Animal b);
	friend void SortPlace(std::multiset<Animal>& a);
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

std::string BigName(std::multiset<Animal>& bc) {
	std::set<std::pair<std::string, int>> place;
	std::multiset<Animal>::iterator b = bc.begin();
	while (b != bc.end()) {
		int n = 0;
		for (std::multiset<Animal>::iterator i = b; i != bc.end(); i++)
	{
			if (b->place == i->place) {
				n++;
		}
	}
		place.emplace(b->place, n);
		b++;
	}
	b = bc.begin();
	std::set<std::pair<std::string, int>>::iterator k = --place.end();
	return k->first;
}
std::string Areal(std::multiset<Animal>& a, Animal b) {
	std::multiset<Animal>::iterator g = a.lower_bound(b);
	for (std::multiset<Animal>::iterator i = a.lower_bound(b); i != a.upper_bound(b); i++) {
		if (g->number >= i->number) {
			g = i;
		}
	}
	return g->place;
}
void SortPlace(std::multiset<Animal>& a) {
	std::set<std::string> places;
	for (std::multiset<Animal>::iterator i = a.begin(); i !=a.end(); i++)
	{
		places.insert(i->place);
	}
	std::set<std::string>::iterator i = places.begin();
	while (i != places.end()) {
		for (std::multiset<Animal>::iterator k = a.begin(); k != a.end(); k++)
		{
			if (*i == k->place) {
				std::cout << *k << "\n";
			}
		}
		i++;
	}
}
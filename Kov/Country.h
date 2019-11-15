#pragma once
#include <iostream>
#include <string>
#include <map>
class Country
{
public:
	Country();
	Country(std::string name, std::string code, std::map<int, long long int> pop) :name(name), code(code), popul (pop) {}
	~Country();
	Country(const Country& a):name(name),code(code),popul(popul){}
	friend std::string ToString(Country& a) {
		std::string result;
		result = a.name + " (" + a.code + ") :";
	/*	std::cout << a.name << " " << '(' << a.code << ')' << " :" << " ";*/
		for (std::map<int, long long int>::iterator i = a.popul.begin(); i != a.popul.end(); i++) {
			result+= std::to_string(i->second) + "[" + std::to_string(i->first) + "], ";
		}
		return result;
	}

private:
	std::string name;
	std::string code;
	std::map<int, long long int> popul;
	
};

Country::Country()
{
}

Country::~Country()
{
}
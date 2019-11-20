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
	friend void WhereTo(Train& wh, std::string q);
	friend std::istream& operator>>(std::istream&, Train&);
	friend std::ostream& operator<<(std::ostream&,  Train&);
	friend void WhereToE(Train& wh, std::string q);

private:
	std::string place;
	int number;
	char e;
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
std::ostream& operator<<(std::ostream& out, Train& train)
{
	out << train.place <<" "<< train.number <<" "<< train.e << "\n";
	return out;
}
Train::~Train()
{
}

void WhereTo(Train& wh,std::string q)
{
	if (wh.place == q) 
	{
	std::cout<<wh;
	}

}

void WhereToE(Train& wh, std::string q)
{
	if (wh.place == q&& wh.e=='+')
	{
		std::cout << wh;
	}
}
#ifndef ROUTE_H
#include <string>
#include <utility>
#include <iostream>
class Route
{
public:
	Route(std::pair<int,std::string>,std::string,int);
	~Route();
	const std::pair<int, std::string> GetBus()const  { return this->bus; }
	const int GetRoute()const { return this->RouteNumber; }
	const std::string GetSurname()const  { return this->Surname; }
	void SetBus(std::pair<int, std::string> nbus);
	void SetRoute(int);
	void SetSurname(std::string);
private:
	std::pair<int, std::string> bus;
	std::string Surname;
	int RouteNumber;

};

std::string ToString(const Route&);
#endif // !ROUTE_H



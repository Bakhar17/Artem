#include "Route.h"

Route::Route(std::pair<int, std::string> bus_, std::string Surname_, int route_) :bus(bus_), Surname(Surname_), RouteNumber(route_) {}


Route::~Route()
{
}

std::string ToString(const Route& route) {
	std::string temp;
	temp = std::to_string(route.GetBus().first) + " " + route.GetBus().second + " " + route.GetSurname()+" "+ std::to_string(route.GetRoute())+"\n";
	return temp;
}

void Route::SetBus(std::pair<int, std::string> nbus) {
	bus = nbus;
}
void Route::SetRoute(int nRouteNumber) {
	RouteNumber = nRouteNumber;
}
void Route::SetSurname(std::string nSurname) {
	Surname = nSurname;
}
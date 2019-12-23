// MultiNasled.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <fstream>
#include <sstream>
#include <memory>
#include "Flights.h"
#include <vector>


using std::vector;
void Add_Pilot(vector<std::shared_ptr<Pilot>>& pilots);
void Add_Plane(vector<std::shared_ptr<AirPlane>>& planes);
void Add_Flight(vector<std::shared_ptr<Flight>>& flights, vector<std::shared_ptr<Pilot>>& pilots, vector<std::shared_ptr<AirPlane>>& planes);
int main()
{
    std::cout << "Hello World!\n";
	std::ifstream fin_pilot("Pilot.txt");
	std::ifstream fin_plane("Plane.txt");
	std::ifstream fin_flight("Flight.txt");


	// Pilots initialisation 
	vector<std::shared_ptr<Pilot>> pilots;
	while (!fin_pilot.eof()) {
		string pi;
		getline(fin_pilot, pi);
		std::istringstream temp(pi);
		std::shared_ptr<Pilot> ptr_pilot (new Pilot);
		ptr_pilot->Read(temp);

		pilots.push_back(ptr_pilot);

	}
	fin_pilot.close();

	
	// Planes initialisation 
	vector<std::shared_ptr<AirPlane>> planes;
	while (!fin_plane.eof()) {
		string pi;
		getline(fin_plane, pi);
		std::istringstream temp(pi);
		std::shared_ptr<AirPlane> ptr_plane(new AirPlane);
		ptr_plane->Read(temp);
		planes.push_back(ptr_plane);
	}
	fin_plane.close();
	
	//Flights initialisation 
	vector<std::shared_ptr<Flight>> flights;
	while (!fin_flight.eof()) {
		string pi;
		getline(fin_flight, pi);
		std::istringstream temp(pi);
		std::shared_ptr<Flight> ptr_flight(new Flight);
		ptr_flight->Read(temp);

		flights.push_back(ptr_flight);

	}
	fin_flight.close();
	Add_Pilot(pilots);
	for (size_t i = 0; i < size(pilots); i++)
	{
		pilots[i]->Print();
	}
	Add_Flight(flights,pilots,planes);

	for (size_t i = 0; i < size(flights); i++)
	{
		flights[i]->Print();
	}
	Add_Plane(planes);
	for (size_t i = 0; i < size(planes); i++)
{
	planes[i]->Print();
}
	Delete_Pilot(pilots);
	for (size_t i = 0; i < size(pilots); i++)
	{
		pilots[i]->Print();

	}
	Delete_Plane(planes);
	Delete_Flight(flights);
	for (size_t i = 0; i < size(flights); i++)
	{
		flights[i]->Print();
	}
	Find_Pilot(flights,pilots);
	Find_Plane(flights, planes);
	ChangeInfo(flights,pilots,planes);
}





#pragma once
#include "Pilot.h"
#include "AirPlane.h"


class Flight : public Pilot, public AirPlane
{
public:
	Flight()=default;
	~Flight();
	std::ostream& Print();
	void Read(std::istream&);
	bool Check();
	void Read(std::istream& in, int n);
	friend void Delete_Flight(vector<std::shared_ptr<Flight>>&);
	friend void Find_Pilot(vector<std::shared_ptr<Flight>>&, vector<std::shared_ptr<Pilot>>&);
	friend void Find_Plane(vector<std::shared_ptr<Flight>>&, vector<std::shared_ptr<AirPlane>>&);
	friend void ChangeInfo(vector<std::shared_ptr<Flight>>&, vector<std::shared_ptr<Pilot>>& , vector<std::shared_ptr<AirPlane>>&);
private:
	int flight_number=0;
	string date_in;
	string date_out;
	double km=0;
	double flight_cost=0;
	string place_out;
	string place_in;
	int stops=0;
	int tickets=0;
	double size=0;
};


Flight::~Flight()
{
}
void Flight::Read(std::istream& in) {
	in >> flight_number >> date_in >> date_out >> name >> number >> brand >> km >> flight_cost >> place_out >> place_in >> stops >> tickets >> size;
}
std::ostream& Flight:: Print() {
	cout << "\n|flight_number: " << flight_number << " |date of in: " << date_in << " |date of out: " 
		<< date_out << " |pilot's name: " << name << " |plane's number: " << number << " |brand: " 
		<< brand << " |mileage: " << km << " |flight cost: " << flight_cost << " |place of out: " 
		<< place_out << "|place of in: " << place_in << " |number of stops: " << stops << " |saled tickets: " 
		<< tickets << " |size: " << size << "\n";
	return cout;
}
bool Flight::Check() {
	if (flight_number != 0 && date_in != "" && date_out != "" && place_in != "" && place_out != "") {
		return 1;
	}
	else return 0;
}
void Flight::Read(std::istream& in,int n) {
	flight_number=(n + 1);
	in >> date_in >> date_out >> name >> number >> brand >> km >> flight_cost >> place_out >> place_in >> stops >> tickets >> size;
}

void Add_Flight(vector<std::shared_ptr<Flight>>& flights, vector<std::shared_ptr<Pilot>>& pilots, vector<std::shared_ptr<AirPlane>>& planes) {
	string pi;
	int n = size(flights);
	cout << "\nWrite a new flight using next example(in one line):\n|date of in: |date of out: |pilot's name: |plane's number: |brand: |mileage: |flight cost: |place of out: |place of in: |number of stops: |saled tickets: |size: \n";
	cout << "\nYou can use next pilots:\n\n";
	for (size_t i = 0; i < size(pilots); i++)
	{
		pilots[i]->Print();
	}
	cout << "\n You can use next planes:\n\n";
	for (size_t i = 0; i < size(planes); i++)
	{
		planes[i]->Print();
	}
	getline(cin, pi);
	std::istringstream temp(pi);
	std::shared_ptr<Flight> ptr_flight(new Flight);
	ptr_flight->Read(temp, n);
	while (!ptr_flight->Check() && !ptr_flight->Check_Name(pilots) && !ptr_flight->Check_Plane(planes)) {
		cout << "Something went wrong! Please, try again!\n";
		getline(cin, pi);
		std::istringstream temp(pi);
		std::shared_ptr<Flight> ptr_flight(new Flight);
		ptr_flight->Read(temp, n);
	}
	flights.push_back(ptr_flight);
	std::ofstream fout("Flight.txt", std::ios_base::app);
	fout << "\n" << n + 1 << " " << pi;
	fout.close();
}


void Delete_Flight(vector<std::shared_ptr<Flight>> & flights) {
	int flight_number;
	vector<std::shared_ptr<Flight>>::iterator i;
	for (i = flights.begin(); i != flights.end(); i++)
	{
		(*i)->Print();
	}
	cout << "Choose a flight's number you'd like to delete: ";
	cin >> flight_number;
	int sizer = (size(flights));
	for (i = flights.begin(); i != flights.end(); i++)
	{
		if ((*i)->flight_number == flight_number) {
			flights.erase(i);
			break;
		}
	}
	if (sizer == flights.size()) {
		cout << "Flight hasn't been found!\n";
		return;
	}
	std::fstream fout("Flight.txt", std::ios_base::out);
	size_t k;
	string fl;
	for (k = 0; k < size(flights)-1; k++)
	{

		fl = std::to_string(k + 1) + " " + flights[k]->date_in + " " + flights[k]->date_out + " " + flights[k]->name + " " + std::to_string(flights[k]->number) + " " + flights[k]->brand+ " " + std::to_string(flights[k]->km) + " " + std::to_string(flights[k]->flight_cost) + " " +(flights[k]->place_out) + " "+(flights[k]->place_in)+" "+std::to_string(flights[k]->stops)+" "+std::to_string(flights[k]->tickets)+" "+std::to_string(flights[k]->size)+"\n" ;
		fout << fl;
	}
	fl = std::to_string(k + 1) + " " + flights[k]->date_in + " " + flights[k]->date_out + " " + flights[k]->name + " " + std::to_string(flights[k]->number) + " " + flights[k]->brand + " " + std::to_string(flights[k]->km) + " " + std::to_string(flights[k]->flight_cost) + " " + (flights[k]->place_out) + " " + (flights[k]->place_in) + " " + std::to_string(flights[k]->stops) + " " + std::to_string(flights[k]->tickets) + " " + std::to_string(flights[k]->size);
	fout << fl;
	fout.close();
	fout.open("Flight.txt", std::ios_base::in);
	flights.clear();
	while (!fout.eof()) {
		string pi;
		getline(fout, pi);
		std::istringstream temp(pi);
		std::shared_ptr<Flight> ptr_flight(new Flight);
		ptr_flight->Read(temp);
		flights.push_back(ptr_flight);
	}
}

void Find_Pilot(vector<std::shared_ptr<Flight>>& flights,vector<std::shared_ptr<Pilot>>& pilots) {
	for (size_t i = 0; i < size(flights); i++)
	{
		flights[i]->Print();
	}
	cout << "\nChoose a flight's number of flight you're interested in: ";
	int n;
	cin >> n;
	string pilot;
	if (n >= 1 && n <= size(flights))
		pilot=flights[n - 1]->name;
	else {
		cout << "Incorrect flight's number!";
		return;
	}
	CheckInfo(pilot, pilots);
}
void Find_Plane(vector<std::shared_ptr<Flight>>& flights, vector<std::shared_ptr<AirPlane>>& planes) {
	for (size_t i = 0; i < size(flights); i++)
	{
		flights[i]->Print();
	}
	cout << "\nChoose a flight's number of flight you're interested in: ";
	int n;
	cin >> n;
	int plane;
	if (n >= 1 && n <= size(flights))
		plane = flights[n - 1]->number;
	else {
		cout << "Incorrect flight's number!";
		return;
	}
	CheckInfo(plane, planes);
}
void ChangeInfo(vector<std::shared_ptr<Flight>>& flights, vector<std::shared_ptr<Pilot>>&pilots, vector<std::shared_ptr<AirPlane>>&planes) {
	for (size_t i = 0; i < size(flights); i++)
	{
		flights[i]->Print();
	}
	cout << "Choose a flight's number you'd like to change: ";
	int number;
	cin >> number;
	size_t i = 0;
	for (; i < size(flights); i++)
	{
		if (number == flights[i]->flight_number) {
			flights[i]->Print();
			break;
		}
	}
	if (i == size(flights)) {
		cout << "Incorrect number!";
		return;
	}
	string fl;
	cout << "Write new info(write until you reach parametr you need): \n|date of in: |date of out: |pilot's name: |plane's number: |brand: |mileage: |flight cost: |place of out: |place of in: |number of stops: |saled tickets: |size: \n";
	while (fl == "") {
		getline(cin, fl);
	}
	std::istringstream in(fl);
	flights[i]->Read(in, i);
	while (!flights[i]->Check_Name(pilots) ||!flights[i]->Check() ||  !flights[i]->Check_Plane(planes)) {
		cout << "Something went wrong! Please, try again!\n";
		getline(cin, fl);
		std::istringstream temp(fl);
		flights[i]->Read(temp, i);
	}
	std::fstream fout("Flight.txt", std::ios_base::out);
	size_t k;
	for (k = 0; k < size(flights) - 1; k++)
	{
		fl = std::to_string(k + 1) + " " + flights[k]->date_in + " " + flights[k]->date_out + " " + flights[k]->name + " " + std::to_string(flights[k]->number) + " " + flights[k]->brand + " " + std::to_string(flights[k]->km) + " " + std::to_string(flights[k]->flight_cost) + " " + (flights[k]->place_out) + " " + (flights[k]->place_in) + " " + std::to_string(flights[k]->stops) + " " + std::to_string(flights[k]->tickets) + " " + std::to_string(flights[k]->size) + "\n";
		fout << fl;
	}
	fl = std::to_string(k + 1) + " " + flights[k]->date_in + " " + flights[k]->date_out + " " + flights[k]->name + " " + std::to_string(flights[k]->number) + " " + flights[k]->brand + " " + std::to_string(flights[k]->km) + " " + std::to_string(flights[k]->flight_cost) + " " + (flights[k]->place_out) + " " + (flights[k]->place_in) + " " + std::to_string(flights[k]->stops) + " " + std::to_string(flights[k]->tickets) + " " + std::to_string(flights[k]->size);
	fout << fl;
	fout.close();
}
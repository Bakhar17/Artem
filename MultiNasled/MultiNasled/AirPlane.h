#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>
using std::vector;
using std::string;
using std::cout;
using std:: cin;
class AirPlane
{
public:
	AirPlane()=default;
	~AirPlane();
	void Read(std::istream&);
	std::ostream& Print();
	bool Check();
	bool Check_Plane(vector<std::shared_ptr<AirPlane>>& planes);
	friend void Delete_Plane(vector<std::shared_ptr<AirPlane>>& planes);
	friend void CheckInfo(int , vector<std::shared_ptr<AirPlane>>& );
	friend void ChangeInfo(vector<std::shared_ptr<AirPlane>>& planes);
protected:
	int number=0;
	string brand="";
	int release_date=0;
	double capacity=0;
	int passengers=0;
};
AirPlane::~AirPlane()
{
}

std::ostream& AirPlane::Print()
{
	cout << "|number: " << number << " | " << "|brand " << brand << " | " << "release date: " << release_date << " | " << "capacity: " << capacity<<" |passengers: "<<passengers<<"\n";
	return cout;
}
void AirPlane::Read(std::istream& in) {
	in >> number >> brand >> release_date >> capacity >> passengers;
}
bool AirPlane::Check_Plane(vector<std::shared_ptr<AirPlane>>& planes) {
	for (size_t i = 0; i < size(planes); i++)
	{
		if (this->number == planes[i]->number && this->brand == planes[i]->brand) 
			return 1;
	}
	return 0;
}

bool AirPlane::Check() {
	if (number != 0 && brand != "" && release_date != 0&&capacity!=0&&passengers!=0) {
		return 1;
	}
	return 0;
}

void Add_Plane(vector<std::shared_ptr<AirPlane>>& planes) {
	string pi;
	cout << "\nWrite a new plane using next example(in one line):\n|number: |brand: |release_date: |capacity: |passengers: \n";
	getline(cin, pi);
	std::istringstream temp(pi);
	std::shared_ptr<AirPlane> ptr_plane(new AirPlane);
	ptr_plane->Read(temp);
	while (!ptr_plane->Check()) {
		cout << "Something went wrong! Please, try again!\n";
		getline(cin, pi);
		std::istringstream temp(pi);
		std::shared_ptr<Pilot> ptr_pilot(new Pilot);
		ptr_pilot->Read(temp);
	}
	planes.push_back(ptr_plane);
	std::ofstream fout("Plane.txt", std::ios_base::app);
	fout << "\n" << pi;
	fout.close();
}

void Delete_Plane(vector<std::shared_ptr<AirPlane>>& planes) {
	int number;
	vector<std::shared_ptr<AirPlane>>::iterator i;
	for (i = planes.begin(); i != planes.end(); i++)
	{
		(*i)->Print();
	}
	cout << "Choose a plane's number you'd like to delete: ";
	cin >> number;
	int sizer = (size(planes));
	for (i = planes.begin(); i != planes.end(); i++)
	{
		if ((*i)->number == number) {
			planes.erase(i);
			break;
		}
	}
	if (sizer == planes.size()) {
		cout << "Plane hasn't been found!\n";
		return;
	}


	std::fstream fout("Plane.txt", std::ios_base::out);
	size_t k;
	if (!planes.empty()) {
		string pi = "";
		for (k = 0; k < size(planes) - 1; k++)
		{
			pi = std::to_string(planes[k]->number) + " " + (planes[k]->brand) + " " + std::to_string(planes[k]->release_date) + " " + std::to_string(planes[k]->capacity) + " " + std::to_string(planes[k]->passengers) + "\n";
			fout << pi;
		}
		pi = pi = std::to_string(planes[k]->number) + " " + (planes[k]->brand) + " " + std::to_string(planes[k]->release_date) + " " + std::to_string(planes[k]->capacity) + " " + std::to_string(planes[k]->passengers);
		fout << pi;
		fout.close();
	}
	else {
		fout.close();
	}
}

void CheckInfo(int number, vector<std::shared_ptr<AirPlane>>& flights) {
	for (size_t i = 0; i < size(flights); i++)
	{
		if (number == flights[i]->number) {
			flights[i]->Print();
			return;
		}
	}
}
void ChangeInfo(vector<std::shared_ptr<AirPlane>>& planes) {
	for (size_t i = 0; i < size(planes); i++)
	{
		planes[i]->Print();
	}
	cout << "Choose a plane's number you'd like to change: ";
	int number;
	cin >> number;
	size_t i = 0;
	for (; i < size(planes); i++)
	{
		if (number == planes[i]->number) {
			planes[i]->Print();
			break;
		}
	}
	if (i == size(planes)) {
		cout << "Incorrect number!";
		return;
	}
	cout << "Write new info: \n|number: |brand: |release_date: |capacity: |passengers: \n";
	string info;
	while (info == "")
		getline(cin, info);
	std::istringstream in(info);
	planes[i]->Read(in);
	while (!planes[i]->Check()) {
		cout << "Something wrong! Please, try again!\n";
		getline(cin, info);
		std::istringstream in(info);
		planes[i]->Read(in);
	}
	std::fstream fout("Plane.txt", std::ios_base::out);
	string pi = "";
	size_t k;
	for (k = 0; k < planes.size() - 1; k++)
	{

		pi= std::to_string(planes[k]->number) + " " + (planes[k]->brand) + " " + std::to_string(planes[k]->release_date) + " " + std::to_string(planes[k]->capacity) + " " + std::to_string(planes[k]->passengers) + "\n";
		fout << pi;
	}
	pi = std::to_string(planes[k]->number) + " " + (planes[k]->brand) + " " + std::to_string(planes[k]->release_date) + " " + std::to_string(planes[k]->capacity) + " " + std::to_string(planes[k]->passengers);
	fout << pi;
	fout.close();
}
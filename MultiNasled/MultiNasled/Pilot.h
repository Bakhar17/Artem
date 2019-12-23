#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <sstream>
using std::vector;
using std::cout;
using std::cin;
using std::string;

class Pilot
{
public:
	Pilot() {};
	~Pilot() {};
	std::ostream& Print();
	void Read(std::istream& );
	bool Check();
	bool Check_Name( vector<std::shared_ptr<Pilot>>& pilots);
	friend void Delete_Pilot(vector<std::shared_ptr<Pilot>>& pilots);
	friend void CheckInfo(string name,vector<std::shared_ptr<Pilot>>& pilots);
	friend void ChangeInfo(vector<std::shared_ptr<Pilot>>&);
protected:
	string name="";
	double experience=0;
	string adress="";
	string dateofbirth="";
	double salary=0;
};

std::ostream& Pilot::Print() {
	cout << "|name: " << name << " |experience: " << experience << " |adress: "<<adress << " |dateofbirth: " << dateofbirth << " |salary: " << salary << "\n";
	return cout;
}
void Pilot::Read(std::istream& in) {
	in >> name >> experience >> adress >> dateofbirth >> salary;
}

bool Pilot::Check() {
	if (name != "" && !experience  && adress != "" && dateofbirth != "" && !salary ) {
		return 1;
	}
	return 0;
}

bool Pilot::Check_Name(vector<std::shared_ptr<Pilot>>& pilots) {
	for (size_t i = 0; i < size(pilots); i++)
	{
		if (name == pilots[i]->name) return 1;
	}
	return 0;
}

void Add_Pilot(vector<std::shared_ptr<Pilot>>& pilots) {
	string pi;
	cout << "\nWrite a new pilot using next example(in one line):\n | name: | experience : | adress : | dateofbirth : | salary : \n";
	getline(cin, pi);
	std::istringstream temp(pi);
	std::shared_ptr<Pilot> ptr_pilot(new Pilot);
	ptr_pilot->Read(temp);
	while (!ptr_pilot->Check()) {
		cout << "Something went wrong!Please, try again!\n";
		getline(cin, pi);
		std::istringstream temp(pi);
		std::shared_ptr<Pilot> ptr_pilot(new Pilot);
		ptr_pilot->Read(temp);
	}
	pilots.push_back(ptr_pilot);
	std::ofstream fout("Pilot.txt", std::ios_base::app);
	fout << "\n" << pi;
	fout.close();
}

void Delete_Pilot(vector<std::shared_ptr<Pilot>>& pilots) {
	string name;
	vector<std::shared_ptr<Pilot>>::iterator i;
	for ( i = pilots.begin(); i != pilots.end(); i++)
	{
		(*i)->Print();
	}
	cout << "Choose a pilot you'd like to delete: ";
	cin >> name;
	int sizer = (size(pilots));
	for (i = pilots.begin(); i !=pilots.end(); i++)
	{
		if ((*i)->name == name) {
			pilots.erase(i);
			break;
		}
	}
	if (sizer==pilots.size()) {
		cout << "Pilot hasn't been found!\n";
		return;
	}


	std::fstream fout("Pilot.txt",std::ios_base::out);
	size_t k;
	if (!pilots.empty()) {
		string pi = "";
		for (k = 0; k < pilots.size()-1; k++)
	{

		pi = pilots[k]->name + " " + std::to_string(pilots[k]->experience) + " " + pilots[k]->adress + " " + pilots[k]->dateofbirth + " " + std::to_string(pilots[k]->salary)+"\n";
		fout << pi;
	}
	pi = pilots[k]->name + " " + std::to_string(pilots[k]->experience) + " " + pilots[k]->adress + " " + pilots[k]->dateofbirth + " " + std::to_string(pilots[k]->salary);
	fout << pi;
	fout.close();
	}
	else {
		fout.close();
	}
}
void CheckInfo(string name, vector<std::shared_ptr<Pilot>>& pilots) {
	for (size_t i = 0; i < size(pilots); i++)
	{
		if (name == pilots[i]->name) {
			pilots[i]->Print();
			return;
		}
	}
}

void ChangeInfo(vector<std::shared_ptr<Pilot>>&pilots) {
		for (size_t i = 0; i < size(pilots); i++)
	{
		pilots[i]->Print();
	}
		cout << "Choose a pilot's name you'd like to change: ";
		string name;
		cin >> name;
		size_t i = 0;
		for (; i < size(pilots); i++)
		{
			if (name == pilots[i]->name) {
				pilots[i]->Print();
				break;
			}
		}
		if (i == size(pilots)) {
			cout << "Incorrect name!";
			return;
		}
		cout << "Write new info: \n| name: | experience : | adress : | dateofbirth : | salary : \n";
		string info;
		while(info=="")
		getline(cin, info);
		std::istringstream in(info);
		pilots[i]->Read(in);
		while (!pilots[i]->Check()) {
			cout << "Something wrong! Please, try again!\n";
			getline(cin, info);
			std::istringstream in(info);
			pilots[i]->Read(in);
		}
		std::fstream fout("Pilot.txt", std::ios_base::out);
			string pi = "";
			size_t k;
			for (k = 0; k < pilots.size() - 1; k++)
			{

				pi = pilots[k]->name + " " + std::to_string(pilots[k]->experience) + " " + pilots[k]->adress + " " + pilots[k]->dateofbirth + " " + std::to_string(pilots[k]->salary) + "\n";
				fout << pi;
			}
			pi = pilots[k]->name + " " + std::to_string(pilots[k]->experience) + " " + pilots[k]->adress + " " + pilots[k]->dateofbirth + " " + std::to_string(pilots[k]->salary);
			fout << pi;
			fout.close();
}
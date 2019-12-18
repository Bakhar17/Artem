#include "Flowers_class.h"
#include "Flowers_nasl.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <memory>
using std::vector;
void Happy(vector<std::shared_ptr<Flower>>&);
void Sad(vector<std::shared_ptr<Flower>>&);
void Trans(vector<std::shared_ptr<Flower>>& bouquet, vector<std::shared_ptr<Flower>>& result);
size_t Find(vector<std::shared_ptr<Flower>>& bouquet, string name) {
	for (size_t i = 0; i < size(bouquet); i++)
	{
		if (bouquet[i]->GetName() == name) {
			return i;
		}
	}
	return 0;
}

std::shared_ptr<Flower> get_ptr(char marker)

{
	if (marker == 'R')
		return std::make_shared<Rose>();
	if (marker == 'P')
		return std::make_shared<Peonis>();
	if (marker == 'T')
		return std::make_shared<Tulip>();
}
int main()
{
	char marker;
	vector<std::shared_ptr<Flower>> flower_ptr;
	std::ifstream fin("Roses.txt");
	if (!fin.is_open()) {
		std::cout << "Wrong file!";
		system("pause");
		exit(1);
	}
	if (!fin.is_open())
	{
		cout << "ERROR: file is not open.\n";
		system("pause");
		exit(1);
	}
	while (true)
	{
		char marker;
		fin >> marker;
		if (fin.eof())
			break;
		flower_ptr.push_back(get_ptr(marker));
		string str;
		getline(fin, str);
		std::istringstream stream(str);
		flower_ptr.back()->Read(stream);
	}
	sort(flower_ptr.begin(), flower_ptr.end(), [](std::shared_ptr<Flower> first, std::shared_ptr<Flower> second) {return first->GetPrice() > second->GetPrice(); });
	for (size_t i = 0; i < size(flower_ptr); i++)
	{
		flower_ptr[i]->Print();
	}
	char hol_type;
	cout << "What type of event(happy/sad)\n";
	cout << "Choose(h/s): ";
	cin >> hol_type;
	while (hol_type != 'h' && hol_type != 's') {
		cin >> hol_type;
	}
	switch (hol_type)
	{
	case('h'):
		Happy(flower_ptr);
		break;
	case('s'):
		Sad(flower_ptr);
		break;
	}
	system("pause");
	return 0;
	
}


void Happy(vector<std::shared_ptr<Flower>>& bouquet) {
	int number=0;
	double max_price;
	cout << "What max price: ";
	cin >> max_price;
	double total_price=0;
	vector<std::shared_ptr<Flower>> result;
	for_each(bouquet.begin(), bouquet.end(), [&total_price, &bouquet, &max_price, &number, &result](std::shared_ptr<Flower> first) {
		while (max_price >= 0 &&max_price>= first->GetPrice()) {
			result.push_back(first);
			max_price -= first->GetPrice();
			number++;
			total_price += first->GetPrice();
		}
		});
	if (number == 0) {
		cout << "Pay more money ;)";
		return;
	}
	while (number % 2 == 0) {
		double pr = result[size(result) - 1]->GetPrice();
		result.erase(--result.end());
		number--;
		max_price += pr;
		total_price -= pr;
		for_each(bouquet.begin(), bouquet.end(), [&total_price, &bouquet, &max_price, &number, &result, &pr](std::shared_ptr<Flower> first) {
			if (pr > first->GetPrice())
				while (max_price >= 0 && max_price >= first->GetPrice()) {
					result.push_back(first);
					max_price -= first->GetPrice();
					number++;
					total_price += first->GetPrice();
				}
			});
	}
	vector<std::shared_ptr<Flower >> edit;

	for (size_t i = 0; i < size(result); i++)
	{
		result[i]->Print();
	}
	Trans(result, edit);
	for (size_t i = 0; i < size(edit); i++)
	{
		edit[i]->Print();
	}
	//cout <<"|numberof: "<< number << "  |total_price: " << total_price;
}

void Sad(vector<std::shared_ptr<Flower>>& bouquet) {
	int number = 0;
	double max_price;
	cout << "What max price: ";
	cin >> max_price;
	double total_price = 0;
	vector<std::shared_ptr<Flower>> result;
	for_each(bouquet.begin(), bouquet.end(), [&total_price, &bouquet, &max_price, &number, &result](std::shared_ptr<Flower> first) {
		while (max_price >= 0 && max_price >= first->GetPrice()) {
			result.push_back(first);
			max_price -= first->GetPrice();
			number++;
			total_price += first->GetPrice();
		}
		});
	if (number == 0) {
		cout << "Pay more money ;)";
		return;
	}
	while (number % 2 == 1) {
		double pr = result[size(result) - 1]->GetPrice();
		result.erase(--result.end());
		number--;
		max_price += pr;
		total_price -= pr;
		for_each(bouquet.begin(), bouquet.end(), [&total_price, &bouquet, &max_price, &number, &result, &pr](std::shared_ptr<Flower> first) {
			if (pr > first->GetPrice())
				while (max_price >= 0 && max_price >= first->GetPrice()) {
					result.push_back(first);
					max_price -= first->GetPrice();
					number++;
					total_price += first->GetPrice();
				}
			});
	}
	for (size_t i = 0; i < size(result); i++)
	{
		result[i]->Print();
	}
	cout << "|numberof: " << number << "  |total_price: " << total_price;
}

void Trans(vector<std::shared_ptr<Flower>>& bouquet,vector<std::shared_ptr<Flower>>& result) {
	string what;
	cin >> what;
	string that;
	cin >> that;
std::transform(bouquet.begin(), bouquet.end(),std::back_inserter(result),
	[what, that,&bouquet](std::shared_ptr<Flower> sweet)
	{
		if (sweet->GetName() == what) {
			size_t i = Find(bouquet, that);
			return bouquet[i];
		}
		else return sweet;

	});
}
#include "Flowers_class.h"
#include "Flowers_nasl.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using std::vector;
void Happy(vector<Flower*>&);
void Sad(vector<Flower*>&);
Flower* get_ptr(char marker)

{
	if (marker == 'R')
		return new Rose;
	if (marker == 'P')
		return new Peonis;
	if (marker == 'T')
		return new Tulip;
}
int main()
{
	char marker;
	vector<Flower*> flower_ptr;
	std::ifstream fin("Roses.txt");
	if (!fin.is_open()) {
		std::cout << "Wrong file!";
		system("pause");
		exit(1);
	}
	while (!fin.eof()) {
		fin >> marker;
		flower_ptr.push_back(get_ptr(marker));
		string str;
		getline(fin, str);
		std::istringstream obj(str);
		flower_ptr.back()->Read(obj);
	}
	sort(flower_ptr.begin(), flower_ptr.end(), [](Flower* first, Flower* second) {return first->GetPrice() > second->GetPrice(); });
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
		break;
	}
	system("pause");
	return 0;
}


void Happy(vector<Flower*>& bouquet) {
	int number=0;
	double max_price;
	cout << "What max price: ";
	cin >> max_price;
	double total_price=0;
	vector<Flower*> result;
	for_each(bouquet.begin(), bouquet.end(), [&total_price, &bouquet, &max_price, &number, &result](Flower* first) {
		while (max_price > 0 &&max_price>= first->GetPrice()) {
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
	if (number % 2 == 0) {
		total_price -= result[number-1]->GetPrice();
		max_price += result[number - 1]->GetPrice();
		result.erase(--result.end());
		number--;
	}
	for (size_t i = 0; i < size(result); i++)
	{
		result[i]->Print();
	}
	cout <<"|numberof: "<< number << "  |total_price: " << total_price;
}
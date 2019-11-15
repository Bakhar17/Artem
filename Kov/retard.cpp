#include <fstream>
#include "Country.h"
#include <sstream>

int main() {
	std::ifstream fin("pop.txt");
	std::string temp;
	std::ofstream fout("Output.txt");
	Country a;
	std::map<int, long long int> pop;
	std::string name,code;
	long long int k;
	getline(fin, temp);
	while (!fin.eof())
	{

	getline(fin, temp);
	std::stringstream sex(temp);
	sex >> name;
	sex >> code;
	for (int i = 1960; i <= 2018; i++)
	{
		sex >> k;
		pop.emplace(i, k);
	}
	a = { name,code,pop };
	fout<<ToString(a)<<"\n";
	}

}
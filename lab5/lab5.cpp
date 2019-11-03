#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <map>
#include "func.h"

void task1()

{	std::ofstream fout("Output.txt");
	std::ifstream fin("Text.txt");
	std::string str;
	while(!fin.eof()){	
	std::getline(fin, str);
	if (str.find("char") != std::string::npos)
	{
		str.insert(str.find("char"), "unsigned ");
	}
	fout << str<<"\n";}

}
void task2()
{
	std::ofstream fout("Output.txt");
	std::ifstream fin("Text2.txt");
	std::string str;
	while (!fin.eof())
	{
		getline(fin, str);
		while (str.find("we") != std::string::npos)
		{
			str.insert(str.find("we"), "they");
			str.erase(str.find("we"),2);
		}
		fout << str << "\n";
	}
}
void task3()
{
	std::ofstream fout("Output.txt");
	std::fstream fin1;
	std::ifstream fin("Text3.txt");
	std::string str;
	std::vector<std::string> words;
	std::string word;
	words.push_back("int");
	words.push_back("string");
	words.push_back("main");
	words.push_back("#include");
	words.push_back("while");
	words.push_back("for");
	int n;
	int pos=0;

			for (auto& i : words)
			{	n = 0;
			fin1.open("Text3.txt",std::ios::in);
				while (!fin1.eof())
				{
					getline(fin1, str);
					std::stringstream temp;
					temp << str;
					while (!temp.eof()) {
						temp >> word;
					if (word == i)
					{
						n++;
					}

					}
			

				}
				fin1.close();
				fout << i << " " << n << "\n";

	}
}
void task4()
{
	setlocale(LC_ALL, "Russian"); 
	double chislo;
	std::cout << "Put money";
	std::cin >> chislo;
	int rubles = int(chislo);
	int set = (chislo*100);
	set %= 100;
	std::string asd ;
	
	int copy_asd(rubles);
	int s = size(std::to_string(rubles))/3;
	int k;
	for (size_t i = s; i > 1; i--)
	{
		k = pow(1000, i);
		asd += std::to_string(copy_asd / k);
		asd += " ";
		copy_asd = copy_asd % k;
	}
	 
	asd += std::to_string(copy_asd / 1000);
	asd += " ";
	asd += std::to_string(rubles % 1000);
	if (asd[0] == '0')
	{
		asd[0] = ' ';
	}

	if (rubles % 10 == 3 || rubles % 10 == 4)
	{
		std::cout << asd << " рубля " << set << " коп.";
	}
	if (rubles % 10 == 0 || rubles % 10 == 5 || rubles % 10 == 6 || rubles % 10 == 7 || rubles % 10 == 8 || rubles % 10 == 9)
	{
		std::cout << asd << " рублей " << set<< " коп.";
	}
	if (rubles % 10 == 1)
	{
		if (rubles % 100 == 1)
		{
			std::cout << asd << " рублей " << set << " коп.";
		}
		else
		{
			std::cout << asd << " рубль " << set << " коп.";
		}
	}
	if (rubles % 10 == 2)
	{
		if (rubles % 100 == 1)
		{
			std::cout <<asd << " рублей " << set << " коп.";
		}
		else
		{
			std::cout << asd << " рубля " << set << " коп.";
		}
	}


}
void task5() {
	std::ifstream fin("Text2.txt", std::ios::in);
	std::map<std::string, int> wordsdict;
	std::string str;
	std::fstream fout;
	std::fstream fout1;
	std::fstream f1;
	if (fin.is_open())
	{
		fout.open("Output.txt", std::ios::out);
		while (!fin.eof()) {
			getline(fin, str);
			funcmess(str);
			fout << str << "\n";
		}
		fout.close();

	}
	check(fout, fout1, wordsdict);
}
void task6() {
	setlocale(LC_ALL, "rus");
	std::multimap<int, std::string> polig;
	polig.emplace( 1, "один");
	polig.emplace(1, "адзiн");
	polig.emplace(1, "one");
	polig.emplace(2, "два");
	polig.emplace(2, "two");
	polig.emplace(3, "три");
	polig.emplace(3, "тры");
	polig.emplace(3, "three");
	polig.emplace(4, "четыре");
	polig.emplace(4, "чатыры");
	polig.emplace(4, "four");
	int k;

	//for (std::multimap<int,std::string>:: iterator i= polig.begin(); i !=polig.end(); i++)
	//{
	//	std::cout << i->first << " " << i->second << "\n";
	//}	
	std::cout << "Введите число ";
	std::cin >> k;
	std::multimap<int, std::string>::iterator i;
	if (polig.lower_bound(k) == polig.end()) {
		std::cout << "Такого элемента нет";
	}
	for ( i = polig.lower_bound(k); i != polig.upper_bound(k); i++)
	{
		std::cout << i->second << "\n";
	}
}

int main()
{
	std::cout << "Put n ";
	int n;
	std::cin >> n;
	switch (n)
	{
	case(1):
		task1();
		break;
	case(2):
		task2();
		break;
	case(3):
		task3();
		break;
	case(4):
		task4();
		break;
	case(5):
		task5();
		break;
	case(6):
		task6();
		break;

	}

}
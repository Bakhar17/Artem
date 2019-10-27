#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

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
	double lo;
	//std::string set=std::to_string(chislo);
	//int p=set.find(".");
	//set = set[p+1] + set[p + 2];
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
		std::cout << asd << " ����� " << set << " ���.";
	}
	if (rubles % 10 == 0 || rubles % 10 == 5 || rubles % 10 == 6 || rubles % 10 == 7 || rubles % 10 == 8 || rubles % 10 == 9)
	{
		std::cout << asd << " ������ " << set<< " ���.";
	}
	if (rubles % 10 == 1)
	{
		if (rubles % 100 == 1)
		{
			std::cout << asd << " ������ " << set << " ���.";
		}
		else
		{
			std::cout << asd << " ����� " << set << " ���.";
		}
	}
	if (rubles % 10 == 2)
	{
		if (rubles % 100 == 1)
		{
			std::cout <<asd << " ������ " << set << " ���.";
		}
		else
		{
			std::cout << asd << " ����� " << set << " ���.";
		}
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
	}

}
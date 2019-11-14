#include <iostream>
#include "func.h"
#include <string>
#include <fstream>
#include <sstream>
#include <map>
void funcmess(std::string& b);
void check(std::fstream& fout, std::fstream& fout1, std::map<std::string, int>& wordsdict);

int main()
{
	std::ifstream fin("Text.txt",std::ios::in);
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
			fout << str<<"\n";
		}
		fout.close();

	}
	check(fout, fout1,wordsdict);
}
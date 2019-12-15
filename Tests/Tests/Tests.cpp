#include <iostream>
#include "Header.h"
#include <fstream>

void Er(string, vector<string>&);

void SortR(vector<string>&);

int main()
{
	fstream fin("Text.txt",ios_base::in);
	string str;
	vector<string> stroki;
	while (!fin.eof()) {
		getline(fin, str);
		stroki.push_back(str);
	}
	SortR(stroki);
	Er("ASD", stroki);
	auto pos = stroki[0].find("asd");
	cout << pos;
	fstream fout("Out.txt", ios_base::out);
	for (size_t i = 0; i < size(stroki); i++)
	{
		fout << stroki[i] << "\n";
	}
}


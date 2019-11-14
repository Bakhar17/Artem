#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
void funcmess(std::string& b)
{
	int n;
	while (true)
	{
		n = b.find(',');
		if (n != std::string::npos)
		{
			b.erase(n, 1);
		}
		n = b.find('.');
		if (n != std::string::npos)
		{
			b.erase(n, 1);
		}
		if (b.find(',') == std::string::npos && b.find('.') == std::string::npos)
		{
			break;
		}
		}
}
void check(std::fstream &fout,std::fstream&fout1,std::map<std::string,int>&wordsdict) {
	fout.open("Output.txt", std::ios::in);
	std::string str;
	std::string str1;
	std::string word;
	int n;
	std::string word2;
	while (!fout.eof())
	{
		getline(fout, str);
		std::stringstream temp(str);

		while (!temp.eof())
		{
			n = 0;
			temp >> word;
			fout1.open("Output.txt", std::ios::in);
			while (!fout1.eof())
			{
				getline(fout1, str1);
				std::stringstream temp1(str1);
				while (!temp1.eof()) {
					temp1 >> word2;
					if (word == word2)
					{
						n++;
					}

				}

			}
			wordsdict.emplace(word, n);
			fout1.close();
		}

	}
	fout.close();
	fout.open("Output.txt", std::ios::out);
	for (std::map<std::string, int>::iterator i = wordsdict.begin(); i != wordsdict.end(); i++)
	{
		fout << i->first << " " << i->second << "\n";
	}
}
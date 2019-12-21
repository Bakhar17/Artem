#include <iostream>
#include "Header.h"
#include <fstream>
#include <iterator>
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
	string word;
	cin >> word;
	transform(stroki.begin(), stroki.end(), stroki.begin(), [&stroki, word](string temp) {Er(word, temp);
	return temp; });
	SortR(stroki);
	fstream fout("Out.txt", ios_base::out);
	copy(stroki.begin(), stroki.end(), ostream_iterator<string>(fout,"\n"));
}


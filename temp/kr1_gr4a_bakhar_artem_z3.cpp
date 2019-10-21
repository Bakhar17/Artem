#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

int main()
{
	ifstream fin("segments.txt");
	if (fin.is_open())
	{
		int x1, x2, y1, y2;
		string str;
		pair<pair<int, int>, pair<int, int>>;

		map<pair<int, int>, pair<int, int>> mapofpair;
		while (!fin.eof())
		{	
			getline(fin, str);
			istringstream line(str);
			line >> x1 >> y1 >> x2 >> y2;
			mapofpair.insert(make_pair<make_pair<x1, y1>, make_pair<x2, y2>>);

			cout << x1 << y1 << x2 << y2 << "\n";
		}
	}
}
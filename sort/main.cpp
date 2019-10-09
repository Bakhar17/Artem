#include <iostream>
#include <vector>
#include "sort.h"
#include "iodata.h"
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	//srand(time(NULL));
	vector<int> def{};
	const int s = 1000;
	push_vector(def, s);
	cout << "\n";
	unsigned int  start = clock();
	sort_pyzir(def,s);
	unsigned int end = clock();
	cout << (end*1. - start*1. )<<"\n";


	for (int index = 0; index < s; index++)
		cout << def[index] << ' ';
	cout << "\n";
	system("pause");
	return 0;
}
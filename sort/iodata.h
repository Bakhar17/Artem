#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

void push_vector(vector<int>& a,const int s)
{
	for (size_t i = 0; i < s; i++)
	{
		a.push_back(rand() % 100);
	}
	for (size_t i = 0; i < s; i++)
	{
		cout << a[i] << "\t";
	}
}
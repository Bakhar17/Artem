#include <iostream>
#include <vector>
#include "sort.h"
#include "iodata.h"
#include <chrono>

using namespace std::chrono;

int main()
{
	srand(time(NULL));
	vector<int> def{};
	const int s = 10000;
	push_vector(def, s);
	cout << "\n";
	auto start = chrono::system_clock::now();
	sort_vibor(def,s);
	auto end = chrono::system_clock::now();
	auto elapsed_seconds = duration_cast<seconds>(end - start).count();
	auto elasped_milliseconds = duration_cast<milliseconds>(end - start).count();

	time_t end_time = chrono::system_clock::to_time_t(end);
	cout  << "seconds " << elapsed_seconds << "\n" << "milliseconds " << elasped_milliseconds << "\n";

	//for (int index = 0; index < s; index++)
	//	cout << def[index] << ' ';
	cout << "\n";
	system("pause");
	return 0;
}
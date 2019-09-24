#include <iostream>
#include <string>
#include <vector>

using namespace std;
void levopravo(long long a)
{
	int a1 = a;
	unsigned int ves[10]{ 0,0,0,0,0,0,0,0,0,0 };
	while (a >= 1)
	{
		if (a % 10 == 9)
		{
			ves[9] += 1;
		}
		if (a % 10 == 1)
		{
			ves[1] += 1;
		}
		if (a % 10 == 2)
		{
			ves[2] += 1;
		}
		if (a % 10 == 3)
		{
			ves[3] += 1;
		}
		if (a % 10 == 4)
		{
			ves[4] += 1;
		}
		if (a % 10 == 5)
		{
			ves[5] += 1;
		}
		if (a % 10 == 6)
		{
			ves[6] += 1;
		}
		if (a % 10 == 7)
		{
			ves[7] += 1;
		}
		if (a % 10 == 8)
		{
			ves[8] += 1;
		}
		a /= 10;
	}
	/*for (size_t i = 0; i < 10; i++)
	{
		cout << ves[i] << " ";
	}*/

	int index = 0;
	int max = ves[0];
	for (size_t i = 0; i < 9; i++)
	{
		if (max < ves[i + 1])
		{
			max = ves[i + 1];
			index = i + 1;
		}
	}
	//cout << "\n" << index;
	string str = to_string(index) + to_string(a1) + to_string(index);
	cout << "\n" << str;

	
}

int main()
{
	cout << "Put N: ";
	long long N;
	cin >> N;
	(levopravo(N));
}
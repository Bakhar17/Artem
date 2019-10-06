#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
template<class T>
void task1(vector<T>&a )
{
	//сортировка 
	int kol = size(a);
		for (int i = 0; i < kol - 1; i++)
		{
			int pervi = i;
			for (int next = i + 1; next < kol; next++)
			{
				if (a[next] < a[pervi])
					pervi = next;
			}
			swap(a[i], a[pervi]);
		}

		for (int index = 0; index < kol; index++)
		cout << a[index] << ' ';
		cout << "\n";
		//конец сортировки

		int i;
		for ( i = 0; i < kol; i++)
		{
			int num = 1;
			while (a[i] == a[i + 1])
			{
				num += 1;
				i++;
			}
			if (num % 2 == 1)
				break;
		}
		cout << a[i];
}
template<class T>
void task2(vector<T>&a )
{
	//сортировка 
	int kol = size(a);
	for (int i = 0; i < kol - 1; i++)
	{
		int pervi = i;
		for (int next = i + 1; next < kol; next++)
		{
			if (a[next] < a[pervi])
				pervi = next;
		}
		swap(a[i], a[pervi]);
	}

	for (int index = 0; index < kol; index++)
		cout << a[index] << ' ';
	cout << "\n";
	//конец сортировки
	int multi1=1;
	for (size_t i = size(a)-3; i < size(a); i++)
	{
		multi1 *= a[i];
	}
	cout << "multiplicate: " << multi1;
}
template<class T>
void task4(vector<T>& a)
{
	int min = a[0];
	int i1;
	for (size_t i =1; i < size(a); i++)
	{
	if (min>a[i])
	{
		min = a[i];
		i1 = i;
	}
	}
	cout << "min= "<<min << endl;
	//сортировка по возрастанию
		int kol = size(a);
		for (int i = i1; i < kol - 1; i++)
		{
			int pervi = i;
			for (int next = i + 1; next < kol; next++)
			{
				if (a[next] < a[pervi])
					pervi = next;
			}
			swap(a[i], a[pervi]);
		}
		//конец сортировки


		//сортировка по убыванию
		for (size_t i = 0; i < i1; i++)
		{
			int pervi = i;
			for (int next = i+1; next <i1 ; next++)
			{
				if (a[next] > a[pervi])
				{
					pervi = next;
				}
				swap(a[i], a[next]);
			}
		}
		for (int index = 0; index < kol; index++)
			cout << a[index] << ' ';
		cout << "\n";
}
template<class T>
int task6(vector<T> & a)
{
	int kol = size(a);
	for (size_t i = 0; i < kol; i++)
	{
		int pervi = i;
		for (size_t next = i+1; next < kol; next++)
		{
			if (a[next] < a[pervi])
			{
				pervi = next;
			}
			swap(a[i], a[pervi]);
		}
	}
	return a[0];
}
template<class T>
bool task8(vector<T>& a, vector<T>& b)
{
	int i = 1;
	int k = 1;
	for (; i < size(b) ; i++)
	{
		for (; k < size(a) ; k++)
		{
			if (b[i] == a[k] && b[i - 1] == a[k - 1])
			{
				break;
			}
		}
	}
	cout << i << "\t" << k;
	if (k >= size(a))
	{
		return false;
	}
	if (i>=size(b))
	{i -= 1; }

	for (; i >=0;i--)
	{
		if (b[i] != a[k])
		{
			return false;
		}
		k--;
	}
}
int main()
{
	cout << "Task number: ";
	int n;
	cin >> n;
	vector<int> nomer1{ 15,20,98,20,16,16,98 };//задание 1
	vector<int> nomer2{ 1,5,48,64,78,1,2,56 };//задание 2
	vector<int> nomer4{ 15,54,84,6,48,75,12 };//задание 4
	vector<int> nomer6  { 5564,4654,48,213,98,4847};//задание 6
	
													
	//задание 8 


	vector<int> nomer8_1{ 5,7,56,468,21,45,12};
	vector<int> nomer8_2{56,468,21,5};
	switch (n)
	{
	case(1):

		task1(nomer1);
		break;
	case(2):
		task2(nomer2);
		break;
	case(4):
		task4(nomer4);
		break;
	case(3):
		break;
	case(5):
		break;
	case(6):
		cout << "min element: " << (task6(nomer6));
		break;
	case(7):
		break;
	case(8):
		if (task8(nomer8_1, nomer8_2))
		{
			cout << "True";
		}
		else
		{
			cout << "False";
		}
		break;
	}
}
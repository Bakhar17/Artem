#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

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

void task7(vector<int>& a, int n)
{

		int temp,i; 
		for (int counter = 1; counter < size(a); counter++)
		{
			temp = a[counter]; // инициализируем временную переменную текущим значением элемента массива
			i = counter - 1; // запоминаем индекс предыдущего элемента массива
			while (i >= 0 && a[i] > temp) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
			{
				a[i + 1] = a[i]; // перестановка элементов массива
				a[i] = temp;
				i--;
			}
		}
		for (size_t i = 0; i < size(a); i++)
		{
			cout << a[i] << "\t";
		}
		int left = 0;
		int mid;
		int right = size(a);
		while (right != left)
		{
			mid = (left + right) / 2;
			if (n < a[mid])
			{
				right = mid - 1;
			}
			else
			{
				if (n > a[mid])
					left = mid + 1;
				else
				{
					mid= mid + 1;
					break;
				}
			}
		}
		if (left != right)
		{
			cout <<"\n"<<"Requested position: "<< mid;
		}
		else
		{
			cout << "\n" <<"Requested position: "<< left;
		}
}


void task3_summa(vector<int>& a, vector<int>& b)
{
	if (size(a) > size(b))
	{
		for (size_t i = 0; i < size(b); i++)
		{
			cout << a[i] + b[i] << "+";
		}
		for (size_t i = size(b); i < size(a)-1; i++)
		{
			cout << a[i] << "+";
		}
		cout << a[size(a) - 1];
	}
	if (size(b)>size(a))
	{
		for (size_t i = 0; i < size(a); i++)
		{
			cout << a[i] + b[i] << "+";
		}
		for (size_t i = size(a); i < size(b)-1; i++)
		{
			cout << b[i] << "+";
		}
		cout << b[size(b) - 1];

	}
	if (size(a)==size(b))
		{
			for (size_t i = 0; i < size(a)-1; i++)
			{
				cout << a[i] + b[i] << "+";
			}
			cout << a[size(a)-1] + b[size(b)-1];
		}
}

void task5(vector<int>& a)
{
	int kol = size(a);
	sort(a.begin(), a.end());
		for (size_t i = 0; i < kol; i++)
		{
			cout << a[i] << "\t";
		}
		vector<int> temp;
		for (size_t i = 1; i < kol; i++)
		{
			temp.push_back(a[i] - a[0]);
		}
		for (size_t i = 0; i < size(temp); i++)
		{
			cout << temp[i] << "\t";
		}
		cout << "\n";
		int temps = size(temp);
		int nod;
		//решить вопрос с кол-вом!
		for (int i = temp[temps-1]; i > 0; i--)
		{
			if (temp[temps - 1] % i == 0 && temp[temps - 2] % i == 0 && temp[temps - 3 ] % i==0 )
			{
				nod = i;
				cout << "nod = " << nod;
				break;
			}
		}
		cout << "\n";
		vector<int> result;
		int i = 1;
		while (i != a[kol - 1])
		{
			result.push_back(i);
			i += nod;
		}
		result.push_back(i);
		for (size_t i = 0; i < size(result); i++)
		{
			cout << result[i] << " ";
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
	//задание 7:
	vector<int> nomer7{ 15,48,6,5,78,21,35 };

	vector<int> nomer3_1{ 1,5,7,6,4,8};
	vector<int> nomer3_2{ 0,5,9,5,9 };

	vector<int> nomer5{ 1,22,36,29 };
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
		task3_summa(nomer3_1, nomer3_2);
		break;
	case(5):
		task5(nomer5);
		break;
	case(6):
		cout << "min element: " << (task6(nomer6));
		break;
	case(7):
		int k;
		cout << "Put k: ";
		cin>>k;
		task7(nomer7,k);
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
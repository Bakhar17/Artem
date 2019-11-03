#include <iostream>
#include <vector>
using namespace std;

int* task1_min(vector<int> a, int i)
{
	int *pervi=&i;

	for (size_t k = *pervi + 1; k < size(a); k++)
	{
		if (a[*pervi] > a[k])
		{
			*pervi = k;
		}
	}
	return pervi;
}
void task1_sort(vector<int>& a)
{
	for (size_t i = 0; i < size(a); i++)
	{
		swap(a[i], a[*(task1_min(a,i))]);
	}
	for (size_t i = 0; i < size(a); i++)
	{
		cout << a[i] << "\t";
	}

}
int* task2_bin(vector<int>& v, int key, int index)
{
	int result;
	int* ptr=&result;
	int left = 0;
	int right = index;
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (key > v[mid])
		{
			left = mid + 1;
		}
		if (key < v[mid])
		{
			right = mid;
		}
		if (key == v[mid])
		{
			result = mid;
			return ptr;
		}
	}

	if (key > v[right])
	{
		result = right + 1;
		return ptr;
	}
	else
	{
		result = right;
		return ptr;
	}
}
void task2_binsort(vector<int>& a)
{
	
	if (a[0] > a[1])
	{
		swap(a[0], a[1]);
	}
	for (int j = 2; j < size(a); j++)
	{
		int tmp = a[j];
		int k = *(task2_bin(a, a[j], j - 1));
		for (int i = j; i > k; i--)
		{
			a[i] = a[i - 1];
		}
		a[k] = tmp;
	}
	for (size_t i = 0; i < size(a); i++)
	{
		cout << a[i] << "\t";
	}
}

int* subset(int*A, int*B) {

	return nullptr;
}
int main()
{
	vector<int> test{ 5,48,6,8,3,154,48 };
	task1_sort(test);
	cout << "\n";
	vector<int> test2{ 15,4,65,26,6,8,9,1215,45 };
	task2_binsort(test2);
	int size;
	cin >> size;
	int* A = new int[size];

}
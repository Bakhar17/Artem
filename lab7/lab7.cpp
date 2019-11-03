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

int* subset(int*A, int*B,int a,int b) {

		int i = 1;
		int k = 1;
		for (; i < b; i++)
		{
			for (; k < a; k++)
			{
				if (B[i] == A[k] && B[i - 1] == A[k - 1])
				{
					break;
				}
			}
		}
		//cout << i << "\t" << k<<"\n";
		int result = k;
		if (k >= a)
		{
			return nullptr;
		}
		if (i >= b)
		{
			i -= 1;
		}

		for (; i >= 0; i--)
		{
			if (B[i] != A[k])
			{
				return nullptr;
			}
			k--;
		}
		return (A+result-b+1);
}
bool check(int a) {
	int result = 1;
	for (int i = 2; i <=a/2 ; i++)
	{
		if (a % i == 0) {
			result += 1;
		}
	}
	if (result > 1)
	{
		return false;
	}
	return true;
}
int main()
{
	//vector<int> test{ 5,48,6,8,3,154,48 };
	//task1_sort(test);
	//cout << "\n";
	//vector<int> test2{ 15,4,65,26,6,8,9,1215,45 };
	//task2_binsort(test2);



	int size,size2;
	size = 5;
	size2 = 3;
	int* A = new int[size] {1, 53, 86, 32, 5};
	int* B = new int[size2] {53, 86,32};
	int* i=subset(A, B, size, size2);
	cout << *i;
	//for (int i = 0; i < size; i++)
	//{
	//	cout << A[i] << "\t";
	//}
	delete [] A;
	delete [] B;


	//A = new int[size];
	//A[0] = 15;
	//A[1] = 20;
	//A[2] = 7;
	//A[3] = 13;
	//A[4] = 19;
	//int n=0;
	//for (int i=0; i < size; i++)
	//{
	//	if (check(A[i]))
	//	{
	//		n++;
	//	}
	//}

	//B = new int[n]; 
	//int i = 0;
	//for (int k = 0; k < n; k++)
	//{
	//	for (; i < size; i++) {
	//		if (check(A[i])) {
	//			B[k] = A[i];
	//			i++;
	//			break;
	//		}
	//	}
	//}
	//for (int i = 0; i < n; i++)
	//{
	//	cout << B[i] << "\t";
	//}
	//delete[]A;
	//delete[]B;
}
#include <vector>
using namespace std;

void sort_vibor(vector<int>& a)
{
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
}

void sort_shell(vector<int>&mass, int n)
{
	int i, j, step;
	int tmp;
	for (step = n / 2; step > 0; step /= 2)
		for (i = step; i < n; i++)
		{
			tmp = mass[i];
			for (j = i; j >= step; j -= step)
			{
				if (tmp < mass[j - step])
					mass[j] = mass[j - step];
				else
					break;
			}
			mass[j] = tmp;
		}
}

void sort_pyzir(vector<int>& a,const int d)
{
	int temp; 
	for (int i = 0; i < d - 1; i++) {
		for (int j = 0; j < d - i - 1; j++) {
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void sort_oddEven(vector<int>& array, const int s)
{
	for (int i = 0; i < s; i++) {
		// (i % 2) ? 0 : 1 возвращает 1, если i четное, 0, если i не четное
		for (int j = (i % 2) ? 0 : 1; j < s - 1; j += 2) {
			if (array[j] > array[j + 1]) {
				std::swap(array[j], array[j + 1]);
			}
		}
	}
}

void sort_sheiker(vector<int>& a, const int size)
{
	int leftMark = 1;
	int rightMark = size - 1;
	while (leftMark <= rightMark)
	{
		for (int i = rightMark; i >= leftMark; i--)
			if (a[i - 1] > a[i]) swap(a[i], a[i-1]);
		leftMark++;


		for (int i = leftMark; i <= rightMark; i++)
			if (a[i - 1] > a[i]) swap(a[i], a[i - 1]);
		rightMark--;
	}
}

void sort_rascheska(vector<int>& a, const int s)
{
	for (int i = 0; i < s - 1; i++)
	{
		bool swapped = false;
		for (int j = 0; j < s - i - 1; j++)
		{
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				swapped = true;
			}
		}

		if (!swapped)
			break;
	}
}

void sort_vstavka(vector<int>& a, const int s)
{

	int temp, i;
	for (int counter = 1; counter < s; counter++)
	{
		temp = a[counter];
		i = counter - 1;
		while (i >= 0 && a[i] > temp)
		{
			a[i + 1] = a[i];
			a[i] = temp;
			i--;
		}
	}
}

void sort_vibor2(vector<int>& a,const int s)
{
	for (int i = 0; i <s; i++)
	{
		int pervi = i;
		int posled = s - 1-i;
		for (int next = i + 1; next <s; next++)
		{
			if (a[next] < a[pervi])
				pervi = next;

		}
		swap(a[i], a[pervi]);
		for (size_t next = s-1-i; next < s; next--)
		{
		if (a[next] > a[posled])
				{
					posled = next;
				}
		}

		swap(a[posled], a[s - 1 - i]);
	}
}
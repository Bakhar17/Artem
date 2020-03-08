#include <iostream>
extern "C" void _stdcall Swipe(int (*arr)[5][5], int size_,int k);
extern "C" int _stdcall CheckPos(int* arr, int size_, int* sarr, int ssize_);
extern "C" void _stdcall Erase(int* arr, int* size_, int ssize_, int pos);
int main()
{
    int arr[5][5];
	int sr = 1;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arr[i][j] = sr;
			sr++;
		}
	}
	Swipe(&arr, 25, 3);
	for (int i = 0; i < 5; i++)
	{
		std::cout << "\n";
		for (int j = 0; j < 5; j++)
		{
			std::cout << arr[i][j] << "\t";
		}
	}
	int size_=15;
	int ssize_ = 9;
	int* dyn_arr = new int[15];
	for (int i = 0; i < 15; i++)
	{
		dyn_arr[i] = i + 1;
	}
	int* sdyn_arr = new int[9];
	for (int i = 0; i < 9; i++)
	{
		sdyn_arr[i] = i + 3;
	}
	int pos = CheckPos(dyn_arr, 15, sdyn_arr, 9);

	std::cout << "\n" << pos << "\n";
	Erase(dyn_arr, &size_, ssize_, pos);
	for (int i = 0; i < size_; i++)
	{
		std::cout << dyn_arr[i] << "\t";
	}
	delete[] dyn_arr;
	delete[] sdyn_arr;
}

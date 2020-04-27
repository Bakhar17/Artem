#include <iostream>

extern "C" void __cdecl CreateVectorB(int (*A)[3][4],int N, int M, int* B);

int main()
{
    int A[3][4];
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			A[i][j] = rand() % 4 + 3;// push random numbers from 3 to 6
		}
	}
	//check matrix
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			std::cout << A[i][j] << " ";
		}
		std::cout << "\n";
	}
	int* vector=new int(0);
	CreateVectorB(&A, 3, 4, vector);

	//for (size_t i = 0; i < 3; i++)
	//{
	//	for (size_t j = 0; j < 4; j++)
	//	{
	//		std::cout << A[i][j] << " ";
	//	}
	//	std::cout << "\n";
	//}
	if (*vector == -1) {
		std::cout << "No matches!";
	}
	else {
		std::cout << "\n" << *vector;//номера строк в обратной записи
	}

	std::cout << "\n" << *vector;
	system("pause");
	return 0;
}

#include <iostream>
#include <cmath>


int main() {
	std::cout << "Matrix A:\n\n";
	double matrixA[10][10];
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			matrixA[i][k] = double(((rand() % 2000-1000)))/100;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			std::cout << matrixA[i][k] << " ";
		}
		std::cout << "\n";
	}

	std::cout << "\n\nvector x:\n\n";
	double matrixX[10];
	for (int i = 0; i < 10; i++)
	{
		matrixX[i] = double((rand() % 2000 - 1000)) / 100;
	}
	for (int i = 0; i < 10; i++)
	{
		std::cout << matrixX[i] << "\n";
	}

	std::cout << "\nMatrix Ax(f):\n";
	double matrixF[10];
	for (int i = 0; i < 10; i++)
	{
		double temp = 0;
		for (int k = 0; k < 10; k++)
		{
			temp += matrixA[i][k] * matrixX[k];
		}
		matrixF[i] = temp;
	}
	for (int i = 0; i < 10; i++)
	{
		std::cout << matrixF[i] << "\n";
	}

	//Gaussian method with selection of the main element by column

	double matrixA2[10][10];
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			matrixA2[i][k] = matrixA[i][k];
		}
	}

	double matrixF2[10];
	for (int i = 0; i < 10; i++)
	{
		matrixF2[i] = matrixF[i];
	}
	int swaps=0;
	for (int k = 0; k < 10; k++)
	{
		int j = k;

		for (int i = k+1; i < 10; i++)
		{
			double max = matrixA2[k][k];
			if (abs(max) < abs(matrixA2[i][k])) {
				max = matrixA2[i][k];
				j = i;
			}
		}
		//swap strings
		if (j != k)
		{
			swaps++;
			double temp = matrixF2[k];
			matrixF2[k] = matrixF2[j];
			matrixF2[j] = temp;
			for (int i = k; i < 10; i++)
			{
				temp = matrixA2[k][i];
				matrixA2[k][i] = matrixA2[j][i];
				matrixA2[j][i] = temp;
			}
		}
		for (int i = k+1; i < 10; i++)
		{
			double l = matrixA2[i][k] / matrixA2[k][k];
			matrixF2[i] = matrixF2[i] - l * matrixF2[k];
			for (int j = k+1; j < 10; j++)
			{
				matrixA2[i][j] = matrixA2[i][j] - (l * matrixA2[k][j]);
			}
		}

	}

	//reverse motion

	double matrixX2[10];
	matrixX2[9] = matrixF2[9] / matrixA2[9][9];

	for (int i = 8; i>=0 ; i--)
	{
		double gauss=0;
		int k = 10 - i;
		for (int j = 0; j < k-1; j++)
		{
			gauss += matrixA2[i][9-j] * matrixX2[9-j];
		}
		matrixX2[i] = (matrixF2[i] - gauss) / matrixA2[i][i];
	}
	//std::cout << "\n\n";
	//std::cout.setf(std::ios::fixed);
	//std::cout.precision(20); //0 - число символов после точки
	//for (int i = 0; i < 10; i++)
	//{
	//	std::cout << matrixX2[i]<<" ";
	//}
	

	//A*x`:

	double matrixF3[10];
	for (int i = 0; i < 10; i++)
	{
		double temp = 0;
		for (int k = 0; k < 10; k++)
		{
			temp += matrixA[i][k] * matrixX2[k];
		}
		matrixF3[i] = temp;
	}

	//Ax`-f:

	for (int i = 0; i < 10; i++)
	{
		matrixF3[i] = matrixF3[i] - matrixF[i];
	}

	double matrixnorm = abs(matrixF3[0]);
	for (int i = 1; i < 10; i++)
	{
		if (matrixnorm < abs(matrixF3[i])) matrixnorm = matrixF3[i];
	}

	double matrixX3[10];//x-x`
	for (int i = 0; i < 10; i++)
	{
		matrixX3[i] = matrixX[i] - matrixX2[i];
	}
	double xnorm=abs(matrixX3[0]);
	for (int i = 1; i < 10; i++)
	{
		if (xnorm < abs(matrixX3[i])) xnorm = matrixX3[i];
	}

	double detA=1;
	for (int i = 0; i < 10; i++)
	{
		detA *= matrixA2[i][i];
	}
	detA *= pow(-1, swaps);

	std::cout << "\n\n" << detA<<"\n\n";

	
	//A^-1:
	double matrixAs[10][10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		matrixAs[i][i] = 1;
	}

	double matrixAc[10][10];
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			matrixAc[i][k] = matrixA[i][k];
		}
	}

	for (int j = 0; j < 9; j++)
	{
	for (int i = j; i < 9; i++)
	{
		double l = matrixA[i + 1][j] / matrixA[j][j];
		for (int k = j; k < 10; k++)
		{
			matrixA[i + 1][k] -= l * matrixA[j][k];
		}
		for (int k = 0; k < 10; k++)
		{
			matrixAs[i + 1][k] -= l * matrixAs[j][k];
		}
	}
	}
	//reverse motion

	for (int j = 9; j > 0; j--)
	{
		double l;
		for (int i = j; i >0; i--)
		{
			l = matrixA[i - 1][j] / matrixA[j][j];
			matrixA[i - 1][j] -= l * matrixA[j][j];
			for (int k = 0; k <10; k++)
			{
				matrixAs[i-1][k] -= l * matrixAs[j][k];
			}
		}

	}
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			matrixAs[i][k] /= matrixA[i][i];
		}
	}
	std::cout << "\ninverse matrix:\n\n";
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			std::cout << matrixAs[i][k] << " ";
		}
		std::cout << "\n";
	}


	//A^-1*A:
	std::cout << "\ninverse matrix*matrix:\n\n";
	double matrixAresult[10][10];
	for (int i = 0; i < 10; i++)
	{
		double temp;
		for (int j = 0; j < 10; j++)
		{
			temp = 0;
		for (int k = 0; k < 10; k++)
		{
			temp += matrixAs[i][k] * matrixAc[k][j];
		}
		matrixAresult[i][j] = temp;
		}

	}
	std::cout << "\n\n";
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			std::cout << matrixAresult[i][k] << " ";
		}
		std::cout << "\n";
	}
	system("pause");
	return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void morfism()
{
	int n;
	cout << "Put the N: ";
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		if (i % 10 == i * i % 10)
		{
			cout << i << "\n";
		}
	}

}
void sover()
{
	int n;
	cout << "Put the N: ";
	cin >> n;
	for (size_t i = 5; i < n; i++)
	{
		int sum = 0;
		for (size_t k = 1; k < (i/2)+1; k++)
		{

			if (i % k == 0)
			{
			sum += k;

			}
		}
		if (sum == i )
		{
			cout << i << "\n";
		}
	}

}
void maxdel()
{
	int a, b;
	cout << "Put a: ";
	cin >> a;
	int a1 = a;
	cout << "Put b";
	cin >>b;
	vector<int> ab{};
	vector<int> del{};
	for (; a <= b; a++)
	{
		ab.push_back(a);
	}
	for (size_t i = 0; i <= b-a1; i++)
	{
		int kol = 0;
		for (size_t k = 1; k < ab[i]/2+1; k++)
		{
			if (ab[i] % k==0)
			{
				kol += k;
			}
		}
		del.push_back(kol);
	}

	int maxkol = del[0];
	int ind = 0;
	for (size_t i = 0; i <b-a1; i++)
	{
		if (maxkol>del[i+1])
			{
			}
		else
		{
			maxkol = del[i + 1];
			ind = i + 1;
		}
	}
	cout <<"the biggest n witn the biggest number of del "<<ab[ind];
}
void stepen()
{
	int N;
	cout << "Put N:";
	cin >> N;
	int x = 1;
	int i = 1;

	while (N > x)
	{
		x *= 2;
		i++;
	}
	cout << "2^"<<i-2 << "<= "<<N <<" <= 2^"<< i-1;
}
void armstrong()
{
	int N;
	cout << "Put N: ";
	cin >> N;
	int N1;
	for (size_t i = 1; i < N; i++)
	{
		N1 = N;
		int kol=0;
		while(N1>=1)
		{
			kol += 1;
			N1 /= 10;
		}
		cout << kol;
	}
}
	int main()
{
	int n;
	cout << "Task number: ";
	cin >> n;
	switch (n)
	{
	case(1):
		morfism();
		break;
	case(2):
		sover();
		break;
	case(3):
		maxdel();
		break;
	case(4):
		stepen();
		break;
	case(5):
		armstrong();
		break;
	}

}
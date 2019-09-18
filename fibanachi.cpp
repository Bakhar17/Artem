#include <iostream>
#include <string>
#include <vector>
using namespace std;
int a;
bool pal1(int a)
{
	string c = to_string(a);
	for (int i = 0, b = (c.length() - 1); i <= b / 2; i++)
	{
	
	if (c[i] != c[b - i])
	{
		return false;
	}
}
}
int main()
{
	cout << "put a: ";
	int  b;
	cin >> a;
	cout << "put b: ";
	cin >> b;
	for (; a <= b; a++)
	{
		if (pal1(a)) {
		cout << a << "\n";
		}

	}

}
/*void task1(int N)
{
	std::cout << "N= ";
	cin >> N;
	vector<int> fiban{};
	int fib = 0;
	int fib1 = 1;
	fiban.push_back(fib);
	fiban.push_back(fib1);
	std::cout << fiban[0] << " " << fiban[1] << " ";
	for (int i = 2; i < N; i++)
	{
		fiban.push_back(fiban[i - 1] + fiban[i - 2]);
		std::cout << fiban[i] << " ";
	}
}
	void task13(int N=1000)
	{
		vector<long long> fiban{};
		int fib = 0;
		int fib1 = 1;
		fiban.push_back(fib);
		fiban.push_back(fib1);
		for (int i = 2; i < N; i++)
		{
			fiban.push_back(fiban[i - 1] + fiban[i - 2]);
		}
		std::cout <<"fib[1000] "<< fiban[999];


}
	void task12(int N )
	{
		std::cout << "N= ";
		cin >> N;
		vector<double> fiban{};
		int fib = 0;
		int fib1 = 1;
		fiban.push_back(fib);
		fiban.push_back(fib1);
		int k = 0;
		while (fiban[k] < N)
		{
			for (int i = 2; i <= N; i++)
			{
				fiban.push_back(fiban[i - 1] + fiban[i - 2]);
			}
			k++;
		}
		std::cout << fiban[k];
	}
	void task14(int N)
	{
		vector<long long> fiban{};
		std::cout << "N= ";
		cin >> N;
		long long sum=0;
		int fib = 0;
		int fib1 = 1;
		fiban.push_back(fib);
		fiban.push_back(fib1);
			for (int i = 2; i < N; i++)
			{
				fiban.push_back(fiban[i - 1] + fiban[i - 2]);
		
			}
			int k = 0;
			while (sum < N) {
				sum += fiban[k];
				k++;
			}
			if (sum>N)
			{
				sum -= fiban[k-1];
			}
			std::cout << "summa " << sum;
	}
int main()
{
	int N;
	cin >> N;
	switch (N)
	{
	case(1): {(task1(N));
		break; }
	case(3):
	{(task13());
		break;
	}
	case(2):
	{(task12(N));
		break;
	}
	case(4):
	{
		(task14(N));
		break;
	}

	}
	
}*/
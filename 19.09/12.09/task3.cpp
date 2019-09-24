#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool poryadok(int a)
{
	int a1 = a;
	string srt = to_string(a1);
	for (size_t i = 0; i < srt.length() - 1; i++)
	{
		if (srt[i] >= srt[i + 1])
		{
			return false;
		}
	}

}



int main()
{
	cout << "Put a,b";
	int a, b;
	cin >> a;
	cin >> b;
	for (; a <= b; a++)
	{
		if( poryadok(a))
			{
				cout << a<<"\n";
			}
	}
	
}


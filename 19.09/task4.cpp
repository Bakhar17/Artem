#include <iostream>
#include <string>
using namespace std;


bool cherk(int a, int b)
{
	string ish = to_string(a);
	string vih = to_string(b);
	int i = 0, k = 0;
	while (i < ish.size() && k < vih.size())
	{
		if (ish[i] != vih[k])
		{
			k++;
		}
		else
		{
			i++; 
			k++;
		}
	}
	if (i < ish.length())
	{
		i++;
	}
	if (ish[i - 1] != vih[k - 1])
	{
		return false ;
	}
	
}


int main()
{
	int A, B;
	cout << "Put A,B(A<B)";
	cin >> A;
	cin >> B;
	if (cherk(A, B))
	{
		cout << "True";
	}
	else
	{
		cout << "False";
	}
	
}
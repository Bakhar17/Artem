#include <iostream>
#include <string>
using namespace std;


bool cherk(int a, int b)
{
	string ish = to_string(a);
	string vih = to_string(b);
	int i = 0;
	while (a != b && ish.length() > vih.length() && i<ish.length()) {
		if (ish[i] != vih[i])
		{
			vih.erase(vih[i]);
		}
		else
		{
			if (i<ish.length())
			i = i + 1;
		}
	}
	if (a != b)
	{
		return false;
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
#include <iostream>


using namespace std;

int main()
/* 1
{
int n;
cout << "Vvod n: ";
cin >> n;
while (n%2==0)
{
	n = n / 2;

}
if (n==1)
{
	cout << "Yes";
}
else
{
	cout << "NO";
}
system("pause");
}
*/
/*{
	int n, s = 0;
	cout << "Vvod n: ";
	cin >> n;
	while (n)
	{
		s += n % 10;
		n /= 10;

	}
	cout << "summa: " << s;
	system("pause");
}

{
	int day, mon, year;
	cout << "Today: \n";
	cin >> day;
	cin >> mon;
	cin >> year;
	enum  month{ jan=1,feb,march,apr,may,june,july,aug,sept,oct,nov,dec };
	switch(mon)
	{
	case(jan):case(march):case(may):case(july):case(aug):case(oct):case(nov):
	{
		if (day<31)
		{
			day += 1;
			cout << day << " " << mon << " " << year;
		}
		else
		{
			day = 1;
			mon += 1;
			cout << day << " " << mon << " " << year;
		}
		break;
	}
	case(sept):case(apr):case(june):
	{
		if (day<30)
		{
			day += 1;
			cout << day << " " << mon << " " << year;
		}
		else
		{
			day = 1;
			mon += 1;
			cout << day << " " << mon << " " << year;
		}
		break;
	}
	case(dec):
	{
		if (day < 31)
		{
			day += 1;
			cout << day << " " << mon << " " << year;
		}
		else
		{
			day = 1;
			mon = 1;
			year += 1;
			cout << day << " " << mon << " " << year;
		}
		break;
	}
	case(feb):
	{
		if (year % 4 == 0)
		{
			if (day < 29)
			{
				day += 1;
				cout << day << " " << mon << " " << year;
			}
			else
			{
				day = 1;
				mon += 1;
				cout << day << " " << mon << " " << year;
			}
		}
		else
		{
			if (day < 28)
			{
				day += 1;
				cout << day << " " << mon << " " << year;
			}
			else
			{
				day = 1;
				mon += 1;
				cout << day << " " << mon << " " << year;
			}
		}
		break;
	}
	}
}
{
int n;
cout << "Vvod n: ";
cin >> n;
double summa=0;
double fact = 1;
for (int i = 1; i <= n; i++)
{
	fact = fact/i;
	summa += fact;
}
cout << summa;
}*/
/*{
int n;
cin >> n;
int i = 2;
int del;
int znam=2;
while (znam <= n)
{
	del = 1;
	for (; del < znam; del++)
	{
		cout << del << "/" << znam << "\n";
	}
	znam++;
}
}*/
{
	int a, b, c, vr;
	cin >> a;
	cin >> b;
	c = a % b;
	if (c == 0 && c!=1)
	{
		cout << b;
	}
	else
	{
	
	while (b!=c)
	{
		if (b % c != 0)
		{

			vr = c;
			c = b % c;
			b = vr;
		}
		cout << c;
	}
}
}
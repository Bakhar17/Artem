#include <iostream>
#include <cstdlib>

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
/*summa number{
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
}*/

/* data{
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
}*/
/* task5 factorial{
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
/* task2 {
	int del = 1, znam = 1;
	int n;
	cout << "Vvod n: ";
	cin >> n;
	for (; znam < n; znam++)
	{
		int del1, znam1;
		for (; del < znam; del++)
		{
			del1 = del;
			znam1 = znam;
			do
			{
				if (del1 > znam1)
					del1 = del1 % znam1;
				else
					znam1 = znam1 % del1;
			} while (del1 != 0 && znam1 != 0);
			if (znam1 + del1 == 1)
				cout << del << "/" << znam << "\n";
		}
		del = 1;

	}
}
*/
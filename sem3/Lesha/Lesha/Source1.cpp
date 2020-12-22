#include <iostream>
#include <conio.h>
using namespace std;
struct time
{
	int hour;
	int minute;
	int second;
};
class aero
{
public:
	string whereto;
	int num;
	string typeOfPlane;
	time t;
	string day;
	aero();
	string GetWher();
	string GetDay();
	void show();
};
aero::aero()
{
	cout << "Input place where to go";
	cin >> whereto;
	cout << "Input a number of plane";
	cin >> num;
	cout << "Type of plane";
	cin >> typeOfPlane;
	cout << "Input hour";
	cin >> t.hour;
	cout << "Input minute";
	cin >> t.minute;
	cout << "Input second";
	cin >> t.second;
	cout << "Enter day";
	cin >> day;
}
void aero::show()
{
	cout << "Place :" << whereto << endl;

	cout << "Number of plane :" << num << endl;

	cout << "Type of plane :" << typeOfPlane << endl;

	cout << "Time :" << t.hour << "." << t.minute << "." << t.second << "." << endl;

	cout << "Day :" << day << endl;
}
string aero::GetWher()
{
	return whereto;
}
string aero::GetDay()
{
	return day;
}
void spisWhereto(aero spis[], int n)
{
	string wher;
	cout << "Input place where to go";
	cin >> wher;
	for (int i = 0; i < n; i++)
	{
		if (wher == spis[i].GetWher())
			spis[i].show();
	}

}
void spisDay(aero spis[], int n)
{
	string dayn;
	cout << "Input day";
	cin >> dayn;
	for (int i = 0; i < n; i++)
	{
		if (dayn == spis[i].GetDay())
			spis[i].show();
	}
}
void spisDayTime(aero spis[], int n)
{
	string dayn;
	cout << "Input day";
	cin >> dayn;
	time ti;
	cout << "Input hour";
	cin >> ti.hour;
	cout << "Input minute";
	cin >> ti.minute;
	cout << "Input second";
	cin >> ti.second;
	for (int i = 0; i < n; i++)
	{
		if (dayn == spis[i].GetDay())
		{
			if (ti.hour < spis[i].t.hour)
			{
				spis[i].show();
			}
			else if (ti.hour == spis[i].t.hour)
			{
				if (ti.minute < spis[i].t.minute)
				{
					spis[i].show();
				}
				else if (ti.minute == spis[i].t.minute)
				{
					if (ti.second < spis[i].t.second)
					{
						spis[i].show();
					}
				}

			}
		}
	}
};
int main()
{
	aero* spi;
	int n;
	cout << "Enter a number of planes: ";
	cin >> n;
	spi = new aero[n];
	for (int i = 0; i < n; i++)
	{
		spi[i].show();
	}
	spisDay(spi, n);
	spisDayTime(spi, n);
	spisDayTime(spi, n);

}
#include <iostream>
#include <vector>
#include<string>
using namespace std;


int main()
{
	enum colour { green = 1984, red, yellow, white, black };
	
	int year;
	cout << "put your year of birthday ";
	cin >> year;
	int year1 = year;
	if (year < 1989)
	{
		switch (year)
		{
		case(green):
		{
			cout << "green ";
			break;
		}
		case(red):
		{
			cout << "red";
			break;
		}
		case(yellow):
		{
			cout << "red ";
			break;
		}
		case(white):
		{
			cout << "white ";
			break;
		}
		case(black):
		{
			cout << "black ";
			break;
		}
		}
	}
	else
	{
		while (year > 1988)
		{
			year = year - 5;
			if (year < 1989)
			{
				switch (year)
				{
				case(green):
				{
					cout << "green ";
					break;
				}
				case(red):
				{
					cout << "red";
					break;
				}
				case(yellow):
				{
					cout << "yellow ";
					break;
				}
				case(white):
				{
					cout << "white ";
					break;
				}
				case(black):
				{
					cout << "black ";
					break;
				}
				}
			}


		}
	}
	
	enum animal { rat = 1984, cow, tiger, rabbit, dragon, snake, horse, oven, monkey, hen, dog, pig };
	if (year1 < 1996)
	{
		switch (year1)
		{
		case(rat):
		{
			cout << "rat ";
			break;
		}
		case(cow):
		{
			cout << "cow ";
			break;
		}
		case(tiger):
		{
			cout << "tiger ";
			break;
		}
		case(rabbit):
		{
			cout << "rabbit ";
			break;
		}
		case(dragon):
		{
			cout << "dragon ";
			break;
		}
		case(snake):
		{
			cout << "snake ";
			break;
		}
		case(horse):
		{
			cout << "horse ";
			break;
		}
		case(oven):
		{
			cout << "oven ";
			break;
		}
		case(monkey):
		{
			cout << "monkey ";
			break;
		}
		case(hen):
		{
			cout << "hen ";
			break;
		}
		case(dog):
		{
			cout << "dog ";
			break;
		}
		case(pig):
		{
			cout << "pig ";
			break;
		}

		}
	}
	if (year1 > 1996)
	{
		while (year1 > 1996)
			year1 -= 12;
		switch (year1)
		{
		case(rat):
		{
			cout << "rat ";
			break;
		}
		case(cow):
		{
			cout << "cow ";
			break;
		}
		case(tiger):
		{
			cout << "tiger ";
			break;
		}
		case(rabbit):
		{
			cout << "rabbit ";
			break;
		}
		case(dragon):
		{
			cout << "dragon ";
			break;
		}
		case(snake):
		{
			cout << "snake ";
			break;
		}
		case(horse):
		{
			cout << "horse ";
			break;
		}
		case(oven):
		{
			cout << "oven ";
			break;
		}
		case(monkey):
		{
			cout << "monkey ";
			break;
		}
		case(hen):
		{
			cout << "hen ";
			break;
		}
		case(dog):
		{
			cout << "dog ";
			break;
		}
		case(pig):
		{
			cout << "pig ";
			break;
		}

		}
	}

}


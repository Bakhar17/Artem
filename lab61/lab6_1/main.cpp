#include <iostream>
#include "train.h"
#include <vector>

void task1(std::vector<Train> &tr1,std::string q)
{	for (int i = 0; i < size(tr1); i++)
{
	WhereTo(tr1[i], q);
}
std::cout << "Nothing more\n";
}

void task2(std::vector<Train>& tr2, std::string c) {
		for (int i = 0; i < size(tr2); i++)
	{
		WhereToE(tr2[i], c);
	}
		std::cout << "Nothing more\n";
	
}
int main()
{
	Train b("Petr", 2, '+');
	Train c, k,w,e,g,s,h,y;
	k = {"Malin",5,'+' };
	c = {"Kamenka",11,'-' };
	w = { "Malin",12,'+' };
	e = { "Malin",3,'-' };
	g = { "Malin",9,'+' };
	s = { "Kamenka",10,'-' };
	h = { "Malin",1,'-' };
	y = { "Kamenka",2,'-' };
	std::cout << b<<c<<k;
	std::string q;
	std::cout << "UsualBus ";
	std::cin >> q;

	//std::cout << b;
	std::vector<Train> tr1 = { b,c,k,w,e,g,s,h,y};
	task1(tr1, q);
	std::cout << "ExpressBus ";
	std::cin >> q;
	task2(tr1, q);
}
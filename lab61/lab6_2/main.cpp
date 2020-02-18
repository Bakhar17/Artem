#include <iostream>
#include "func.h"
#include <fstream>

int main() {
	std::cout << sizeof(int);
	std::ofstream fout("res.txt");
	//Rational b,c,q;
	//b = { 4,6 };
	//c = { 1,4 };
	//std::cout << b<<"\t"<<c<<"\n";
	//q = b+c;
	//std::cout << q<<"\n";
	//q = b * c;
	//std::cout << q<<"\n";
	//q = b / c;
	//std::cout << q<<"\n";
	//std::cout << (b == c);
	Rational math = { 3345,1482 };
	Rational gran = { 3393,1482 };
	Rational shag = { 1,29640 };
	while (math < gran) {
		fout << math << "\n";
		math = math+shag;
	}
}
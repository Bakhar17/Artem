#include <iostream>
#include "func.h"

int main() {
	Rational b,c,q;
	b = { 4,6 };
	c = { 1,4 };
	std::cout << b<<"\t"<<c<<"\n";
	q = b+c;
	std::cout << q<<"\n";
	q = b * c;
	std::cout << q<<"\n";
	q = b / c;
	std::cout << q<<"\n";
	std::cout << (b == c);
}
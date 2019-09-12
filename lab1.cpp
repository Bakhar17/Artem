#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	cout << "1  ";
	string s;
	cout << "What's your name: ";
	cin >> s;
	cout << "Nice to meet you," + s<<endl;

	cout << "2  ";
	int x, y, c;
	cout << "Put x: ";
	cin >> x;
	cout << "Put y: ";
	cin >> y;
	c = x + y;
	cout << "x + y =";
	cout << c << endl;
	c = x - y;
	cout << "x - y =";
	cout << c << endl;
	c = x * y;
	cout << "x * y =";
	cout << c << endl;
	c = x / y;
	cout << "x / y =";
	cout << c << endl;
	cout << "3  ";
	int b;
	b = y;
	y = x;
	x = b;
	cout << "x= ";
	cout << x << endl;
	cout << "y= " ;
	cout << y << endl;
	cout << "4  ";
	double d;
	d =((3 + x * x - y * y * y)*1. * (x + 3) * (x + 3) / (x - y * y));
	cout << "Get: ";
	cout << d<<endl;
	cout << "5  Seconds to days:";
	cin >> b; 
	b = (b % 86400);
	int g;
	g = b / 3600;
	b = (b % 3600)/60;
	cout << "Now: ";
	cout << g;
	cout << ":";
	cout << b<<endl;

	cout << "6  ";
	float a,q,w,w1,w2,w3,w4,w5,w6,w7,w8,w9,w10,w10a,w10b;
	cin >> a;
	q = a * a;
	w = q * q;
	cout << "a^4=";
	cout << w << endl;

	w1 = w * q;
	cout << "a^6=";
	cout << w1 << endl;

	w2 = w1 * a;
	cout << "a^7=";
	cout << w2 << endl;

	w3 = w * w;
	cout << "a^8=";
	cout << w3 << endl;

	w4 = w3 * a;
	cout << "a^9=";
	cout << w4 << endl;

	w5 = w3 * q;
	cout << "a^10=";
	cout << w5 << endl;

	w6 = w3 * w*a;
	cout << "a^13=";
	cout << w6<<endl;

	w7 = w2 * a*w2; 
	cout << "a^15=";
	cout << w7 << endl;

	w8 = w7 * w1;
	cout << "a^21=";
	cout << w8 << endl;

	w9 = w7 * w6;
	cout << "a^28=";
	cout << w9 << endl;


	w10a = w3 * w3;
	w10b = w10a * w10a;
	w10 = w10b * w10b;
	cout << "a^64=";
	cout << static_cast<unsigned long long>(w10) << endl;

	cout << "7  ";
	cout << "Put x:";
	cin >> q;
	d = q * q;
	double f,h;
	f = 4 * d * q + 3 * d + 2 * q + 1;
	h = q * (-4 * d + 3 * q - 2) + 1;
	cout << "(1): ";
	cout << f<<endl;
	cout << "(2): ";
	cout << h;
	system("pause");

}
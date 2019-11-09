#pragma once
#include <iostream>
class Rational
{
public:
	Rational();
	Rational(int a1, int b1) :a(a1), b(b1) { reduce(a, b); };
	Rational(const Rational& r);

	~Rational();
	friend std::istream& operator>>(std::istream& in, Rational& a);
	friend std::ostream& operator<<(std::ostream& out, Rational & a);
	friend Rational operator+(Rational& f, Rational& s);
	friend Rational operator*(Rational& f, Rational &s);
	friend Rational operator/(Rational& f, Rational& s);
	friend bool operator==(Rational& f, Rational& s);
	friend bool operator>(Rational& f, Rational& s);
	friend bool operator<(Rational& f, Rational& s);
private:
	int a;
	int b;
	void reduce(int& a,int& b);
};
void Rational::reduce(int& a,int& b) {
	if (b != 0) {
		for (size_t i = 2; i <=a; i++)
		{
			while (b%i==0&&a%i==0)
			{
				b /= i;
				a /= i;
			}
		}
	}
	else {
		std::cout << "Division by zero";
		std::abort();
	}
}
Rational::Rational()
{
}

Rational::~Rational()
{
}
Rational::Rational(const Rational& a):a(a.a),b(a.b)
{
}

std::istream& operator>>(std::istream& in, Rational& a) {
	in >> a.a >> a.b;
	return in;
}
std::ostream& operator<<(std::ostream& out, Rational& a) {
	out << a.a <<'/'<< a.b;
	return out;
}

Rational operator+(Rational& f, Rational& s) {
	Rational c;
	c = { (f.a * s.b + f.b * s.a),(f.b * s.b) };
	return c;
}
Rational operator*(Rational& f, Rational& s) {
	Rational c;
	c = { f.a * s.a,f.b * s.b };
	return c;
}
Rational operator/(Rational& f, Rational& s) {
	Rational c;
	c = { f.a * s.b,f.b * s.a };
	return c;
}
bool operator==(Rational& f, Rational& s) {
	if (f.a == s.a && f.b == s.b) {
		return true;
	}
	return false;
}
bool operator>(Rational& f, Rational& s) {
	Rational c;
	c = { (f.a * s.b - f.b * s.a),(f.b * s.b) };
	double r = c.a / c.b;
	if (c.a > 0) {
		return true;
	}
	else false;

}
bool operator<(Rational& f, Rational& s) {
	Rational c;
	c = { (f.a * s.b - f.b * s.a),(f.b * s.b) };
	double r = c.a / c.b;
	if (r < 0) {
		return true;
	}
	else return false;
}
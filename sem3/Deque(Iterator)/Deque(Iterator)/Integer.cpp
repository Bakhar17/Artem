#include "Integer.h"

Integer::Integer()
{
}
Integer::~Integer()
{

}
void Integer::Accept(Visitor& v) {
	v.VisitInt(this);
}

Integer::Integer(int x_) :x(x_) {}

std::ostream& operator<<(std::ostream& out, const Integer& obj) {
	out << obj.x;
	return out;
}
Integer::Integer(const Integer& other) {
	this->x = other.x;
}
void operator>>(std::istream& in, Integer& obj) {
	int kx;
	in >> kx;
	obj.x = kx;
}

Visitor::Visitor() {}
Visitor::~Visitor() {}

void IntegerVisitor::VisitInt(Integer* x) {
	sum = sum + x->GetInt();
}
int IntegerVisitor::GetSum()const {
	return this->sum;
}



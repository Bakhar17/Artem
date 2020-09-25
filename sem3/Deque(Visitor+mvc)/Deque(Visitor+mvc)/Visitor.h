#ifndef VISITOR_H_
#define VISITOR_H_


class Visitor
{
public:
	virtual void Visit(int&)=0;
	virtual ~Visitor();

protected:
	Visitor();
};

Visitor::Visitor() {}
Visitor::~Visitor(){}


class IntVisitor:public Visitor {
public:
	virtual void Visit(int&)override;
	int GetSum()const;
private:
	int sum = 0;
};

void IntVisitor::Visit(int& x) {
	sum += x;
}

int IntVisitor::GetSum()const {
	return this->sum;
}
#endif // !VISITOR_H_


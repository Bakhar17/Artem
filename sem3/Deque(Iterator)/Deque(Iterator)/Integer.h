#ifndef INTEGER_H_
#define INTEGER_H_
#include <iostream>

class Visitor;

class Integer
{
public:
	Integer();
	Integer(int x_);
	~Integer();
	Integer(const Integer&);
	friend std::ostream& operator<<(std::ostream& out, const Integer&);
	friend void operator>>(std::istream&, Integer&);
	int GetInt()const { return this->x; };
	void Accept(Visitor& v);
private:
	int x = 0;
};


//Visitor 
class Visitor
{
public:
	virtual void VisitInt(Integer*) = 0;
	virtual ~Visitor();	
	Visitor();
};


class IntegerVisitor :public Visitor
{
public:
	virtual void VisitInt(Integer*)override ;
	int GetSum()const;
private:
	int sum = 0;
};


#endif // !INTEGER_H_


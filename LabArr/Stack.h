#pragma once
#include <iostream>
class Stack
{
public:
	Stack(int size) :size(size)
	{
		top = new int[size];
	}
	Stack() {};
	~Stack();
	int pop();
	void push(int x);
	int peek();
	bool empty();

private:
	int* top=nullptr;
	int size;
};


Stack::~Stack()
{
	if (top != nullptr) {
		top = &(top[0]);
		delete[]top;
	}

}

int Stack::pop() {
	if (top != nullptr) {
	int x = *top;
	top--;
	delete (top + 1);
	return x;
	}
	throw 1;
}
void Stack::push(int x) {
	if (top != &(top[size]) && top!=&(top[0])) {
	top++;
	*top = x;
	}
	else if (top == &(top[0])) {
	*top=x;
	} 
	else{
		std::cout << "Stack is over";
	}

}
int Stack::peek() {
	return *top;
}
bool Stack::empty() {
	if (top == nullptr) {
		return 1;
	}
	return 0;
}
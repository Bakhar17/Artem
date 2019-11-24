#pragma once
#include <iostream>
using namespace std;
class stack
{
	int top;
	char body[100];
public:
	int prior(char x)
	{
		if ((x = '*') || (x = '/')) return 2;
		if ((x = '+') || (x = '-')) return 1;
		if ((x = '(') || (x = ')')) return 0;
	}
	stack() { top = 0; }
	bool empty() { return top == 0; }
	char get_top_element() { return body[top]; }
	int top_prior() { return prior(body[top]); }
	void push(char x)
	{
		top++;
		body[top] = x;
	}
	char pop()
	{
		top--;
		return body[top + 1];
	}

};



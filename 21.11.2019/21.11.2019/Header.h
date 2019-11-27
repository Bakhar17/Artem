#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class stack
{
	int top;
	char body[100];
public:
	int prior(char x)
	{
		if ((x == '*') || (x == '/')) return 2;
		if ((x == '+') || (x == '-')) return 1;
		if ((x == '(') || (x == ')')) return 0;
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

class stackint
{
	int top;
	vector<double> sum;
public:
	stackint() { top = 0; }
	void push(double x)
	{
		top++;
		sum.push_back(x);
	}
	void pop()
	{
		top--;
		sum.erase(sum.end()-1);
	}
	double get_top_element() { return sum[top-1]; }
};


void Calc(const string& pnote) {
	stackint final;
	size_t i = 0;
	if (pnote[0]=='-') {
		string temp1 = "";
		temp1 += stoi(pnote);
		i = size(temp1);
	}
	for (; i < pnote.size(); i++)
	{
		if (pnote[i] == ' ' && (pnote[i + 1] != '+' || pnote[i + 1] != '-' || pnote[i + 1] != '*' || pnote[i + 1] != '/')) {
			size_t t = i - 1;
			while (pnote[t] >= '1' && t != 0 && pnote[t] <= '9') {
				t--;
			}
			string temp1;
			if (t != 0) {
				t++;
			}
			for (; t < i; t++)
			{
				temp1 += pnote[t];
			}
			final.push(stoi(temp1));
		}
		if (pnote[i] == '+') {
			double oper1 = final.get_top_element();
			final.pop();
			double oper2 = final.get_top_element();
			final.pop();
			final.push(oper2 + oper1);
		}
		if (pnote[i] == '-') {
			double oper1 = final.get_top_element();
			final.pop();
			double oper2 = final.get_top_element();
			final.pop();
			final.push(oper2 - oper1);
		}
		if (pnote[i] == '*') {
			double oper1 = final.get_top_element();
			final.pop();
			double oper2 = final.get_top_element();
			final.pop();
			final.push(oper2 * oper1);
		}
		if (pnote[i] == '/') {
			double oper1 = final.get_top_element();
			final.pop();
			double oper2 = final.get_top_element();
			final.pop();
			final.push(oper2 / oper1 * 1.0);
		}

	}
	std::cout << final.get_top_element() << "\n";
}

string OPZ(const char (&note)[100]) {
	int i = 0;
	stack s;
	string pnote;
	if (note[0] == '-') {
		pnote += note[0];
		i++;
	}

	for (; i < strlen(note); i++)
	{
		if (note[i] == '(') s.push(note[i]);
		else if ((note[i] == '+') || (note[i] == '-') || (note[i] == '/') || (note[i] == '*'))
		{
			while ((!s.empty()) && (s.top_prior() >= s.prior(note[i])))
			{
				pnote += s.pop();
			}
			s.push(note[i]);
		}
		else if (note[i] == ')')
		{
			while ((!s.empty()) && (s.get_top_element() != '('))
			{
				pnote += s.pop();
			}
			s.pop();
		}
		else
		{
			string temp = "";
			while (i < strlen(note) && note[i] != '+' && note[i] != '-' && note[i] != '/' && note[i] != '*' && note[i] != '(' && note[i] != ')') {
				temp += note[i];
				i++;
			}
			pnote += temp += " ";
			i--;
		}
	}
	while (!s.empty())
	{
		pnote += s.pop();
	}
	return pnote ;

}
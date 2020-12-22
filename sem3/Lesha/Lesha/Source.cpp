#include <iostream>
#include <fstream>
#include <stack>
#include <string>
using namespace::std;

bool checkStack(const stack<char>& left, const stack<char>& right) {
	char l = left.top();
	char r = right.top();
	if ((l == '(' && r == ')')||(l == '{' && r == '}')|| (l=='['&&r ==']')) {
		return true;
	}
	return false;
}
int algorithm(string stroka) {
	stack<char> leftStack;
	stack<char> rightStack;
	for (size_t i = 0; i < stroka.size(); i++)
	{
		if (stroka[i] == ':') {
			if (i > 0 && (stroka[i - 1] == '{' || stroka[i - 1] == '[' || stroka[i - 1] == '(' || stroka[i - 1] == '}' || stroka[i - 1] == ']' || stroka[i - 1] == ')')) {
				stroka.erase(i - 1, 2);
			}
			else if (i < stroka.size() && (stroka[i + 1] == '{' || stroka[i + 1] == '[' || stroka[i + 1] == '(' || stroka[i + 1] == '}' || stroka[i + 1] == ']' || stroka[i + 1] == ')')) {
				stroka.erase(i, 2);
			}
		}
	}

	for (size_t i = 0; i < stroka.size(); i++)
	{
		if (stroka[i] == '{' || stroka[i] == '[' || stroka[i] == '(') {
			leftStack.push(stroka[i]);
		}
		if (stroka[i] == '}' || stroka[i] == ']' || stroka[i] == ')') {
			rightStack.push(stroka[i]);
			if (leftStack.size() < rightStack.size()) {
				return 1;
			}
			if (checkStack(leftStack, rightStack)) {
				leftStack.pop();
				rightStack.pop();
			}
			else {
				return 2;
			}
		}
	}
	if (leftStack.size() != rightStack.size()) {
		return 3;
	}
}
int main() {
	string stroka;

	std::ifstream fin("smiles.in.txt");
	std::ofstream fout("smiles.out.txt");
	while (!fin.eof()) {
		string temp="";
		fin >> temp;
		fout << algorithm(temp) << "\n";
	}
	return 0;
}
#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;
class Program
{
public:
	Program();
	~Program();
	void PushVector(vector<string>&vlist) {
		ifstream fin("Text.txt");
		while (!fin.eof()) {
			string str;
			getline(fin, str);
			vlist.push_back(str);
		}
	}
	void PushList(list<string>& slist) {
		ifstream fin("Text.txt");
		while (!fin.eof()) {
			string str;
			getline(fin, str);
			slist.push_back(str);
		}
	}
	void PushDeque(deque<string>& dlist) {
		ifstream fin("Text.txt");
		while (!fin.eof()) {
			string str;
			getline(fin, str);
			dlist.push_back(str);
		}
	}
	void Copy(list<string>&, deque<string>&);
	void Copy(vector<string>&, deque<string>&);
	void Copy(deque<string>&, vector<string>&);
	void Copy(deque<string>&, list<string>&);
private:
	list<string> slist;
	deque<string> dlist;
	vector<string> vlist;
};

Program::Program()
{
}

Program::~Program()
{
}
void Program::Copy(list <string>& list, deque<string>&deque) {
	copy(list.begin(), list.end(), deque);
}
void Program::Copy(vector <string>& list, deque<string>& deque) {
	copy(list.begin(), list.end(), deque);
}
void Program::Copy(deque <string>& list, vector<string>& deque) {
	copy(list.begin(), list.end(), back_inserter(deque));
}
void Program::Copy(deque<string>& list, list<string> & deque) {
	copy(list.begin(), list.end(), deque.begin());
}
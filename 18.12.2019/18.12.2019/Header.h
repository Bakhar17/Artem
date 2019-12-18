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
	void Sort(vector<string>&);
	void Sort(deque<string>&);
	void Sort(list<string>&);
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
	copy(list.begin(), list.end(), deque.begin());
}
void Program::Copy(vector <string>& list, deque<string>& deque) {
	copy(list.begin(), list.end(), deque.begin());
}
void Program::Copy(deque <string>& list, vector<string>& deque) {
	copy(list.begin(), list.end(), back_inserter(deque));
}
void Program::Copy(deque<string>& lis, list<string> & deque) {
	copy(lis.begin(), lis.end(), deque.begin());
}
bool comp(string left, string right) {
	int s = size(left) > size(right)?  size(left): size(right);
	for (size_t i = 0; i < s; i++)
	{
		if (left[i] > right[i]) {
			return 1;
		}
	}
	return 0;
}
void Program::Sort(vector<string>& vect) {
	sort(vect.begin(), vect.end(), comp);
}
void Program::Sort(list<string>& list) {
	sort(list.begin(), list.end(), comp);
}
void Program::Sort(deque<string>& deque) {
	sort(deque.begin(), deque.end(), comp);
}
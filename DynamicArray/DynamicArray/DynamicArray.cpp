#include"Array.h"
#include"Stack.h"
#include"Queue.h"
#include<iostream>
using namespace std;
int main() {
	Queue<double> ti;
	ti.pushback(0);
	ti.pushback(11);
	ti.pushback(22);
	cout << ti.top() << '\n';
	ti.pushback(33);
	ti.pushback(44);
	ti.pushback(55);
	cout << ti.top() << '\n';
	ti.pushback(66);
	ti.pushback(77);
	std::cout << "\n";
	ti.popfront();
	ti.popfront();
	std::cout << "\n";
	Stack<float> t;
	t.pushback(21);
	t.pushback(22);
	t.pushback(23);
	if (!t.IsEmpty()) {
		t.pushback(24);
		t.pushback(25);
		t.pushback(26);
	}
	cout << t.head() << '\n';
	t.popback();
	cout << t.head() << '\n';
	t.popback();

}

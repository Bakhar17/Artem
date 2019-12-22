#pragma once
#include <iostream>
using namespace std;
template<class T>
struct Nodes {
	T data;
	Nodes* prev;
	Nodes() = default;
	Nodes(const T& data, Nodes* n = nullptr) :data(data), prev(n) {}
};

template<class T>
class Stack {
private:
	size_t size_=0;
	Nodes<T>* top;

public:

	Stack() = default;
	Stack(const Stack&) = default;
	void Pop();
	void Push(T value);
	T Top()const {
		if (size_) {
			return top->data;
		}
	}
	bool empty() { return !size_; };
		//T& operator[](int index) {
		//	if (!IsEmpty()) { return data[index]; }
		//	else { delete[]data; assert(false); }
		//}
};
template <class T>
void Stack<T>::Push(T value) {
	Nodes<T>* node = new Nodes<T>(value, top);
	top = node;
	size_++;
}
template< class T>
void Stack<T>::Pop() {
	if (size_ == 0) {
		return;
	}
	Nodes<T>* ptr = top->prev;
	delete top;
	top = ptr;
	size_--;
}

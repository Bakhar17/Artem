#pragma once
#include<cassert>
template<class T>
class Stack {
private:
	size_t size;
	T* data;
	unsigned int capacity;

public:
	Stack();
	explicit Stack(size_t _size);
	const void Pop();
	const void Push(T value);
	const T head();
	const bool IsEmpty();
	const int stackelements();
	const void clear() { data = nullptr; size = 0; capacity = 0; }
	~Stack() { clear(); };
	T& operator[](int index) {
		if (!IsEmpty()) { return data[index]; }
		else { delete[]data; assert(false); }
	}
};

template<class T>
Stack<T>::Stack() : size(0), data(nullptr), capacity(0) {}
template<class T>
Stack<T>::Stack(size_t _size) : size(_size), data(new T[_size]), capacity(_size)
{}
template<class T>
const void Stack<T>::Pop() {
	if (!IsEmpty()) {
		size_t newsize = size - 1;
		if (size == capacity * 4) {
			newsize = size / 2;
		}
		T* temp = new T[newsize];
		for (size_t i = 1; i < capacity - 1; i++) {
			temp[i] = data[i];
		}
		delete[]data;
		size = newsize;
		capacity--;
		data = temp;
	}
	else {
		delete[]data;
		assert(false);
	}
}
template<class T>
const void Stack<T>::Push(T value) {
	if (this->size == 0) {
		this->size = 2;
		this->data = new T[2];
		this->capacity++;
		this->data[0] = value;
		return;
	}
	if (this->capacity < this->size) {
		this->data[this->capacity] = value;
		this->capacity++;
	}
	else {
		T* tmp = new T[this->size * 2];
		for (size_t i = 0; i < this->capacity; i++) {
			tmp[i] = this->data[i];
		}
		tmp[this->capacity] = value;
		this->capacity++;
		delete[]this->data;
		this->data = tmp;
		this->size *= 2;
	}
}
template<class T>
const T Stack<T>::head() {
	if (!IsEmpty()) {
		return this->data[capacity - 1];
	}
	else {
		delete[]data;
		assert(false);
	}
}
template<class T>
const bool Stack<T>::IsEmpty() {
	return !this->capacity;
}
template<class T>
const int Stack<T>::stackelements() {
	if (!IsEmpty()) {
		return capacity;
	}
	else {
		delete[]data;
		assert(false);
	}
}
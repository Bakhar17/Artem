#pragma once
#include<cassert>
template<class T>
class Queue {
private:
	T* data;
	size_t size;
	unsigned int capacity;
public:
	Queue();
	explicit Queue(size_t _size);
	const void popfront();
	const void pushback(T value);
	const T top();
	bool IsEmpty();
	const int QueneElements();
	const void clear() { delete[]data; data = nullptr; size = 0; capacity = 0; }
	T& operator[](int index) {
		if (!IsEmpty()) { return data[index]; }
		else { delete[]data; assert(false); }
	}
	~Queue() { delete[] data; }
};

template<class T>
Queue<T>::Queue() :data(nullptr), size(0), capacity(0)
{}
template<class T>
Queue<T>::Queue(size_t _size) : data(new T[_size]), size(_size), capacity(_size)
{}
template<class T>
const void Queue<T>::pushback(T value) {
	if (size == 0) {
		size = 2;
		data = new T[2];
		capacity++;
		data[0] = value;
		return;
	}
	if (capacity < size) {
		data[capacity] = value;
		capacity++;
	}
	else {
		T* tmp = new T[size * 2];
		for (size_t i = 0; i < capacity; i++) {
			tmp[i] = data[i];
		}
		tmp[capacity] = value;
		capacity++;
		delete[]data;
		data = tmp;
		size *= 2;
	}
}
template<class T>
const T Queue<T>::top() {
	if (!IsEmpty()) {
		return data[0];
	}
	else {
		assert(("QUENE IS EMPTY", false));
	}
}
template<class T>
bool Queue<T>::IsEmpty() {
	return !capacity;
}
template<class T>
const int Queue<T>::QueneElements() {
	if (!IsEmpty()) {
		return capacity;
	}
	else {
		assert(("QUENE IS EMPTY", false));
	}
}

template<class T>
const void Queue<T>::popfront() {
	if (!IsEmpty()) {
		size_t newsize = size - 1;
		if (size == capacity * 4) {
			newsize = size / 2;
		}
		T* tmp = new T[newsize];
		for (size_t i = 1; i < capacity - 1; i++) {
			tmp[i] = data[i + 1];
		}
		delete[]data;
		size = newsize;
		capacity--;
		data = tmp;
	}
	else {
		delete[]data;
		assert(("QUEUE IS EMPTY", false));
	}
}
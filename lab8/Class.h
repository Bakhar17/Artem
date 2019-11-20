#pragma once
#include <iostream>

class Array
{
public:
	Array();
	explicit Array(size_t _size);
	Array(const Array& c);
	Array& operator=(const Array& c);
	int& operator[](size_t index);
	const int& operator[](size_t index) const;
	void At(size_t index, int value);

	~Array();
	class ErrorIndex
	{
	public:
		size_t index;
		ErrorIndex(size_t index1) :index(index1)
		{
		}
	};

private:
	int* data;
	size_t size;
};



Array::Array(const Array& c)
{
	this->size = c.size;
	this->data = new int[size];
	for (int i = 0; i < size; i++)
	{
		this->data[i] = c.data[i];
	}
}
Array::Array() :data(nullptr), size(0)
{
}
Array::Array(size_t _size) : data(new int[_size]), size(_size)
{

}
Array& Array:: operator=(const Array& c)
{
	if (this != &c)
	{

		this->size = c.size;
		delete[]data;
		this->data = new int[size];
		for (int i = 0; i < size; i++)
		{
			this->data[i] = c.data[i];
		}
	}
	return *this;
}
Array::~Array()
{
	delete[]data;
}
int& Array::operator[](size_t index)
{
	return data[index];
}
const int& Array::operator[](size_t index) const
{
	return data[index];
}
void Array::At(size_t index, int value)
{
	if (index > this->size - 1)
	{
		throw ErrorIndex(index);
	}
	this->data[index] = value;
}

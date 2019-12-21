#include"Array.h"
#include<cassert>
Array::Array(size_t _size) : data(new int[_size]), size(_size), elements(_size), grow(0) {}
Array::Array() : data(nullptr), size(0), elements(0), grow(0) {}
Array::Array(const Array& c)
{
	this->elements = c.elements;
	this->grow = c.grow;
	this->size = c.size;
	this->data = new int[size];
	for (int i = 0; i < size; i++)
	{
		this->data[i] = c.data[i];
	}
}


Array& Array:: operator=(const Array& c)
{
	if (this != &c)
	{
		this->elements = c.elements;
		this->grow = c.grow;
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
int& Array::operator[](int index)
{
	if (index < 0 || index >= this->size) {
		delete[]this->data;
		assert(false, "OUT OF RANGE");

	}
	this->elements = index;
	return data[index];
}
void Array::SetAt(size_t index, int value)
{
	if (index > this->size - 1 || index < 0)
	{
		delete[]this->data;
		assert(false, "OUT OF RANGE");
	}
	this->data[index] = value;
	if (index > this->elements) {
		this->elements = index;
	}
}
const int Array::GetSize() {
	return this->size;
}
const void Array::FreeExtra(size_t newsize) {
	if (!IsEmpty()) {
		Array tmp(newsize);
		for (size_t i = 0; i < newsize; i++) {
			tmp[i] = this->data[i];
		}
		*this = tmp;
	}
	else {
		delete[]data;
		assert(false, "ALREADY EMPTY");
	}
}
const bool Array::IsEmpty() {
	return !this->size;
}
const int Array::GetUpperBound() {
	if (!IsEmpty()) {
		return this->data[elements - 1];
	}
	else {
		delete[] data;
		assert(false, "ARRAY IS EMPTY");
	}

}
const void Array::RemoveAll() {
	delete[]this->data;
}
const void Array::SetSize(size_t size, size_t grow) {
	if (size == this->size) {
		return;
	}
	if (size < this->size) {

		this->FreeExtra(size);
		return;
	}
	Array tmp(size + grow);
	for (size_t i = 0; i < this->elements; i++) {
		tmp[i] = this->data[i];
	}
	*this = tmp;

}
const void Array::Add(size_t indexpos, int value) {
	if (indexpos >= this->size) {
		SetSize(indexpos, 5);
		this->data[indexpos] = value;
	}

	else {
		delete[]this->data;
		assert(false, "LOGIC ERROR");
	}
}
const void Array::InsertAt(size_t index, int value) {
	SetSize(this->size * 2);
	for (size_t i = this->size - 1; i > index; i--) {
		this->data[i] = this->data[i - 1];
	}
	this->elements++;
	this->data[index] = value;
}
const void Array::RemoveAt(size_t index) {
	if (!IsEmpty() && index < this->elements && index >= 0) {
		for (size_t i = index; i < this->size - 1; i++) {
			this->data[i] = this->data[i + 1];
		}
		this->elements--;
		this->FreeExtra(this->size - 1);
	}
	else {
		delete[]data;
		assert(false, "BAD INDEX");
	}
}
const Array Append(Array& A, Array& B) {
	size_t newsize, smallersize;
	A.size > B.size ? newsize = A.size, smallersize = B.size : newsize = B.size, smallersize = A.size;
	Array result(newsize);
	for (size_t i = 0; i < smallersize; i++) {
		result[i] = A[i] + B[i];
	}
	return result;
}
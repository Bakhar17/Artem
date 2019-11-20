#include "class.h"

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
size_t Array::GetSize() {
	return this->size;
}
bool Array::IsEmpty() {
	if (this->size == 0) {
		return true;
	}
	else return false;
}
Array Array::SetSize(size_t size, int grow) {
	if (size > this->size) {
		this->size += grow;
		return *this;
	}
	else {
		Array b{size };
		for (size_t i = 0; i < size; i++)
		{
			b[i] = this->data[i];
		}
		delete []this;
		return b;
	}
}
void Array::RemoveAll() {
	delete [] data;
	data = nullptr;
	size = 0;
}

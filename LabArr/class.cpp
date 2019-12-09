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
	for (size_t i = 0; i < size; i++)
	{
		this->data[i] = -0;
	}
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
int& Array::operator[](size_t index)
{
	return data[index];
}
const int& Array::operator[](size_t index) const
{
	return data[index];
}
void Array::SetAt(size_t index, int value)
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
	if (size >= this->size) {
		int temp_size = this->size;
		while (size >= this->size) {

			this->size += grow;
		}
		Array b{ this->size };
		for (size_t i = 0; i < temp_size; i++)
		{
			b[i] = this->data[i];
		}
		*this = b;
		return *this;
	}
	else {
		Array b{size };
		for (size_t i = 0; i < size; i++)
		{
			b[i] = this->data[i];
		}
		*this = b;
		return *this;
	}
}
void Array::RemoveAll() {
	delete[] this->data;
}

void Array::Add(int x) {
	this->SetSize(this->size + 1, 1);
	this->SetAt(this->size - 1, x);
}
void Array::GetAt(int index) {
	if(index<this->GetSize())
	std::cout<< this->data[index]<<"\n";
}
int Array::GetUpperBound() {
	int pos =-1;
	int _size = this->GetSize();
	size_t i = 0;
	for (i=_size-1 ; i !=0; i--)
	{
		if (this->data[i] != 0) {
			pos = i+1;
			break;
		}
	}
	if (pos >= _size) {
		return -1;
	}
	return pos;
}
void Array::RemoveAt(size_t index) {
	if (index < this->size) {
		Array b{ index };
		for (size_t i = 0; i < index; i++)
		{
			b[i] = this->data[i];
		}
		*this = b;
	}
	else {
		std::cout << "Wrong index, enter new(max " << this->GetSize()-1 << "): ";
		std::cin >> index;
		RemoveAt(index);
	}
}
void Array::FreeExtra() {
	size_t pos = this->GetUpperBound();
	if (pos != -1) {
		this->RemoveAt(pos);
	}
}

const Array Array::Append(const Array& oper2) const {
	size_t min_size;
	size_t max_size;
	if (this->size <= oper2.size) {
		min_size = this->size;
		max_size = oper2.size;
	}
	else {
		max_size = this->size;
		min_size = oper2.size;
	}
	Array sum(max_size);
	if (max_size == min_size) {
		for (size_t i = 0; i < min_size; i++)
		{
			sum.data[i] = this->data[i] + oper2.data[i];
		}
		return sum;
	}

	if (max_size > this->size) {
		for (size_t i = 0; i < min_size; i++)
		{
			sum.data[i] = this->data[i] + oper2.data[i];
		}
		for (size_t i = min_size; i < max_size; i++)
		{
			sum.data[i] = oper2.data[i];
		}

	}

	else {
		for (size_t i = 0; i < min_size; i++)
		{
			sum.data[i] = this->data[i] + oper2.data[i];
		}
		for (size_t i = min_size; i < max_size; i++)
		{
			sum.data[i] = this->data[i];
		}
	}
	return sum;
}
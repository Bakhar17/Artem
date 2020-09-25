#ifndef ARRAY_H_
#define ARRAY_H_
#include <algorithm>
#include <utility>
#include <fstream>
#include <iostream>
template<class T>
class Array
{
public:
	explicit Array()=default;
	Array(int size);
	Array(const Array<T>&);
	Array(const std::initializer_list<T>&);
	Array(Array&&)noexcept;
	T& operator[](int index);
	const T& operator[](int index)const;
	Array& operator=(const Array<T>&);
	Array& operator=(Array&&)noexcept;
	const bool operator==(const Array<T>&)const;
	const bool operator!=(const Array<T>&)const;
	void PushFront(const T&);
	void PushBack(const T&);
	const bool IsEmpty()const;
	const int Size()const;
	const T Front()const;
	const T Back()const;
	void PopBack();
	void PopFront();
	~Array();
protected:
	void Clear();
private:
	T* data_=nullptr;
	int size_=0;
	int capacity_=0;
};


template<class T>
void Array<T>::Clear() {
	delete[] data_;
	size_ = capacity_ = 0;
}


template<class T>
Array<T>::Array(int size) :size_(size)
{
	capacity_ = size + 20;
	data_ = new T [capacity_];
	for (int i = 0; i < size_; i++)
	{
		data_[i] = 0;
	}
}


template<class T>
Array<T>::Array(const Array<T>& other):size_(other.size_),capacity_(other.capacity_)
{
	data_ = new T[capacity_];
	for (int i = 0; i < size_; i++)
	{
		data_[i] = other.data_[i];
	}
}


template<class T>
Array<T>::Array(const std::initializer_list<T>& list) : size_(list.size()), capacity_(list.size() + 24)
{
	data_ = new T[capacity_];
	int k = 0;
	for (auto i = list.begin(); i !=list.end(); i++)
	{
		data_[k] = (*i);
		k++;
	}
}


template<class T>
Array<T>::Array(Array<T>&& other) noexcept :data_(other.data_),size_(other.size_),capacity_(other.capacity_)
{
	other.data_ = nullptr;
	other.size_ = 0;
	other.capacity_ = 0;
}


template<class T>
const bool Array<T>::operator==(const Array<T>& other)const
{
	if (size_ != other.size_) return 0;

	for (int i = 0; i < size_; i++)
	{
		if (data_[i] != other.data_[i]) {
			return 0;
		}
	}
	return 1;
}


template<class T>
const bool Array<T>::operator!=(const Array<T>& other)const
{
	return (!(*this==other));
}


template<class T>
void Array<T>::PushFront(const T&obj)
{
	if (size_ < capacity_) {
		for (int i = size_-1; i != -1; i--)
		{
			data_[i + 1] = data_[i];
		}
		data_[0] = obj;
		size_++;
	}
	else {
		Array<T> tmp(size_ + 1);
		for (int i = 0; i < size_; i++)
		{
			tmp.data_[i + 1] = data_[i];
		}
		tmp.data_[0] = obj;
		Swap(*this, tmp);
	}
}


template<class T>
void Array<T>::PushBack(const T& obj)
{
	if (size_ < capacity_) {
		data_[size_] = obj;
		size_++;
	}
	else {
		Array<T> tmp(size_+1);
		for (int i = 0; i < size_; i++)
		{
			tmp.data_[i] = this->data_[i];
		}
		tmp.data_[size_] = obj;
		Swap(*this, tmp);
	}
}


template<class T>
const bool Array<T>::IsEmpty() const
{
	return (size_==0);
}


template<class T>
const int Array<T>::Size() const
{
	return this->size_;
}


template<class T>
const T Array<T>::Front() const
{
	return data_[0];
}


template<class T>
const T Array<T>::Back() const
{
	return data_[size_-1];
}


template<class T>
void Array<T>::PopBack()
{
	if (size_ == 0) {
		return;
	}
	size_--;
}


template<class T>
void Array<T>::PopFront()
{
	if (size_ == 0) return;
	size_--;
	for (int i = 0; i < size_; i++)
	{
		data_[i] = data_[i + 1];
	}
}


template<class T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
	if (!(*this == other)) {
		Clear();
		this->size_ = other.size_;
		this->capacity_ = other.capacity_;
		data_ = new T[size_];
		for (int i = 0; i < size_; i++)
		{
			data_[i] = other.data_[i];
		}
	}
	return *this;
}


template<class T>
Array<T>::~Array()
{
	Clear();
}


template<class T>
void Swap(T& a, T& b)
{
	T tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp);
}


template<class T>
Array<T>& Array<T>::operator=(Array<T>&& other)noexcept
{
	if (this == &other) {
		return *this;
	}
	Clear();
	data_ = other.data_;
	size_ = other.size_;
	capacity_ = other.capacity_;

	other.data_ = nullptr;
	other.capacity_ = other.size_ = 0;
	return *this;
}


template<class T>
T& Array<T>::operator[](int index) {
	if (index >= size_) throw "bad index";
	return data_[index];
}


template<class T>
const T& Array<T>::operator[](int index)const {
	if (index >= size_) throw "bad index";
	return data_[index];
}
#endif // !ARRAY_

#ifndef DEQUE_H_
#define DEQUE_H_
#include "Array.h"


template<class T>
class AbstractDeque
{
public:
	virtual ~AbstractDeque()=default;
	virtual const bool IsEmpty()const = 0;
	virtual const int Size()const = 0;
	virtual void PushBack(const T&) = 0;
	virtual void PushFront(const T&) = 0;
	virtual void PopBack() = 0;
	virtual void PopFront() = 0;
	virtual const T Front()const = 0;
	virtual const T Back()const = 0;
private:
	virtual void Clear() = 0;
};



template<class T>
class Deque:public AbstractDeque<T>,
			private Array<T>
{
public:
	Deque()=default;
	Deque(const Deque<T>&);
	Deque& operator=(const Deque<T>&);
	Deque(Deque<T>&&)noexcept;
	Deque& operator=(Deque<T>&&)noexcept;
	Deque(const std::initializer_list<T>&);
	virtual ~Deque()=default;
	virtual const bool IsEmpty()const override;
	virtual const int Size()const override;
	virtual void PushBack(const T&) override;
	virtual void PushFront(const T&) override;
	virtual void PopBack() override;
	virtual void PopFront() override;
	virtual const T Front()const override;
	virtual const T Back()const override;
	const bool operator==(const Deque<T>& other);
	const bool operator!=(const Deque<T>& other);
	T& operator[](int);
	const T& operator[](int)const;
	friend std::ostream& operator<<(std::ostream& out, const Deque<T>& obj);
private:
	virtual void Clear()override;
};


template<class T>
void Deque<T>::Clear() {
	Array<T>::Clear();
}


template<class T>
Deque<T>::Deque(const Deque<T>&other):Array<T>::Array(other){}


template<class T>
Deque<T>& Deque<T>::operator=(const Deque<T>&other)
{
	Array<T>::operator=(other);
	return *this;
}


template<class T>
Deque<T>::Deque(Deque<T>&&other)noexcept:Array<T>::Array(std::move(other)){}


template<class T>
Deque<T>& Deque<T>::operator=(Deque<T>&&other)noexcept
{
	Array<T>::operator=(std::move(other));
	return *this;
}


template<class T>
Deque<T>::Deque(const std::initializer_list<T>&list):Array<T>(list){}


template<class T>
T& Deque<T>::operator[](int index)
{
	return Array<T>::operator[](index);
}


template<class T>
const bool Deque<T>::IsEmpty() const
{
	return Array<T>::IsEmpty();
}


template<class T>
const int Deque<T>::Size() const
{
	return Array<T>::Size();
}


template<class T>
void Deque<T>::PushBack(const T& obj)
{
	Array<T>::PushBack(obj);
}


template<class T>
void Deque<T>::PushFront(const T&obj)
{
	Array<T>::PushFront(obj);
}


template<class T>
void Deque<T>::PopBack()
{
	Array<T>::PopBack();
}


template<class T>
void Deque<T>::PopFront()
{
	Array<T>::PopFront();
}


template<class T>
const T Deque<T>::Front() const
{
	return Array<T>::Front();
}


template<class T>
const T Deque<T>::Back() const
{
	return Array<T>::Back();
}


template<class T>
const bool Deque<T>::operator==(const Deque<T>& other)
{
	return Array<T>::operator==(other);
}


template<class T>
const bool Deque<T>::operator!=(const Deque<T>& other)
{
	return Array<T>::operator!=(other);
}


template<class T>
const T& Deque<T>::operator[](int index)const {
	return Array<T>::operator[](index);
}
#endif // !DEQUE_H_
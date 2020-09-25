#ifndef ITERATOR_H_
#define ITERATOR_H_
#include "Deque.h"
#include <iostream>


template <class T>
class Iterator {
public:
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual const bool IsDone() const = 0;
	virtual T CurrentItem() const = 0;
};


template<class T>
class DequeIterator :public Iterator<T>
{
public:
	DequeIterator(Deque<T>* obj);
	virtual void First()override;
	virtual void Next()override;
	virtual const bool IsDone()const override;
	virtual T CurrentItem()const override;
private:
	Deque<T>* _deque;
	int _current;
	
};


template<class T>
DequeIterator<T>::DequeIterator(Deque<T>* obj):_deque(obj),_current(0){}


template<class T>
void DequeIterator<T>::First()
{
	_current = 0;
}


template<class T>
void DequeIterator<T>::Next()
{
	_current++;
}


template<class T>
inline const bool DequeIterator<T>::IsDone() const
{
	return _current>=_deque->Size();
}


template<class T>
T DequeIterator<T>::CurrentItem()const
{
	if (IsDone()) throw "OutOfRange";
	return _deque->operator[](_current);
}
#endif // !ITERATOR_H_
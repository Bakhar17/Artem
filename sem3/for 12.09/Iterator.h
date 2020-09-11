#ifndef ITERATOR_H_
#define ITERATOR_H_

#include "Deque.h"

template <class T>
class Iterator {
public:
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() const = 0;
	virtual T CurrentItem() const = 0;
};

template <class T>
class DequeIterator : public Iterator<T>,
					  private BiDirectionalList<T> 
{
public:
	DequeIterator(const Deque<T>*);
	virtual void First() override;
	virtual void Next()override;
	virtual bool IsDone() const override;
	virtual T CurrentItem() const override;
	virtual ~DequeIterator();
private:
	const Deque<T>* _deque;
	typename BiDirectionalList<T>::Node* _current;
};


template<class T>
DequeIterator<T>::~DequeIterator(){
	_deque->~Deque();
	_current = nullptr;
}


template <class T>
DequeIterator<T>::DequeIterator(const Deque<T>* obj) :_deque(obj),_current(nullptr) {};


template <class T>
void DequeIterator<T>::First() {
	this->_current = _deque->Head();
}


template <class T>
void DequeIterator<T>::Next() {
	_current = _current->BiDirectionalList<T>::Node::Next();
}


template <class T>
bool DequeIterator<T>::IsDone()const {
	return (_current == nullptr);
}


template <class T>
T DequeIterator<T>::CurrentItem()const {
	if (IsDone()) {
		throw 1;
	}
	else {
		return (_current->BiDirectionalList<T>::Node::GetValue());
	}
}
#endif 
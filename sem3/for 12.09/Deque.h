#ifndef DEQUE_H_
#define DEQUE_H_

#include "container.h"
template<typename T>
class AbstractDeque {
public:
    virtual ~AbstractDeque() = default;
	virtual bool IsEmpty() const = 0;
	virtual void PopBack() = 0;
	virtual void PopFront() = 0;
	virtual void PushFront(const T&) = 0;
	virtual void PushBack(const T&) = 0;
	virtual int Size() const = 0;
	virtual T Front() = 0;
	virtual T Back() = 0;
	virtual const T Front()const = 0;
	virtual const T Back()const = 0;
	virtual typename BiDirectionalList<T>::Node* Head()const = 0;
};

template <class T>
class Deque : public AbstractDeque<T>,
			  private BiDirectionalList<T> 
{
public:
	Deque()=default;
	Deque(const std::initializer_list<T>&);
	Deque(const Deque&)=default;
	virtual bool IsEmpty() const override;
	virtual void PopBack() override;
	virtual void PopFront() override;
	virtual void PushFront(const T&) override;
	virtual void PushBack(const T&) override;
	virtual int Size() const override;
	virtual T Front() override;
	virtual T Back() override;
	virtual const T Front()const override;
	virtual const T Back()const override;
	virtual typename BiDirectionalList<T>::Node* Head() const override;
	virtual ~Deque() override;
};


template<class T>
Deque<T>::~Deque() {
	BiDirectionalList<T>::~BiDirectionalList();
}


template <class T>
typename BiDirectionalList<T>::Node* Deque<T>::Head() const {
	return BiDirectionalList<T>::Head();
}


template <class T>
Deque<T>::Deque(const std::initializer_list<T>& list):BiDirectionalList<T>::BiDirectionalList(list) {}


template <class T>
bool Deque<T>::IsEmpty() const {
	return BiDirectionalList<T>::IsEmpty();
}


template <class T>
void Deque<T>::PopFront() {
	BiDirectionalList<T>::PopFront();
}


template <class T>
void Deque<T>::PopBack() {
	BiDirectionalList<T>::PopBack();
}


template <class T>
void Deque<T>::PushFront(const T& obj) {
	BiDirectionalList<T>::PushFront(obj);
}


template <class T>
void Deque<T>::PushBack(const T& obj) {
	BiDirectionalList<T>::PushBack(obj);
}


template <class T>
int Deque<T>::Size() const {
	return BiDirectionalList<T>::Size();
}


template <class T>
T Deque<T>::Front() {
	return BiDirectionalList<T>::Front();
}


template <class T>
T Deque<T>::Back(){
	return BiDirectionalList<T>::Back();
}


template <class T>
const T Deque<T>::Front()const {
	return BiDirectionalList<T>::Front();
}


template <class T>
const T Deque<T>::Back()const {
	return BiDirectionalList<T>::Front();
}
#endif // !DEQUE_H_


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
protected:
	Iterator();
};

template <class T>
class DequeIterator : public Iterator<T> {
public:
	DequeIterator(const Deque<T>*);
	virtual void First();
	virtual void Next();
	virtual bool IsDone() const;
	virtual T CurrentItem() const;
private:
	const Deque<T>* _deque;
	T* _current;
};
#endif 
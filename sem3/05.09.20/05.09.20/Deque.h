#ifndef DEQUE_H_
#define DEQUE_H_

template<typename T>
class AbstractDeque {
public:
    virtual ~AbstractDeque() = default;
	virtual bool IsEmpty() const = 0;
	virtual void Pop() = 0;
	virtual void Push(const T&) = 0;
	virtual size_t Size() const = 0;
	virtual T Front() = 0;
	virtual T Back() = 0;
};
#endif // !DEQUE_H_


#pragma once
template<class T>
struct Nodeq {
	T data;
	Nodeq* next;
	Nodeq() = default;
	Nodeq(const T& data, Nodeq* n = nullptr) :data(data), next(n) {}
};
template<class T>
class Queue
{
public:
	Queue() = default;
	Queue(const Queue&) = default;
	void Pop();
	void Push(const T& value);
	T& front()const {
		if (size_) {
			return head_->data;
		}
	}
	T& back()const {
		if (size_) {
			return tail_->data;
		}
	}
	bool empty() { return !size_; };

private:
	Nodeq<T>* head_;
	Nodeq<T>* tail_;
	size_t size_=0;
};
template<class T>
void Queue<T>::Push(const T& value) {
	if (size_ == 0) {
	Nodeq<T>* node = new Nodeq<T>(value, tail_);
	head_= tail_ = node;
	size_++;
	return;
	}
	Nodeq<T>* node = new Nodeq<T>(value);
	tail_->next = node;
	tail_ = node;
	size_++;
}
template<class T>
void Queue<T>::Pop() {
	if (size_) {
	Nodeq<T>* ptr = head_->next;
	delete head_;
	head_ = ptr;
	size_--;
	}
}

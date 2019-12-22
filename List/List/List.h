#pragma once
#include <iostream>
#include <algorithm>
#include <iterator>
#include <cassert>
using namespace std;

template<class T>
struct Node {
	T data;
	Node* next;
	Node* prev;
	Node() = default;
	Node(const T& data, Node* n = nullptr, Node* p = nullptr) :
		data(data), next(n), prev(p) {}
};


template<class T>
class List {
public:
	List() = default;
	List(const List&) = default;
	~List();

	bool empty() { return !size_; };
	void insert(const T&, size_t);
	size_t find(const T&)const;
	size_t get_size() { return size_; }
	void push_front(const T&);
	void push_back(const T&);
	void remove_id(size_t);
	void remove_key(const T&);

	T& operator[](size_t);
	T& operator[](size_t)const ;
	template<class T>
	friend std::ostream& operator<<(std::ostream&, const List<T>&);

	template<class T>
	class Iterator {
	public:
		Iterator() = delete;
		Iterator(Node<T>* ptr) : cur_(ptr) {};
		~Iterator() = default;

		Iterator<T>& operator++() { cur_ = cur_->next; return *this; };
		Iterator<T>& operator--() { cur_ = cur_->prev; return *this; };
		T& operator*() { return cur_->data;  };
		bool operator==(const Iterator<T>& other) { return cur_ == other.cur_; };
		bool operator!=(const Iterator<T>& other) { return cur_ != other.cur_; };
		Node<T>* cur_;
	private:

	};

	Iterator<T> begin() { return Iterator<T>(head_); };
	Iterator<T> end() { return Iterator<T>(nullptr); };
	Iterator<T> cbegin()const { return  Iterator<T>(head_); };
	Iterator<T> cend()const { return  Iterator<T>(nullptr); };
private:
	Node<T>* head_;
	Node<T>* tail_;
	size_t size_;
	void kill_em_all_(); // Free memory of all nodes.
};


template<class T>
List<T>::~List() {
	kill_em_all_();
}


template<class T>
void List<T>::kill_em_all_() {
	if (!empty()) {
		Node<T>* tmp = head_;
		while (size_) {
			head_ = tmp->next;
			delete tmp;
			tmp = head_;
			size_--;
		}
	}
}


template<class T>
void List<T>::push_back(const T& elem)
{
	Node<T>* node = new Node<T>(elem, nullptr, tail_);
	if (empty()) {
		head_ = node;
	}
	else {
		tail_->next = node;
	}
	tail_ = node;
	size_++;
}
template<class T>
void List<T>::insert(const T& obj, size_t pos){
	if (pos > size_) {
		cout << "Wrong Pos!\n";
		return;
}
	if (pos == 0) {
		push_front(obj);
		return;
	}
	if (pos == size_) {
		push_back(obj);
		return;
	}
	if (pos < size_) {
	size_t pos_ = 0;
	Iterator<T> i = begin();
	while (pos_ != pos) {
		++i;
		pos_++;
	}
	--i;
	Node<T>* pre = i.cur_;
	++i;
	Node<T>* n = i.cur_;
	Node<T>* node = new Node<T>(obj, n, pre);
	pre->next = node;
	n->prev = node;
	}
	size_++;
}

template<class T>
std::ostream& operator<<(std::ostream& out, const List<T>& list) {
	for (size_t i = 0; i < list.size_; i++)
	{
		out << list[i]<<"\n";
	}
	return out;
}
template<class T>
void List<T>::push_front(const T& elem)
{
	Node<T>* node = new Node<T>(elem, head_, nullptr);
	if (empty()) {
		tail_ = node;
	}
	else {
		head_->prev = node;
	}
	head_ = node;
	size_++;
}
template<class T>
T& List<T>::operator[](size_t pos) {
	if (pos >= size_) {
		cout << "Wrong Pos!\n";
		abort();
	}
	Iterator<T> i = this->begin();
	size_t pos_ = 0;
	while (pos_ != pos) {
		++i;
		pos_++;
	}
	return *i;
}
template<class T>
std::ostream& operator<<(std::ostream& out, const Node<T>*& Node) {
	return Node->data;
}
template<class T>
T& List<T>::operator[](size_t pos)const {
	if (pos >= size_) {
		cout << "Wrong Pos!\n";
		abort();
	}
	Iterator<T> i = this->cbegin();
	size_t pos_ = 0;
	while (pos_ != pos) {
		++i;
		pos_++;
	}
	return *i;
}
template<class T>
size_t List<T>::find(const T& obj)const {
	size_t pos = 0;
	Iterator<T> i = this->cbegin();
	while (pos!=size_&&*i != obj) { 
	++i;
	pos++;
	}
	return pos;
}
template<class T>
void List<T>::remove_id(size_t pos) {
	if (pos >= size_) {
		cout << "Wrong Pos!\n";
		return;
	}
	if (pos > 0 && pos != size_ - 1) {
	size_t pos_ = 0;
	Iterator<T> i = this->begin();
	while (pos_ != pos) {
		++pos_;
		++i;
	}
	--i;
	Node<T>* pre = i.cur_;
	++++i;
	Node<T>* n = i.cur_;
	--i;
	delete i.cur_;
	pre->next = n;
	n->prev = pre;
	size_--;
	}
	if (pos == 0) {
		Iterator<T> i = this->begin();
		++i;
		head_ = i.cur_;
		--i;
		delete i.cur_;
		head_->prev = nullptr;
		size_--;
	}
	if (pos == size_ - 1) {
		Iterator<T> i(tail_);
		tail_ = tail_->prev;
		tail_->next = nullptr;
		delete i.cur_;
		size_--;
	}
}
template<class T>
void List<T>::remove_key(const T&obj) {
	size_t pos = this->find(obj);
	this->remove_id(pos);
}
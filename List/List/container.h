#ifndef CONTAINER_H_
#define CONTAINER_H_
#include <iostream>
#include <algorithm>
#include <iterator>
#include <cassert>
#include <vector>
using namespace std;

template<class T>
class BiDirectionalList {
public:
	struct Node {
	T value;
	Node* next;
	Node* prev;
	Node() = default;
	Node(const T& _value, Node* _n = nullptr, Node* _p = nullptr) :
		value(_value), next(_n), prev(_p) {}
};
	BiDirectionalList()=default ;
	BiDirectionalList(const BiDirectionalList&)=default;
	~BiDirectionalList();

	bool IsEmpty() { return !size_; };
	void Insert(const T&, size_t);
	int Find(const T&)const;
	int Size()const { return this->size_; }
	void PushFront(const T&);
	void PopFront();
	void PopBack();
	void PushBack(const T&);
	void remove_id(size_t);
	void remove_key(const T&);
	Node* Front() {
		return head_;
	}
	Node* Back() {
		return tail_;
	}
	const Node* Front()const {
		return  head_;
	}
	const Node* Back()const {
		return  tail_;
	}
	Node* operator[](size_t pos);
	const Node* operator[](size_t pos)const;
	template<class T>
	friend std::ostream& operator<<(std::ostream&, const BiDirectionalList<T>&);

	template<class T>
	class Iterator {
	public:
		Iterator() = delete;
		Iterator(Node* ptr) : cur_(ptr) {};
		~Iterator() = default;

		Iterator<T>& operator++() { cur_ = cur_->next; return *this; };
		Iterator<T>& operator--() { cur_ = cur_->prev; return *this; };
		T& operator*() { return cur_->value;  };
		bool operator==(const Iterator<T>& other) { return cur_ == other.cur_; };
		bool operator!=(const Iterator<T>& other) { return cur_ != other.cur_; };
		Node* cur_;
	private:

	};

	Iterator<T> begin() { return Iterator<T>(head_); };
	Iterator<T> end() { return Iterator<T>(nullptr); };
	Iterator<T> cbegin()const { return Iterator<T>(head_); };
	Iterator<T> cend()const { return Iterator<T>(nullptr); };
	vector<T> ToVector();
	vector<int> FindAll(const T&);

private:
	Node* head_=nullptr;
	Node* tail_=nullptr;
	int size_=0;
	void KillThemAll(); // Free memory of all nodes.
};
#endif // !CONTAINER_H_


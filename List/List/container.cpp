#include "container.h"
template<class T>
BiDirectionalList<T>::~BiDirectionalList() {
	KillThemAll();
}
template<class T>
void BiDirectionalList<T>::KillThemAll() {
	if (!this->IsEmpty()) {
		Node* tmp = head_;
		while (this->size_) {
			this->head_ = tmp->next;
			delete tmp;
			tmp = head_;
			size_--;
		}
	}
}
template <class T>
BiDirectionalList<T>::BiDirectionalList(std::initializer_list<T> l) {
	std::for_each(l.begin(), l.end(), [&](const T obj) {this->PushBack(obj); });
}
template<class T>
void BiDirectionalList<T>::PushBack(const T& elem)
{
	Node* node = new Node(elem, nullptr, tail_);
	if (IsEmpty()) {
		head_ = node;
	}
	else {
		tail_->next = node;
	}
	tail_ = node;
	size_++;
}
template<class T>
void BiDirectionalList<T>::Insert(const T& obj, size_t pos) {
	if (pos > size_) {
		cout << "Wrong Pos!\n";
		return;
	}
	if (pos == 0) {
		PushFront(obj);
		return;
	}
	if (pos == size_) {
		PushBack(obj);
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
		Node* pre = i.cur_;
		++i;
		Node* n = i.cur_;
		Node* node = new Node<T>(obj, n, pre);
		pre->next = node;
		n->prev = node;
	}
	size_++;
}
template<class T>
std::ostream& operator<<(std::ostream& out, const BiDirectionalList<T>& list) {
	for (size_t i = 0; i < list.Size(); i++)
	{
		out << list[i] << "\n";
	}
	return out;
}
template<class T>
void BiDirectionalList<T>::PushFront(const T& elem)
{
	Node* node = new Node(elem, head_, nullptr);
	if (IsEmpty()) {
		tail_ = node;
	}
	else {
		head_->prev = node;
	}
	head_ = node;
	size_++;
}
template<class T>
T& BiDirectionalList<T>::operator[](size_t pos) {
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
	return i.cur_->value;
}
template<class T>
const T& BiDirectionalList<T>::operator[](size_t pos)const {
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
	return i.cur_->value;
}
template<class T>
int BiDirectionalList<T>::Find(const T& obj)const {
	size_t pos = 0;
	Iterator<T> i = this->cbegin();
	while (pos != size_ && *i != obj) {
		++i;
		pos++;
	}
	if (pos == size_) {
		return -1;
	}
	return pos;
}
template<class T>
void BiDirectionalList<T>::remove_id(size_t pos) {
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
		Node* pre = i.cur_;
		++++i;
		Node* n = i.cur_;
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
void BiDirectionalList<T>::remove_key(const T& obj) {
	size_t pos = this->Find(obj);
	this->remove_id(pos);
}
template <class T>
void BiDirectionalList<T>::PopFront() {
	if (!this->IsEmpty()) {
		Node* tmp = head_;
		head_ = tmp->next;
		delete tmp;
		size_--;
	}
}
template <class T>
void BiDirectionalList<T>::PopBack() {
	if (!this->IsEmpty()) {
		Node* tmp = tail_;
		tail_ = tmp->prev;
		delete tmp;
		size_--;
	}
}
template <class T>
vector<T> BiDirectionalList<T>::ToVector() {
	vector<T> temp;
	for (size_t i = 0; i < this->size_; i++)
	{
		temp.push_back((*this)[i]->value);
	}
	return temp;
}
template <class T>
std::vector<int> BiDirectionalList<T>::FindAll(const T& _value_) {
	vector<int> res;
	for (size_t i = 0; i < this->size_; i++)
	{
		if (_value_ == (*this)[i]) {
			res.push_back(i);
		}
	}
	return res;
}
template <class T>
std::vector<T> BiDirectionalList<T>::ToVector()const {
	vector<T> temp;
	for (size_t i = 0; i < this->size_; i++)
	{
		temp.push_back((*this)[i]);
	}
	return temp;
}

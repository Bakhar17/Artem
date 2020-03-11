//
// Created by Artem on 11.03.2020.
//

#ifndef CONTAINER_H_
#define CONTAINER_H_
#include <algorithm>
#include <vector>
#include <cassert>
#include <iostream>
template<class T>
class BiDirectionalList {
public:
    struct Node {
    public:
        T value;

    private:
        friend class BiDirectionalList;

        Node* next = nullptr;
        Node* prev = nullptr;

        Node(Node* next, Node* prev, const T& val);
    };

    BiDirectionalList() = default;
    BiDirectionalList(const std::initializer_list<T>&);
    BiDirectionalList(const BiDirectionalList<T>&);
    BiDirectionalList(BiDirectionalList<T>&&);
    ~BiDirectionalList();
    int Size() const;
    bool IsEmpty() const;
    void PushFront(const T& value);
    void PushBack(const T&  value);
    void PopFront();
    void PopBack();
    void InsertBefore(int pos, const T& value);
    void InsertAfter(int pos, const T& value);
    void Erase(const T&);
    int Find(const T& value) const;
    std::vector<int> FindAll(const T& value) const;
    std::vector<T> ToVector() const;
    T Front();
    T Back();
    const T Front() const;
    const T Back()  const;
    T operator[](int i);
    const T operator[](int i) const;
    bool operator==(const BiDirectionalList<T>& other) const;
    bool operator!=(const BiDirectionalList<T>& other) const;
    BiDirectionalList& operator=(const BiDirectionalList<T>& other);
    BiDirectionalList& operator=(BiDirectionalList<T>&& other);

private:
    Node* head_ = nullptr;
    Node* tail_ = nullptr;
    int size_ = 0;
    void Clear();
};
template<class T>
BiDirectionalList<T>::Node::Node(
        BiDirectionalList::Node* next,
        BiDirectionalList::Node* prev,
        const T& val) : value(val) {
    this->next = next;
    this->prev = prev;
}
template <class T>
BiDirectionalList<T>::BiDirectionalList(const std::initializer_list<T>& el) {
    std::for_each(el.begin(), el.end(), [&](const T obj) {this->PushBack(obj); });
}
template<class T>
BiDirectionalList<T>::~BiDirectionalList() {
    Clear();
}
template<class T>
int BiDirectionalList<T>::Size() const {
    return size_;
}
template<class T>
bool BiDirectionalList<T>::IsEmpty() const {
    return size_ == 0;
}
template<class T>
void BiDirectionalList<T>::PushFront(const T& value) {
    if (!size_) {
        head_ = tail_ = new Node(nullptr, nullptr, value);
    }
    else {
        head_ = new Node(head_, nullptr, value);
        head_->next->prev = head_;
    }
    size_++;
}
template<class T>
void BiDirectionalList<T>::PushBack(const T& value) {
    if (!size_) {
        head_ = tail_ = new Node(nullptr, nullptr, value);
    }
    else {
        tail_ = new Node(nullptr, tail_, value);
        tail_->prev->next = tail_;
    }
    size_++;
}
template<class T>
void BiDirectionalList<T>::PopFront() {
    assert(size_ > 0);
    Node* temp = head_;
    head_ = head_->next;
    delete temp;
    size_--;

    if (!size_) {
        head_ = nullptr;
        tail_ = nullptr;
    }
    else {
        head_->prev = nullptr;
    }
}
template<class T>
void BiDirectionalList<T>::PopBack() {
    assert(size_ > 0);
    Node* temp = tail_;
    tail_ = tail_->prev;
    delete temp;
    size_--;

    if (!size_) {
        head_ = nullptr;
        tail_ = nullptr;
    }
    else {
        tail_->next = nullptr;
    }
}
template<class T>
int BiDirectionalList<T>::Find(const T& value) const {
    int i = 0;
    Node* cur = head_;

    while (cur != nullptr) {
        if (cur->value == value) {
            return i;
        }
        else {
            cur = cur->next;
            i++;
        }
    }

    return -1;
}
template<class T>
std::vector<int> BiDirectionalList<T>::FindAll(const T& value) const {
    int i = 0;
    Node* cur = head_;
    std::vector<int> data;
    while (cur != nullptr) {
        if (cur->value == value) {
            data.push_back(i);
        }
        i++;
        cur = cur->next;
    }
    return data;
}
template<class T>
std::vector<T> BiDirectionalList<T>::ToVector() const {
    std::vector<T> data;
    Node* cur = head_;

    while (cur != nullptr) {
        data.push_back(cur->value);
        cur = cur->next;
    }

    return data;
}
template<class T>
void BiDirectionalList<T>::InsertBefore(int pos, const T& value) {
    assert(size_ > 0 && pos < size_ && pos >= 0 );
    Node* temp = head_;
    while (pos--) {
        temp = temp->next;
    }
    Node* insert_el = new Node(temp, temp->prev, value);
    insert_el->prev->next = insert_el;
    insert_el->next->prev = insert_el;
    size_++;
}
template<class T>
void BiDirectionalList<T>::InsertAfter(int pos, const T& value) {
    assert(size_ > 0 && pos < size_ && pos >= 0);
    Node* temp = head_;
    while (pos--) {
        temp = temp -> next;
    }
    Node* insert_el = new Node(temp->next, temp, value);
    insert_el->next->prev = insert_el;
    insert_el->prev->next = insert_el;
    size_++;
}
template<class T>
void BiDirectionalList<T>::Erase(const T& element) {
    int pos = Find(element);
    assert(pos != -1);
    Node* temp = head_;
    while (pos--) {
        temp = temp->next;
    }
    if (temp == head_) {
        head_ = head_->next;
        delete head_->prev;
        head_->prev = nullptr;
    }
    else if(temp == tail_){
        tail_ = tail_->prev;
        delete tail_->next;
        tail_->next = nullptr;
    }
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
    size_--;
}

template<class T>
bool BiDirectionalList<T>::operator==(const BiDirectionalList<T>& other) const {
    if (size_ != other.size_)
        return false;

    Node* cur_t = this->head_;
    Node* cur_o = other.head_;

    while (cur_t != nullptr && cur_o != nullptr) {
        if (cur_o->value != cur_t->value) {
            return false;
        }
        cur_o = cur_o->next;
        cur_t = cur_t->next;
    }

    return true;
}

template<class T>
bool BiDirectionalList<T>::operator!=(const BiDirectionalList<T>& other) const {
    return !(*this == other);
}
template<class T>
BiDirectionalList<T>& BiDirectionalList<T>::operator=(const BiDirectionalList<T>& other) {
    if (&other == this) {
        return *this;
    }

    Clear();

    Node* cur_o = other.head_;
    while (cur_o != nullptr) {
        PushBack(cur_o->value);
        cur_o = cur_o->next;
    }

    return *this;
}
template<class T>
BiDirectionalList<T>::BiDirectionalList(const BiDirectionalList<T>& other) {
    *this = other;
}
template<class T>
BiDirectionalList<T>& BiDirectionalList<T>::operator=(BiDirectionalList<T>&& other) {
    if (this == &other)
        return *this;

    Clear();

    head_ = other.head_;
    tail_ = other.tail_;
    size_ = other.size_;

    other.size_ = 0;
    other.head_ = nullptr;
    other.tail_ = nullptr;

    return *this;
}
template<class T>
BiDirectionalList<T>::BiDirectionalList(BiDirectionalList<T>&& other) {
    *this = std::move(other);
}

template<class T>
T BiDirectionalList<T>::operator[](int i) {
    assert(0 <= i && i < size_);
    Node* cur = head_;
    while (i--) {
        cur = cur->next;
    }
    return cur->value;
}
template<class T>
const T BiDirectionalList<T>::operator[](int i) const {
    assert(0 <= i && i < size_);
    Node* cur = head_;
    while (i--) {
        cur = cur->next;
    }
    return cur->value;
}

template<class T>
T BiDirectionalList<T>::Front() {
    assert(size_ > 0);
    return head_->value;
}

template<class T>
T BiDirectionalList<T>::Back() {
    assert(size_ > 0);
    return  tail_->value;
}

template<class T>
const T BiDirectionalList<T>::Front() const {
    assert(size_ > 0);
    return head_->value;
}

template<class T>
const T BiDirectionalList<T>::Back() const {
    assert(size_ > 0);
    return tail_->value;
}

template<class T>
void BiDirectionalList<T>::Clear() {
    while (size_ != 0) {
        PopFront();
    }
}
#endif
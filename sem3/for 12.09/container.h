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
            Node* Next();
            T GetValue();
        private:
            friend class BiDirectionalList;
            Node* next = nullptr;
            Node* prev = nullptr;
            Node(Node* next, Node* prev, const T& val);
            bool IsDone();
            
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
        T Front();
        T Back();
        const T Front() const;
        const T Back()  const;
        bool operator==(const BiDirectionalList<T>& other) const;
        bool operator!=(const BiDirectionalList<T>& other) const;
        BiDirectionalList& operator=(const BiDirectionalList<T>& other);
        BiDirectionalList& operator=(BiDirectionalList<T>&& other);
        Node* Head()const ;
    private:
        Node* head_ = nullptr;
        Node* tail_ = nullptr;
        int size_ = 0;
        void Clear();
    };


    template<class T>
    bool BiDirectionalList<T>::Node::IsDone() {
        return this->next == nullptr;
    }


    template<class T>
    T BiDirectionalList<T>::Node::GetValue() {
        return this->value;
    }


    template <class T>
    typename BiDirectionalList<T>::Node* BiDirectionalList<T>::Node::Next() {
        return this->next;
    }
    template <class T>
    typename BiDirectionalList<T>::Node* BiDirectionalList<T>::Head()const {
        return this->head_;
    }

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
//
// Created by Artem on 11.03.2020.
//

#ifndef QUEUE_H_
#define QUEUE_H_
#include "container.h"

template<typename T>
class Abstract_Queue {
public:
    virtual ~Abstract_Queue() = default;
    virtual T Get() = 0;
    virtual const T Get() const = 0;
    virtual bool IsEmpty() const = 0;
    virtual void Pop() = 0;
    virtual void Push(const T&) = 0;
    virtual size_t Size() const = 0;

};


template<typename T>
class Queue : public Abstract_Queue<T>,
              virtual private BiDirectionalList<T> {
public:
    Queue() = default;
    Queue(const Queue&) = default;
    Queue(std::initializer_list<T>);
    ~Queue() override = default;

    T Get() override;
    const T Get() const override;
    bool IsEmpty() const override;
    void Pop() override;
    void Push(const T&) override;
    size_t Size() const override;

};


template<typename T>
Queue<T>::Queue(std::initializer_list<T> list) : BiDirectionalList<T>(list) {}
template<typename T>
T Queue<T>::Get() {
    return BiDirectionalList<T>::Front();
}
template<typename T>
const T Queue<T>::Get() const {
    return BiDirectionalList<T>::Front();
}
template<typename T>
bool Queue<T>::IsEmpty() const {
    return BiDirectionalList<T>::IsEmpty();
}
template<typename T>
void Queue<T>::Pop() {
    BiDirectionalList<T>::PopFront();
}
template<typename T>
void Queue<T>::Push(const T& value) {
    BiDirectionalList<T>::PushBack(value);
}

template<typename T>
size_t Queue<T>::Size() const {
    return BiDirectionalList<T>::Size();
}

#endif
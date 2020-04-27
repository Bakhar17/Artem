#ifndef SHARED_PTR_H_
#define SHARED_PTR_H_

#include <cassert>


template<typename T>
class SharedPtr {
public:
    explicit SharedPtr(std::nullptr_t);
    explicit SharedPtr(T*);
    SharedPtr();
    SharedPtr(const SharedPtr<T>&);
    SharedPtr(SharedPtr<T>&&);
    ~SharedPtr();

    SharedPtr<T>& operator=(const SharedPtr<T>& ptr);
    SharedPtr<T>& operator=(SharedPtr<T>&& ptr);

    T* Get();
    const T* Get() const;

    T& operator *();
    T* operator->();

    const T* operator->() const;
    const T& operator *() const;

    void Release();

    bool operator== (const SharedPtr<T>& rhs) const;
    bool operator!= (const SharedPtr<T>& rhs) const;
    bool operator== (const T* rhs) const;
    bool operator!= (const T* rhs) const;

private:
    T* obj_ = nullptr;
    int* ref_counter_ = nullptr;
    bool* is_valid_ = nullptr;

    void Remove();//destructor
    void MakeNull();
    void Copy(const SharedPtr<T>& ptr); // extra function for copy operator
    };

template<typename T>
SharedPtr<T>::SharedPtr(std::nullptr_t) {
    MakeNull();
}

template<typename T>
SharedPtr<T>::SharedPtr() {
   MakeNull();
}

template<typename T>
SharedPtr<T>::SharedPtr(T* obj) {
    obj_ = obj;
    ref_counter_ = new int(1);
    is_valid_ = new bool(true);
}

template<typename T>
SharedPtr<T>::~SharedPtr() {
    Remove();
}

template<typename T>
T* SharedPtr<T>::Get() {
   return obj_;
}

template<typename T>
const T* SharedPtr<T>::Get() const {
    return obj_;
}

template<typename T>
void SharedPtr<T>::Release() {
    if (is_valid_ != nullptr) {
       *is_valid_ = false;
    }
    obj_ = nullptr;
}

template<typename T>
void SharedPtr<T>::Remove() {
    if (ref_counter_ != nullptr) {
        --(*ref_counter_);
        if (*ref_counter_ == 0) {
            if (*is_valid_) {
                delete(obj_);
            }
            delete(ref_counter_);
            delete(is_valid_);
        }
    }
}

template<typename T>
SharedPtr<T>::SharedPtr(const SharedPtr<T>& ptr) {
    Copy(ptr);
    if (ref_counter_ != nullptr) {
        ++(*ref_counter_);
    }
}

template<typename T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T>& ptr) {
    if (*this == ptr) {
        return *this;
    }
    Remove();
    Copy(ptr);
    if (ref_counter_ != nullptr)
        ++(*ref_counter_);
    return *this;
}

template<typename T>
SharedPtr<T>::SharedPtr(SharedPtr<T>&& ptr) {
    if (ptr.obj_ != nullptr) {
        Copy(ptr);
    }
    else {
        ptr.Remove();
    }
    ptr.MakeNull();
}

template<typename T>
SharedPtr<T>& SharedPtr<T>::operator=(SharedPtr<T>&& ptr) {
    if (*this == ptr) {
        return *this;
    }  
    Remove();
    Copy(ptr);
    ptr.MakeNull();
    return *this;
}

template<typename T>
void SharedPtr<T>::MakeNull() {
    obj_ = nullptr;
    is_valid_ = nullptr;
    ref_counter_ = nullptr;
}

template<typename T>
T* SharedPtr<T>::operator->() {
    return Get();
}

template<typename T>
const T* SharedPtr<T>::operator->() const {
    return Get();
}

template<typename T>
T& SharedPtr<T>::operator*() {
    assert(obj_ != nullptr);
    return *obj_;
}

template<typename T>
const T& SharedPtr<T>::operator*() const {
    assert(obj_ != nullptr);
    return *obj_;
}

template<typename T>
bool SharedPtr<T>::operator==(const SharedPtr<T>& right) const {
    return Get() == right.Get();
}

template<typename T>
bool SharedPtr<T>::operator!=(const SharedPtr<T>& right) const {
    return Get() != right.Get();
}

template<typename T>
bool SharedPtr<T>::operator==(const T* right) const {
    return Get() == right;
}

template<typename T>
bool SharedPtr<T>::operator!=(const T* right) const {
    return Get() != right;
}

template<typename T>
bool operator==(const T* left, const SharedPtr<T>& right) {
    return left == right.Get();
}

template<typename T>
bool operator!=(const T* left, const SharedPtr<T>& right) {
    return left != right.Get();
}

template<typename T>
void SharedPtr<T>::Copy(const SharedPtr<T>& ptr) {
    obj_ = ptr.obj_;
    is_valid_ = ptr.is_valid_;
    ref_counter_ = ptr.ref_counter_;
}


#endif
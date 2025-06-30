// DynamicArray.h
#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>

#define COUNT_DYNAMIC_ARRAY_COPIES 1

template<typename T>
class DynamicArray {
private:
    T* data;
    int capacity;
    int count;

#if COUNT_DYNAMIC_ARRAY_COPIES != 0
    int copyCounter;
#endif

public:
    DynamicArray();
    ~DynamicArray();

    void Append(const T& value);
    void push_back(const T& value);
    void pop_back();
    void shrink_to_fit();
    T& operator[](int index);

#if COUNT_DYNAMIC_ARRAY_COPIES != 0
    int GetCopyCount() const;
#endif
};

#include "DynamicArray.tpp"

#endif

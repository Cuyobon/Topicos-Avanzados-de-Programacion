// LinkedList.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template<typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;

public:
    LinkedList();
    void push_front(const T& value);
    void pop_front();
    void Print();
    void Clear();
};

#include "LinkedList.tpp"

#endif

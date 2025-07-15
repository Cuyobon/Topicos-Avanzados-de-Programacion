/*
    SentinelLinkedList.h modificado 

    Cambios realizados:
    - Se agregaron las funciones PushFront(T value) y PopFront(), manteniendo el resto del código exactamente como fue entregado en clase.
    - Ambas funciones operan en tiempo constante y respetan la estructura centinela original.
    - No se alteraron otras partes del archivo, como lo indicó profe.

*/

#pragma once

#include <iostream>
using namespace std;

template <typename T>
class SentinelLinkedList
{
private:
    template <typename T>
    class Node
    {
    public:
        Node()
        {
            prev = nullptr;
            next = nullptr;
        }

        Node(T value)
        {
            data = value;
            prev = nullptr;
            next = nullptr;
        }

        T data;
        Node<T>* next;
        Node<T>* prev;
    };

private:
    Node<T>* NIL; // un puntero al primer y último nodo de nuestra lista ligada.
    int count; // número de elementos en esta lista ligada.

public:
    SentinelLinkedList()
    {
        count = 0;
        NIL = new SentinelLinkedList::Node<T>();
        NIL->next = NIL;
        NIL->prev = NIL;
    }

    int GetCount() { return count; };

    SentinelLinkedList::Node<T>& Find(T value);
    SentinelLinkedList::Node<T>& FindV2(T value);

    SentinelLinkedList::Node<T>& Successor(SentinelLinkedList::Node<T>* node)
    {
        return node->next;
    }

    SentinelLinkedList::Node<T>& Predecessor(SentinelLinkedList::Node<T>* node)
    {
        return node->prev;
    }

    void PushBack(T value);
    T PopBack();
    void PushFront(T value);
    T PopFront();
    void Insert(T valueToInsert, Node<T>* previousNode);
    void Remove(T valueToRemove);
    T Front();

    int operationCounter;
};

template<typename T>
void SentinelLinkedList<T>::Remove(T valueToRemove)
{
    Node<T>* currentNode = NIL->next;

    while (currentNode != NIL)
    {
        if (currentNode->data == valueToRemove)
        {
            currentNode->prev->next = currentNode->next;
            currentNode->next->prev = currentNode->prev;

            delete currentNode;
            count--;
            return;
        }
        else
        {
            currentNode = currentNode->next;
        }
    }
}

template<typename T>
typename SentinelLinkedList<T>::template Node<T>& SentinelLinkedList<T>::Find(T value)
{
    Node<T>* currentNode = NIL->next;

    while (currentNode != NIL)
    {
        if (currentNode->data == value)
        {
            return *currentNode;
        }
        else
        {
            currentNode = currentNode->next;
        }
    }
    return *nullptr;
}

template<typename T>
typename SentinelLinkedList<T>::template Node<T>& SentinelLinkedList<T>::FindV2(T value)
{
    Node<T>* currentNode = NIL->next;

    while (currentNode != NIL)
    {
        if (currentNode->data == value)
            return *currentNode;

        currentNode = currentNode->next;
    }
    return *nullptr;
}

template<typename T>
void SentinelLinkedList<T>::Insert(T valueToInsert, SentinelLinkedList<T>::Node<T>* previousNode)
{
    Node<T>* newNode = new Node<T>(valueToInsert);

    newNode->next = previousNode->next;
    previousNode->next = newNode;
    newNode->next->prev = newNode;
    newNode->prev = previousNode;

    count++;
}

template<typename T>
void SentinelLinkedList<T>::PushBack(T value)
{
    Node<T>* newNode = new Node<T>(value);
    newNode->next = NIL;

    NIL->prev->next = newNode;

    newNode->prev = NIL->prev;
    NIL->prev = newNode;

    count++;
}

template<typename T>
T SentinelLinkedList<T>::PopBack()
{
    if (count == 0)
    {
        cout << "Cuidado, estás haciendo pop back cuando ya no hay elementos en esta lista ligada";
        return {};
    }

    Node<T>* penultimateNode = NIL->prev;

    NIL->prev = penultimateNode->prev;
    penultimateNode->prev->next = NIL;

    T data = penultimateNode->data;

    delete penultimateNode;
    penultimateNode = nullptr;
    count--;

    return data;
}

template<typename T>
void SentinelLinkedList<T>::PushFront(T value)
{
    Node<T>* newNode = new Node<T>(value);

    newNode->next = NIL->next;
    newNode->prev = NIL;

    NIL->next->prev = newNode;
    NIL->next = newNode;

    count++;
}

template<typename T>
T SentinelLinkedList<T>::PopFront()
{
    if (count == 0)
    {
        cout << "Cuidado, estás haciendo PopFront cuando la lista está vacía." << endl;
        return {};
    }

    Node<T>* firstNode = NIL->next;
    T data = firstNode->data;

    NIL->next = firstNode->next;
    firstNode->next->prev = NIL;

    delete firstNode;
    count--;

    return data;
}

template <typename T>
T SentinelLinkedList<T>::Front()
{
    if (count == 0)
    {
        cout << "Advertencia, se está tratando de acceder al primer elemento de una SentinelLinkedList, pero está vacía" << endl;
        return {};
    }
    return NIL->next->data;
}

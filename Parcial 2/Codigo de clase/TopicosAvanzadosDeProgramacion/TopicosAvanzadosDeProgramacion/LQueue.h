/*
    LQueue.h
    Implementación de la clase LQueue

    - LQueue es una cola genérica (template) basada en una SentinelLinkedList.
    - Implementa las funciones Enqueue, Dequeue, Front y GetCount.
    - Todas las operaciones principales (Enqueue y Dequeue) funcionan en tiempo constante 

    Requisitos cumplidos(segun yo jaja):
    - Usa exactamente la clase SentinelLinkedList dada en clase (excepto por las funciones nuevas agregadas en el Punto 1).
    - No realiza recorridos de lista, respetando eficiencia.
*/

#pragma once

#include "SentinelLinkedList.h"
#include <iostream>
using namespace std;

template <typename T>
class LQueue
{
private:
    SentinelLinkedList<T> data;

public:
    LQueue()
    {
    }

    int GetCount()
    {
        return data.GetCount();
    }

    void Enqueue(T value);

    T Dequeue();

    T Front()
    {
        return data.Front();
    }
};

// IMPLEMENTACIONES

template <typename T>
void LQueue<T>::Enqueue(T value)
{
    data.PushBack(value);
}

template <typename T>
T LQueue<T>::Dequeue()
{
    return data.PopFront();
}
#pragma once

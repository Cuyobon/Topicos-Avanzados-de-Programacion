#pragma once

#include <iostream>
using namespace std;

#define STACK_DEFAULT_SIZE 10

template <typename T>
class Stack
{
public:
	Stack()
	{
		head = 0;
	}

	void Push(T value);

	T Pop();

	// también se le conoce a veces como Top. Es lo mismo que Pop pero sin sacar el elemento.
	T Peak();

	int Count() { return head; };

private:
	T data[STACK_DEFAULT_SIZE]; // cuántos elementos caben en esta stack
	int head; // en qué índice del array está el tope de la pila actualmente. También nos dice cuántos elementos tiene dentro actualmente
};

template <typename T>
void Stack<T>::Push(T value)
{
	// hay que checar que no se pase de la capacidad del array
	if (head == STACK_DEFAULT_SIZE)
	{
		// quiere decir que nos pasamos de la capacidad, por tanto no añadimos e imprimimos una advertencia
		cout << "Advertencia, intentó meter más elementos de los que caben en este Stack." << endl;
		return;
	}
	// pone el value en la posición que head diga
	data[head] = value;
	head++;
}

template <typename T>
T Stack<T>::Pop()
{
	// tenemos que checar que no se haga Pop cuando ya está vacía la stack.
	if (head == 0)
	{
		// quiere decir que nos pasamos de la capacidad, por tanto no añadimos e imprimimos una advertencia
		cout << "Advertencia, intentó sacar más elementos esta Stack ya está vacía." << endl;
		return {};
	}

	T value = data[head-1];

	head--; // esto hace que se "quite" el elemento de la pila.
	return value;
}

template <typename T>
T Stack<T>::Peak()
{
	// tenemos que checar que no se haga Pop cuando ya está vacía la stack.
	if (head == 0)
	{
		// quiere decir que nos pasamos de la capacidad, por tanto no añadimos e imprimimos una advertencia
		cout << "Advertencia, esta Stack ya está vacía. No hay elemento para hacer Peak" << endl;
		return {};
	}

	return data[head-1];
}

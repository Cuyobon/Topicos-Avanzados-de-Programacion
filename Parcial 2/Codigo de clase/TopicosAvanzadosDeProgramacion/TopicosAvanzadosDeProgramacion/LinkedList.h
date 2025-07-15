#pragma once

#include <iostream>
using namespace std;

/*
Template <typename T>
Class List
{
	Node<T>* first;
	int size;
};

*/

template <typename T>
class Node
{
public:
	Node()
	{

	}

	Node(T value) 
	{
		data = value;
	}

	T data;
	Node<T>* next;
};

// La lista guarda nodos, pero los nodos guardan T, es decir, cualquier otro tipo de dato.

template <typename T>
class LinkedList
{
private:
	Node<T>* first; // un puntero al primer nodo de nuestra lista ligada.
	// Node<T>* last; // aqu� nos quedamos para el jueves 19.
	int count; // n�mero de elementos en esta lista ligada.

public:
	LinkedList()
	{
		count = 0;
		first = nullptr;
	}

	int GetCount() { return count; };

	Node<T>& Find(T value);

	Node<T>& FindV2(T value);

	Node<T>& Successor(Node<T>* node)
	{
		return node->next;
	}

	Node<T>& Predecessor(Node<T>* node)
	{
		// si es el primer nodo de la lista no tiene predecesor.
		if (node == first)
			return nullptr;

		Node<T> *currentNode = first;
		// mientras no lo encontremos y no hayamos llegado al final de la lista
		while (currentNode->next != node && currentNode->next != nullptr)
		{
			currentNode = currentNode->next;
		}

		// comprobamos la raz�n por la cual se sali� del ciclo while:
		// 1) porque s� encontramos al predecesor
		if (currentNode->next == node)
		{
			return currentNode; // regresamos EL PREDECESOR
		}

		// 2) porque no estaba ese nodo 
		if (currentNode->next == nullptr)
		{
			cerr << "ERROR: se pidi� el predecesor de este nodo, pero no existe en esta lista. Verifique que este nodo pertece a esta lista." << endl;
			return nullptr;
		}

		// array predecesor:
		// dame el predecesor del elemento 5
		// return array[4];
		// el array es SUPER eficaz para obtener successor y predecessor: una sola operaci�n.
	}


	// A�ade un nuevo nodo al final de la lista.
	void PushBack(T value);

	// Quita el nodo del final de la lista y devuelve su valor.
	T PopBack();

	// Un nodo con el valor valueToInsert se insertar� como el Next de previousNode.
	void Insert(T valueToInsert, Node<T>* previousNode);

	int operationCounter;
};



template<typename T>
Node<T>& LinkedList<T>::Find(T value)
{
	// empieza en el primer de la lista
	Node<T>* currentNode = first; // usamos una variable auxiliar para no tocar la referencia al first.

	// hacemos un ciclo para checar todos los nodos, hasta que ya no haya nodo siguiente.
	while (currentNode != nullptr)
	{
		// checa si la data del nodo actual es igual al valor a encontrarse (value)
		if (currentNode->data == value)
		{
			// NOTA: Estas dos l�neas son equivalentes, pero la flecha -> es m�s c�moda y pr�ctica y est�ndar.
			// currentNode->data
			// (*currentNode).data

			// si s� lo tiene, regresamos dicho nodo y nos salimos de la funci�n.
			return currentNode;
		}
		else
		{
			// si no lo tiene, continuamos al nodo que le sigue a currentNode.
			currentNode = currentNode->next;
		}
	}

	// si llegamos a esta parte del c�digo, es porque no encontramos ning�n nodo con el valor value.
	// entonces regresamos nullptr porque no existe dicho nodo.
	return nullptr;
}


template<typename T>
Node<T>& LinkedList<T>::FindV2(T value)
{
	// empieza en el primer de la lista
	Node<T>* currentNode = first; // usamos una variable auxiliar para no tocar la referencia al first.

	// hacemos un ciclo para checar todos los nodos, hasta que ya no haya nodo siguiente.
	while (currentNode != nullptr)
	{
		// checa si la data del nodo actual es igual al valor a encontrarse (value)
		if (currentNode->data == value)
			return currentNode;

		// si no lo tiene, continuamos al nodo que le sigue a currentNode.
		currentNode = currentNode->next;
	}

	// si llegamos a esta parte del c�digo, es porque no encontramos ning�n nodo con el valor value.
	// entonces regresamos nullptr porque no existe dicho nodo.
	return nullptr;
}

template<typename T>
void LinkedList<T>::Insert(T valueToInsert, Node<T>* previousNode)
{
	// Un nodo con el valor valueToInsert se insertar� como el Next de previousNode.

	// Nuevo nodo que ser� el nuevo Next de previousNode 
	Node<T>* newNode = new Node<T>(valueToInsert); // usamos una variable auxiliar para no tocar la referencia al first.

	// NOTA, es importante primero hacer la que va de newNode a previousNode->next y despu�s la de previousNode->next a newNode, 
	// porque si no newNode termina teni�ndose como su propio next, lo cual es un grave error.

	// Hacemos la conexi�n desde newNode hacia el next de previousNode
	newNode->next = previousNode->next;

	// Hacemos la conexi�n desde previousNode hacia newNode como su next
	previousNode->next = newNode;

	// aumentar el tama�o de la lista.
	count++;
}

// A�ade un nuevo nodo al final de la lista.
template<typename T>
void LinkedList<T>::PushBack(T value)
{
	// Creamos un nuevo nodo con el valor value como su data.
	Node<T>* newNode = new Node<T>();
	newNode->data = value;
	newNode->next = nullptr;

	// si first es nullptr
	if (first == nullptr)
	{
		// entonces no hay ning�n nodo, y este que se est� agregando se va a volver first.
		first = newNode;
		count++;
		return; // y ya acabamos, salimos de la funci�n.
	}

	// Obtenemos el �ltimo nodo de la lista. Queremos el nodo cuyo next es igual a nullptr.
	Node<T>* lastNode = first;
	while (lastNode->next != nullptr)
	{
		lastNode = lastNode->next;
		operationCounter++;
	}
	// cuando salimos de este while, ya estamos en el last node.
	// ahora ya podemos decirle a lastNode que su next ya no es nullptr, es el nuevo nodo.
	lastNode->next = newNode;

	count++; // como metimos un nuevo elemento, aumentamos el contador de elementos.
}

template<typename T>
T LinkedList<T>::PopBack()
{
	// si no hay ning�n elemento.
	if (count == 0)
	{
		cout << "Cuidado, est�s haciendo pop back cuando ya no hay elementos en esta lista ligada";
		return {}; // {} es un elemento de tipo T con su valor por defecto, sin importar de qu� tipo sea T.
	}

	// si solo queda un elemento, entonces lo manejamos de esta manera
	if (count == 1)
	{
		// obtenemos su data para retornarla.
		T data = first->data;
		// lo borramos y ponemos first como nullptr
		delete first;
		first = nullptr;
		count--;
		// regresamos la data
		return data;
	}

	// tenemos que encontrar el pen�ltimo nodo realmente, por eso usamos "lastNode->next->next != nullptr"
	// encontrar el �ltimo elemento de la lista y luego quitarlo.
	Node<T>* penultimateNode = first;
	while (	penultimateNode->next->next != nullptr)
	{
		penultimateNode = penultimateNode->next;
	}

	// guardamos la data del �ltimo nodo
	T data = penultimateNode->next->data;

	// ya que tenemos la data borramos al �ltimo nodo
	delete penultimateNode->next;
	penultimateNode->next = nullptr;
	count--;

	return data;
}

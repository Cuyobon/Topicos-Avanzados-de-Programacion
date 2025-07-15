
#pragma once

#include <iostream>
using namespace std;


template <typename T>
class DoubleLinkedList
{
private:
	template <typename T>
	class Node
	{
	public:
		Node()
		{
			// Se podría lograr implementar sin tenerlo aquí, y (en teoría) podrías ganar 
			// una cantidad pequeña pequeñísima de performance, pero como esto es didáctico, 
			// les va a ayudar a evitar unos cuantos problemillas.
			prev = nullptr;
			next = nullptr;
		}

		Node(T value)
		{
			data = value;
			// Se podría lograr implementar sin tenerlo aquí, y (en teoría) podrías ganar 
			// una cantidad pequeña pequeñísima de performance, pero como esto es didáctico, 
			// les va a ayudar a evitar unos cuantos problemillas.
			prev = nullptr;
			next = nullptr;
		}

		T data;
		Node<T>* next;
		Node<T>* prev;
	};


private:
	Node<T>* first; // un puntero al primer nodo de nuestra lista ligada.
	Node<T>* last; // aquí nos quedamos para el jueves 19.
	int count; // número de elementos en esta lista ligada.

public:
	DoubleLinkedList()
	{
		count = 0;
		first = nullptr;
		last = nullptr;
	}

	int GetCount() { return count; };

	DoubleLinkedList::Node<T>& Find(T value);

	DoubleLinkedList::Node<T>& FindV2(T value);

	DoubleLinkedList::Node<T>& Successor(DoubleLinkedList::Node<T>* node)
	{
		return node->next;
	}

	DoubleLinkedList::Node<T>& Predecessor(DoubleLinkedList::Node<T>* node)
	{
		return node->prev;
	}


	// Añade un nuevo nodo al final de la lista.
	void PushBack(T value);

	// Quita el nodo del final de la lista y devuelve su valor.
	T PopBack();

	// Un nodo con el valor valueToInsert se insertará como el Next de previousNode.
	void Insert(T valueToInsert, Node<T>* previousNode);

	void Remove(T valueToRemove);

	// void Remove(Node<T>* nodeToRemove);

	int operationCounter;
};

template<typename T>
void DoubleLinkedList<T>::Remove(T valueToRemove)
{
	// empieza en el primer de la lista
	Node<T>* currentNode = first; // usamos una variable auxiliar para no tocar la referencia al first.

	// hacemos un ciclo para checar todos los nodos, hasta que ya no haya nodo siguiente.
	while (currentNode != nullptr)
	{
		// checa si la data del nodo actual es igual al valor a encontrarse (valueToRemove)
		if (currentNode->data == valueToRemove)
		{
			// si solo hay un nodo en la lista, pues borramos y ya.
			if (count == 1)
			{
				first = nullptr;
				last = nullptr;
			}
			else if (currentNode->prev == nullptr) 	// checar el caso especial en que currentNode es el primer nodo.
			{
				// entonces sí es el primer nodo de la lista.
				// hacemos que el next de current, su previous apunte a nullptr
				currentNode->next->prev = nullptr;
				// hacemos que el next de current sea el first de la lista
				first = currentNode->next;
			}
			else if (currentNode->next == nullptr) // checar el caso especial en que currentNode es el último nodo.
			{
				// hacemos que prev de current, su next apunte a null
				currentNode->prev->next = nullptr;
				last = currentNode->prev;
			}
			else // si no es ninguno de los tres casos especiales anteriores
			{
				// El nodo anterior de currentNode su next debe apuntar a donde apunta currentNode-next
				// el nodo anterior de currentNode es currentNode->prev
				// el next de currentNode->prev sería currentNode->prev->next
				currentNode->prev->next = currentNode->next;
				// ahora hacemos lo mismo pero en la otra dirección
				// el prev de currentNode->next sería currentNode->next->prev debe apuntar a donde apunta currentNode-prev
				currentNode->next->prev = currentNode->prev;
			}

			delete currentNode;
			count--;
			return;
		}
		else
		{
			// si no lo tiene, continuamos al nodo que le sigue a currentNode.
			currentNode = currentNode->next;
		}
	}

}

template<typename T>
DoubleLinkedList<T>::Node<T>& DoubleLinkedList<T>::Find(T value)
{
	// empieza en el primer de la lista
	Node<T>* currentNode = first; // usamos una variable auxiliar para no tocar la referencia al first.

	// hacemos un ciclo para checar todos los nodos, hasta que ya no haya nodo siguiente.
	while (currentNode != nullptr)
	{
		// checa si la data del nodo actual es igual al valor a encontrarse (value)
		if (currentNode->data == value)
		{
			// NOTA: Estas dos líneas son equivalentes, pero la flecha -> es más cómoda y práctica y estándar.
			// currentNode->data
			// (*currentNode).data

			// si sí lo tiene, regresamos dicho nodo y nos salimos de la función.
			return currentNode;
		}
		else
		{
			// si no lo tiene, continuamos al nodo que le sigue a currentNode.
			currentNode = currentNode->next;
		}
	}

	// si llegamos a esta parte del código, es porque no encontramos ningún nodo con el valor value.
	// entonces regresamos nullptr porque no existe dicho nodo.
	return nullptr;
}


template<typename T>
DoubleLinkedList<T>::Node<T>& DoubleLinkedList<T>::FindV2(T value)
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

	// si llegamos a esta parte del código, es porque no encontramos ningún nodo con el valor value.
	// entonces regresamos nullptr porque no existe dicho nodo.
	return nullptr;
}

template<typename T>
void DoubleLinkedList<T>::Insert(T valueToInsert, DoubleLinkedList<T>::Node<T>* previousNode)
{
	// Un nodo con el valor valueToInsert se insertará como el Next de previousNode.

	// Nuevo nodo que será el nuevo Next de previousNode 
	Node<T>* newNode = new Node<T>(valueToInsert); // usamos una variable auxiliar para no tocar la referencia al first.

	// NOTA, es importante primero hacer la que va de newNode a previousNode->next y después la de previousNode->next a newNode, 
	// porque si no newNode termina teniéndose como su propio next, lo cual es un grave error.

	// Hacemos la conexión desde newNode hacia el next de previousNode
	newNode->next = previousNode->next;

	// Hacemos la conexión desde previousNode hacia newNode como su next
	previousNode->next = newNode;

	// aumentar el tamaño de la lista.
	count++;
}

// Añade un nuevo nodo al final de la lista.
template<typename T>
void DoubleLinkedList<T>::PushBack(T value)
{
	// Creamos un nuevo nodo con el valor value como su data.
	Node<T>* newNode = new Node<T>(value);
	newNode->next = nullptr;


	// tenemos que checar que no esté vacía la lista
	if (last == nullptr)
	{
		newNode->prev = nullptr;
		// si se cumple esto, entonces la lista está vacía y newNode se vuelve el único elemento
		// por tanto, él es first y también es last
		first = newNode;
		last = newNode;
		count++;
		return; // nos salimos porque ya hicimos todo lo necesario.
	}

	// como ya tenemos el puntero last, que apunta al último elemento de la lista, pues simplemente
	// le decimos a last que su next es igual a newNode
	last->next = newNode;
	newNode->prev = last;
	// IMPORTANTE: Actualizar que ahora el puntero last apunta a newNode porque ahora él es el verdadero último de la lista.
	last = newNode; 

	count++; // como metimos un nuevo elemento, aumentamos el contador de elementos.
}

template<typename T>
T DoubleLinkedList<T>::PopBack()
{
	// si no hay ningún elemento.
	if (last == nullptr || count == 0 ) // lo dejo con todas las condiciones que significan lo mismo
	{
		cout << "Cuidado, estás haciendo pop back cuando ya no hay elementos en esta lista ligada";
		return {}; // {} es un elemento de tipo T con su valor por defecto, sin importar de qué tipo sea T.
	}

	// si solo queda un elemento, entonces lo manejamos de esta manera porque vamos a dejar la lista vacía
	if (count == 1)
	{
		// obtenemos su data para retornarla.
		T data = first->data;
		// lo borramos y ponemos first como nullptr
		delete first;
		first = nullptr;
		last = nullptr; // este no le hacemos delete porque debe apuntar a la misma memoria que first
		count--;
		// regresamos la data
		return data;
	}

	// ya sabemos que el último nodo es last
	// y sabemos que el penúltimo nodo va a ser el last->prev
	Node<T>* penultimateNode = last->prev;

	// guardamos la data del último nodo
	T data = penultimateNode->next->data;

	// ya que tenemos la data borramos al último nodo
	delete last;
	penultimateNode->next = nullptr;
	last = penultimateNode;
	count--;

	return data;
}


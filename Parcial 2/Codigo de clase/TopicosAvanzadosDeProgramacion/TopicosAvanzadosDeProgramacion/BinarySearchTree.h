#pragma once

#include <iostream>
using namespace std;

#include <cmath> // Required for std::log

double log_base_n(double x, double base);


int MinimaAlturaDeArbol(int numeroDeNodos, int maximoDeHijosPorNodo);

template <typename T>
class BinarySearchTree
{
	template <typename T>
	class TreeNode
	{
	public:
		TreeNode()
		{
			parent = leftChild = rightChild = nullptr;
			data = {};
		}

		TreeNode(T data)
		{
			parent = leftChild = rightChild = nullptr;
			// this se refiere a exactamente el objeto que está mandando a llamar la función. 
			this->data = data;
		}

		T data;
		// el padre de este nodo dentro del árbol. 
		// En otras palabras, this == parent.leftChild || this == parent.rightChild
		TreeNode<T>* parent;

		// vector<TreeNode*> children; // si quisiéramos que tuviera la posibilidad de tener más de dos hijos cada nodo.
		TreeNode<T>* leftChild;
		TreeNode<T>* rightChild;
	};

public:
	BinarySearchTree()
	{
		root = nullptr;
		count = 0;
	}

	void AddWithAddRecursive(T value)
	{
		// primero checamos si root es nullptr. 
		if (root == nullptr)
		{
			// si sí es nullptr, quiere decir que value es el primer valor en entrar, y por tanto se va a 
			// convertir en el nodo root.
			root = new TreeNode<T>(value);
			count++;
			return; // nos salimos de la función.
		}

		TreeNode<T>* currentNode = root;

		AddRecursive(value, currentNode);
	}

	void InsertarNode(TreeNode<T>* currentNode, bool isLeftChild, T value)
	{
		TreeNode<T>* newNode = new TreeNode<T>(value);
		newNode->parent = currentNode;
		if (isLeftChild)
			currentNode->leftChild = newNode;
		else
			currentNode->rightChild = newNode;
		count++;

	}

	void AddRecursive(T value, TreeNode<T>* currentNode)
	{

		// si value es mayor que el data de currentNode
		if (value > currentNode->data)
		{
			// entonces nos vamos a su derecha
			// checamos si ese hijo de la derecha es nullptr.
			if (currentNode->rightChild == nullptr)
			{
				// si sí es nullptr, entonces ahora value va a ser ese hijo.
				InsertarNode(currentNode, false, value);
				return;
			}
			else
			{
				// aquí hacemos la recursión
				return AddRecursive(value, currentNode->rightChild);
			}
		}
		else if (value < currentNode->data) // TODO: aquí hay una trampa que veremos pronto.
		{
			// entonces nos vamos a su izquierda.
			// checamos si ese hijo de la izquierda es nullptr.
			if (currentNode->leftChild == nullptr)
			{
				// si sí es nullptr, entonces ahora value va a ser ese hijo.
				InsertarNode(currentNode, true, value);
				return;
			}
			else
			{
				// aquí hacemos la recursión
				return AddRecursive(value, currentNode->leftChild);
			}
		}

	}

	void Add(T value)
	{
		// primero checamos si root es nullptr. 
		if (root == nullptr)
		{
			// si sí es nullptr, quiere decir que value es el primer valor en entrar, y por tanto se va a 
			// convertir en el nodo root.
			root = new TreeNode<T>(value);
			count++;
			return; // nos salimos de la función.
		}

		TreeNode<T>* currentNode = root;

		// necesitamos un ciclo que dure hasta que lleguemos a un nodo nullptr
		while (currentNode != nullptr) // mientras que nuestro nodo actual siga siendo válido, continua el ciclo.
		{
			// el ciclo consiste en el proceso de navegar a través de hijos izquierdos y derechos
			
			// si value es mayor que el data de currentNode
			if (value > currentNode->data)
			{
				// entonces nos vamos a su derecha
				// checamos si ese hijo de la derecha es nullptr.
				if (currentNode->rightChild == nullptr)
				{
					// si sí es nullptr, entonces ahora value va a ser ese hijo.
					InsertarNode(currentNode, false, value);
					return;
				}
				else
				{
					currentNode = currentNode->rightChild;
				}
			}
			else if (value < currentNode->data) // TODO: aquí hay una trampa que veremos pronto.
			{
				// entonces nos vamos a su izquierda.
				// checamos si ese hijo de la izquierda es nullptr.
				if (currentNode->leftChild == nullptr)
				{
					// si sí es nullptr, entonces ahora value va a ser ese hijo.
					InsertarNode(currentNode, true, value);
					return;
				}
				else
				{
					currentNode = currentNode->leftChild;
				}
			}
		}




	}

	void InOrderWithRecursive()
	{ 
		InOrderRecursive(root);
	}


	int MinimaAltura()
	{
		// le dice que tiene N nodos, y que es un árbol de base 2 (porque es binario en este caso).
		return MinimaAlturaDeArbol(count, 2);
	}



	// Es el nodo raíz desde el cual el árbol es capaz de llegar a cualquier otro nodo en el árbol.
	TreeNode<T>* root; 

	// cuántos nodos en total tiene el árbol.
	int count;

	// cuántos niveles de profundidad tiene el árbol.
	// int depth;

private:
	void InOrderRecursive(TreeNode<T>* node)
	{
		if (node != nullptr)
		{
			// Mandamos recursivamente a izquierda
			InOrderRecursive(node->leftChild);
			// Luego se visita (en este caso, se imprime su valor)
			cout << node->data << endl;
			// Mandamos recursivamente a derecha
			InOrderRecursive(node->rightChild);
		}
	}

	void PreOrderRecursive(TreeNode<T>* node)
	{
		if (node != nullptr)
		{
			// Luego se visita (en este caso, se imprime su valor)
			cout << node->data << endl;
			// Mandamos recursivamente a izquierda
			PreOrderRecursive(node->leftChild);
			// Mandamos recursivamente a derecha
			PreOrderRecursive(node->rightChild);
		}
	}

	void PostOrderRecursive(TreeNode<T>* node)
	{
		if (node != nullptr)
		{
			// Mandamos recursivamente a izquierda
			PostOrderRecursive(node->leftChild);
			// Mandamos recursivamente a derecha
			PostOrderRecursive(node->rightChild);
			// Luego se visita (en este caso, se imprime su valor)
			cout << node->data << endl;
		}
	}


};


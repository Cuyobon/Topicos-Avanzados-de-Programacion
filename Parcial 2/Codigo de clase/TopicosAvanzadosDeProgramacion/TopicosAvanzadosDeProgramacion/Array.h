#pragma once

// if not defined

#ifndef ARRAY_H
#define ARRAY_H


// tarea de Juanito Perez y Pepe Toño

#include <iostream>
using namespace std;

template <typename T>
void ImprimirArray(T array[], int numElements )
{
	cout << "los elementos son: ";
	for (int i = 0; i < numElements; i++)
	{
		cout << array[i] << ", ";
	}
	cout << endl;
}

template <typename T1, typename T2>
T1 Suma(T1 a, T2 b)
{

}

template <typename T1, typename T2, typename T3>
T1 Suma(T1 a, T2 b, T3 c)
{
	return {};
}



template <typename T>
class TArray
{
public:
	TArray(int numElements)
	{
		data = new T[numElements];
		this->numElements = numElements;
	}

	void InicializarACero()
	{
		for (int i = 0; i < numElements; i++)
		{
			data[i] = {};
		}
	}

	void ImprimirElementos()
	{
		cout << "los elementos son: ";
		for (int i = 0; i < numElements; i++)
		{
			cout << data[i] << ", ";
		}
		cout << endl;
	}

	~TArray()
	{
		// liberamos el array de memoria dinámica pedido
		delete[] data;
	}

	T* data;
	int numElements;


};



class Array
{
public:
	Array(int numElements)
	{
		data = new int[numElements];
		this->numElements = numElements;
	}

	void InicializarACero()
	{
		for (int i = 0; i < numElements; i++)
		{
			data[i] = 0;
		}
	}
	
	void ImprimirElementos()
	{
		cout << "los elementos son: ";
		for (int i = 0; i < numElements; i++)
		{
			cout << data[i] << ", ";
		}
		cout << endl;
	}

	~Array()
	{
		// liberamos el array de memoria dinámica pedido
		delete[] data;
	}
	
	int* data;
	int numElements;


};


class FloatArray
{
public:
	FloatArray(int numElements)
	{
		data = new float[numElements];
		this->numElements = numElements;
	}

	void InicializarACero()
	{
		for (int i = 0; i < numElements; i++)
		{
			data[i] = 0;
		}
	}

	void ImprimirElementos()
	{
		cout << "los elementos son: ";
		for (int i = 0; i < numElements; i++)
		{
			cout << data[i] << ", ";
		}
		cout << endl;
	}

	~FloatArray()
	{
		// liberamos el array de memoria dinámica pedido
		delete[] data;
	}

	float* data;
	int numElements;


};


class BoolArray
{
public:
	BoolArray(int numElements)
	{
		data = new bool[numElements];
		this->numElements = numElements;
	}

	void InicializarACero()
	{
		for (int i = 0; i < numElements; i++)
		{
			data[i] = 0;
		}
	}

	void ImprimirElementos()
	{
		cout << "los elementos son: ";
		for (int i = 0; i < numElements; i++)
		{
			cout << data[i] << ", ";
		}
		cout << endl;
	}

	~BoolArray()
	{
		// liberamos el array de memoria dinámica pedido
		delete[] data;
	}

	bool* data;
	int numElements;


};



class TArrayChar
{
public:
	TArrayChar(int numElements)
	{
		data = new char[numElements];
		this->numElements = numElements;
	}

	void InicializarACero()
	{
		for (int i = 0; i < numElements; i++)
		{
			data[i] = {};
		}
	}

	void ImprimirElementos()
	{
		cout << "los elementos son: ";
		for (int i = 0; i < numElements; i++)
		{
			cout << data[i] << ", ";
		}
		cout << endl;
	}

	~TArrayChar()
	{
		// liberamos el array de memoria dinámica pedido
		delete[] data;
	}

	char* data;
	int numElements;


};

class TArrayClaseEjemplo
{
public:
	TArrayClaseEjemplo(int numElements)
	{
		data = new ClaseEjemplo[numElements];
		this->numElements = numElements;
	}

	void InicializarACero()
	{
		for (int i = 0; i < numElements; i++)
		{
			data[i] = {};
		}
	}

	void ImprimirElementos()
	{
		cout << "los elementos son: ";
		for (int i = 0; i < numElements; i++)
		{
			cout << data[i] << ", ";
		}
		cout << endl;
	}

	~TArrayClaseEjemplo()
	{
		// liberamos el array de memoria dinámica pedido
		delete[] data;
	}

	ClaseEjemplo* data;
	int numElements;


};

#endif

// end if (terminar el if). En este caso se refiere al if del #ifndef ARRAY_H
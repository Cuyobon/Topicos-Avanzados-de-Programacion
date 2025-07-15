#pragma once

#define DYNAMIC_ARRAY_DEFAULT_SIZE 4


template <typename T>
class DynamicArray
{
public:
	// por defecto lo inicializa con DYNAMIC_ARRAY_DEFAULT_SIZE espacios.
	DynamicArray()
	{
		capacity = DYNAMIC_ARRAY_DEFAULT_SIZE;
		data = new T[capacity];
		count = 0;
		copyCounter = 0;
	}

	DynamicArray(int size)
	{
		capacity = size;
		data = new T[capacity];
		count = 0;
		copyCounter = 0;
	}

	// cuando se le da delete a una variable de una clase o estructura, eso manda a llamar
	// el destructor de dicha clase/estructura, ejecuta el código de dicho destructor,
	// y una vez que sale de esas llaves es cuando realmente se borra esa variable.
	~DynamicArray()
	{
		// cuando este objeto se destruye, libera la memoria dinámica que pedimos en el constructor.
		delete[] data; 
	} // acá es cuando realmente se borra esta variable.

	void ImprimirElementos()
	{
		cout << "los elementos son: ";
		for (int i = 0; i < count; i++)
		{
			cout << data[i] << ", ";
		}
		cout << endl;
	}

	// Mete al parámetro element en la posición última ocupada de este DynamicArray.
	void Append(T element)
	{
		// antes de meter el elemento nuevo, tenemos que checar que sí quepa dentro de data.
		// si count es mayor o igual que capacity, quiere decir que no nos cabe, y entonces capacity tiene que aumentar.
		if (count >= capacity)
		{
			cout << "count es: " << count << " capacity es: " << capacity << " agrandando al doble capacity" << endl;

			// entonces tenemos que hacer el resize. Es decir, pedir más memoria (el doble de la capacidad actual), 
			capacity = capacity * 2;
			// capacity++;
			T* auxData = new T[capacity];
			// copiar cada uno los elementos de este array al nuevo array,
			for (int i = 0; i < count; i++)
			{
				auxData[i] = data[i];
				copyCounter++;
			}

			cout << "total de copias hasta el momento: " << copyCounter << endl;

			// y finalmente liberamos la memoria a la que apunta el viejo array.
			delete[] data;
			// y asignamos que ahora apunte al nuevo array.
			data = auxData;
		}

		// lo pones en la posición que Count te diga.
		data[count] = element;
		count++; // aumenta el contador de cuántos elementos tienes guardados.
	}

	// este es para no darle acceso directo hacia data a otras clases o partes de código que no tienen por qué tocarlo.
	T get(int index)
	{
		// lo que se va a intentar ejecutar, pero que si arroja (throw) alguna excepción, se sale
		// de estas llaves y se va al catch de abajo.
		try
		{

			if (index >= count)
			{
				throw std::out_of_range("Cuidado, index está fuera de rango para este dynamicArray porque es demasiado grande");
				// este return ni siquiera se ejecuta porque el throw de arriba te saca de las llaves 
				// del try y te manda a las llaves del catch.
				return {};
			}


			if (index < 0)
			{
				throw std::out_of_range("Cuidado, index está fuera de rango porque es negativo para este dynamicArray");
				// este return ni siquiera se ejecuta porque el throw de arriba te saca de las llaves 
				// del try y te manda a las llaves del catch.
				return {};
			}

			return data[index];
		}
		catch (const std::exception& e)
		{
			// entre estas llaves del catch es qué va a hacer tu programa según el caso de excepción que sucedió.
			// En este caso, solo queremos imprimir qué salió mal.
			cout << e.what() << endl;
		}

		// este return de valor por defecto es porque salió algo mal, si todo hubiera salido bien,
		// habríamos ejecutado el de: return data[index];
		return {};
	}

	//
	/*
	try
	{
		myDynamicArray.get(1);
	}
	catch(exception e)
	{
		cout << e.message << endl;
	}
	
	
	*/


private:
	// Un puntero al array donde guardan los datos
	T* data;

	// Cuántos elementos hay guardados actualmente en este DynamicArray
	int count;

	// Cuántos elementos le caben a este DynamicArray.
	int capacity;

	int copyCounter;
};


 /*
-----------------------------------------------
PUNTO 3 - Clase: LStack<T>

Esta clase es una versión de la pila (stack) que hicimos en clase, 
pero en lugar de usar un arreglo fijo, aquí se usa una `forward_list` 
de la STL (una lista enlazada simple).

Cambios y detalles:
- Use `std::forward_list<T>` para guardar los datos.
- Las funciones `Push`, `Pop` y `Peak` están hechas para que 
  trabajen en tiempo constante.
- Como forward_list no tiene función .size(), se agregó 
  una variable count para contar cuántos elementos hay.
- El comportamiento general es el mismo que la pila de clase, 
  solo que adaptado para que use lista en lugar de arreglo
-----------------------------------------------
*/


#pragma once

#include <forward_list>
#include <stdexcept>

template <typename T>
class LStack
{
private:
    std::forward_list<T> data;
    int count;

public:
    LStack() : count(0) {}

    // Push: Insertar al frente (O(1))
    void Push(const T& value)
    {
        data.push_front(value);
        ++count;
    }

    // Pop: Quitar el primero (O(1))
    T Pop()
    {
        if (data.empty())
            throw std::out_of_range("Stack is empty");

        T top = data.front();
        data.pop_front();
        --count;
        return top;
    }

    // Peak: Ver el valor al tope sin removerlo (O(1))
    T Peak() const
    {
        if (data.empty())
            throw std::out_of_range("Stack is empty");

        return data.front();
    }

    // Count: Número de elementos en la pila
    int Count() const
    {
        return count;
    }
};

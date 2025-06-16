#include <iostream>
using namespace std;

int main() {
    // 3) Declarar un puntero a flotante y asignarle el valor nullptr.
    float* ptr = nullptr;

    // 3.1) Pedir memoria dinámica para dicho puntero, y que dentro tenga el valor 7.77.
    ptr = new float(7.77);

    // 3.2) Declarar una variable de tipo flotante con un valor de 6.66.
    float valor = 6.66;

    // 3.3) Hacer que ahora el puntero a flotante del punto 4) apunte a la dirección de memoria de la variable del punto 4.2).
    ptr = &valor;

    // 3.4) Imprimir en pantalla: "Cuidado, acabas de causar un memory leak!".
    cout << "Cuidado, acabas de causar un memory leak!" << endl;

    // 3.5) Imprimir explicación
    cout << "Esto es un memory leak porque habíamos asignado memoria dinámica a 'ptr', "
         << "pero luego lo hicimos apuntar a otra variable sin liberar primero esa memoria. "
         << "Para evitarlo, debimos usar 'delete ptr;' antes de reasignarlo." << endl;

    // 3.6) Pedir memoria dinámica (otra vez) para el puntero de 4) y asignarle el valor 1984.
    ptr = new float(1984);

    // 3.7) Hacer un nuevo puntero a float y hacer que apunte a la misma dirección que el puntero del punto 4.6).
    float* otroPtr = ptr;

    // 3.8) Liberar dicha memoria dinámica, luego asignar nullptr
    delete ptr;
    ptr = nullptr;

    // 3.9) Checar si ese puntero es igual a nullptr
    if (ptr == nullptr)
        cout << "La variable es igual a nullptr." << endl;

    // 3.10) Checar si ese puntero es igual a NULL
    if (ptr == NULL)
        cout << "La variable es igual a NULL." << endl;

    // 3.11) Checar si el puntero de 4.7) es nullptr o NULL
    if (otroPtr == nullptr || otroPtr == NULL) {
        cout << "La variable 'otroPtr' es nullptr o NULL." << endl;
    } else {
        cout << "La variable 'otroPtr' no es nullptr ni NULL. "
             << "Cuidado: apunta a memoria ya liberada (dangling pointer)!" << endl;
    }

    return 0;
}

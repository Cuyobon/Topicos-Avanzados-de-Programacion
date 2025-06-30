#include <iostream>
using namespace std;

// 1.1 y 1.2: Función que recibe un array de booleanos y su tamaño
void modificarArray(bool arr[], int tam) {
    for (int i = 0; i < tam; i++) {
        arr[i] = (i % 2 != 0); // índices pares = false, impares = true
    }
}

// 1.4 a 1.8: Sobrecarga que recibe un array de enteros y usa punteros
void modificarArray(int* arr, int tam) {
    int* ptr = arr; // 1.7: Variable auxiliar que apunta al comienzo del array

    for (int i = 0; i < tam; i++) {
        *(ptr + i) = *(ptr + i) % 2; // 1.5 y 1.6: sin usar [], con punteros
        // 1.8: Imprimir dirección y valor
        cout << "Direccion: " << (ptr + i) << " -> Valor: " << *(ptr + i) << endl;
    }
}

int main() {
    // 1.0: Array de 5 booleanos
    bool arregloBool[5];

    // Llamamos la función para modificar arregloBool
    modificarArray(arregloBool, 5);

    // Mostrar resultado
    cout << "Array de booleanos:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Indice " << i << ": " << boolalpha << arregloBool[i] << endl;
    }

    // 1.3: Array de 10 enteros de 0 a 9
    int arregloInt[10];
    for (int i = 0; i < 10; i++) {
        arregloInt[i] = i;
    }

    // Llamamos a la versión sobrecargada para modificar arregloInt
    cout << "\nArray de enteros tras modificar con %2 y mostrar direcciones:\n";
    modificarArray(arregloInt, 10);

    return 0;
}

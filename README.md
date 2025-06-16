# 📚 Ejercicios de Programación en C++: Arrays, Structs y Memoria Dinámica

Este repositorio contiene una serie de ejercicios prácticos en C++ enfocados en el uso de arrays, estructuras (`structs`), paso de parámetros por referencia, sobrecarga de funciones y manejo de memoria dinámica.

---

## ✅ Temas cubiertos

### 1. Arrays y Funciones

- **Definición y modificación de arrays**: Se creó un array de booleanos y otro de enteros, modificando su contenido a través de funciones.
- **Sobrecarga de funciones**: Se usó el mismo nombre de función (`modificarArray`) para trabajar tanto con arrays de booleanos como de enteros.
- **Aritmética de punteros**: En lugar de usar corchetes (`[]`) para acceder a los elementos del array de enteros, se utilizaron punteros para desplazarse por la memoria, mostrando además las direcciones de cada elemento.

### 2. Estructuras (Struct) y Paso por Referencia

- **Struct `Rect`**: Representa un rectángulo 2D con coordenadas `x`, `y`, `alto` y `ancho`.
- **Constructores**:
  - Por defecto (todos los valores en 0).
  - Con parámetros para inicializar todos los campos.
  - Con sólo `alto` y `ancho`, estableciendo `x` e `y` en 0.
- **Función por referencia**:
  - Recibe un `Rect`, calcula su punto final (`x + ancho`, `y + alto`).
  - Retorna `false` si alguno de los valores es negativo.
- **Función `CheckOverlap`**:
  - Determina si dos rectángulos se traslapan en el espacio.
  - Incluye ejemplos para validar la lógica con distintos casos.

### 3. Manejo de Memoria Dinámica

- **`new` y `delete`**: Uso de memoria dinámica para asignar valores a punteros.
- **Memory leak**:
  - Se demuestra qué ocurre cuando se pierde la referencia a memoria dinámica sin liberar (fuga de memoria).
- **`nullptr` y `NULL`**:
  - Verificación del estado de punteros antes y después de liberar memoria.
- **Puntero colgante (`dangling pointer`)**:
  - Se muestra cómo un puntero puede seguir apuntando a memoria liberada, lo cual es peligroso y debe evitarse.

---

## 🧠 Conclusión

Este proyecto pone en práctica conceptos fundamentales de C++ relacionados con la gestión de memoria, estructuras de datos, paso por referencia y punteros. Es una base importante para entender cómo C++ permite control total sobre el manejo de datos en memoria.

---

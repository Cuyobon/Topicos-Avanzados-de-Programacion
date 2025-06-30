// Utils.h
#ifndef UTILS_H
#define UTILS_H

#include <iostream>

template<typename T>
void PrintArray(T* array, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

#endif

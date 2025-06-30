// DynamicArray.tpp

template<typename T>
DynamicArray<T>::DynamicArray()
    : data(nullptr), capacity(0), count(0)
#if COUNT_DYNAMIC_ARRAY_COPIES != 0
    , copyCounter(0)
#endif
{}

template<typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] data;
}

template<typename T>
void DynamicArray<T>::Append(const T& value) {
    if (count == capacity) {
        int newCapacity = (capacity == 0) ? 1 : capacity * 2;
        T* newData = new T[newCapacity];
        for (int i = 0; i < count; i++) {
            newData[i] = data[i];
#if COUNT_DYNAMIC_ARRAY_COPIES != 0
            copyCounter++;
#endif
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
    data[count++] = value;
}

template<typename T>
void DynamicArray<T>::push_back(const T& value) {
    Append(value);
}

template<typename T>
void DynamicArray<T>::pop_back() {
    if (count > 0) {
        count--;
    }
}

template<typename T>
void DynamicArray<T>::shrink_to_fit() {
    if (capacity > count) {
        T* newData = new T[count];
        for (int i = 0; i < count; i++) {
            newData[i] = data[i];
#if COUNT_DYNAMIC_ARRAY_COPIES != 0
            copyCounter++;
#endif
        }
        delete[] data;
        data = newData;
        capacity = count;
    }
}

template<typename T>
T& DynamicArray<T>::operator[](int index) {
    return data[index];
}

#if COUNT_DYNAMIC_ARRAY_COPIES != 0
template<typename T>
int DynamicArray<T>::GetCopyCount() const {
    return copyCounter;
}
#endif

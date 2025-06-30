#include "DynamicArray.h"
#include "Utils.h"

int main() {
    DynamicArray<int> arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);

    PrintArray(&arr[0], 3);

#if COUNT_DYNAMIC_ARRAY_COPIES != 0
    std::cout << "Copy counter: " << arr.GetCopyCount() << std::endl;
#endif

    arr.pop_back();
    arr.shrink_to_fit();

    PrintArray(&arr[0], 2);
}

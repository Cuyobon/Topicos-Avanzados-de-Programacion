#include "LinkedList.h"

int main() {
    LinkedList<int> list;
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);

    list.Print(); // 30 20 10

    list.pop_front();
    list.Print(); // 20 10

    list.Clear();
}

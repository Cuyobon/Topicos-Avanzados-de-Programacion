// LinkedList.tpp

template<typename T>
LinkedList<T>::LinkedList()
    : head(nullptr)
{}

// Llamamos a Clear aqu� para liberar memoria autom�ticamente
// cuando la lista deja de existir
template<typename T>
LinkedList<T>::~LinkedList() {
    Clear();
}

template<typename T>
void LinkedList<T>::push_front(const T& value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

template<typename T>
void LinkedList<T>::pop_front() {
    if (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename T>
void LinkedList<T>::Print() {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Implementaci�n de la funci�n Clear,
// se encarga de liberar toda la memoria de los nodos de la lista
template<typename T>
void LinkedList<T>::Clear() {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

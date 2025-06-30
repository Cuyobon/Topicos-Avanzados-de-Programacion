// LinkedList.tpp

template<typename T>
LinkedList<T>::LinkedList()
    : head(nullptr) {}

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

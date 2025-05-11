

template<typename T>
inline LinkedList<T>::LinkedList(std::initializer_list<T> init) {
    for (unsigned long long i = 0; i < init.size(); ++i) {
        this->AddLast(init.begin()[i]);
    }
}

template<typename T>
inline LinkedList<T>::~LinkedList() {
    auto current = this->_head;
    while (current != nullptr) {
        auto next = current->next;
        delete current;
        current = next;
    }

    this->_head = nullptr;
    this->_tail = nullptr;
    this->_size = 0;
}

template<typename T>
inline void LinkedList<T>::AddFirst(T object) {
    auto new_node = new DoublyNode<T>;
    new_node->data = object;
    new_node->next = this->_head;
    this->_head = new_node;
    ++this->_size;
}

template<typename T>
inline void LinkedList<T>::AddLast(T object) {
    auto new_node = new DoublyNode<T>;
    new_node->data = object;
    new_node->prev = this->_tail;
    if (this->_tail) this->_tail->next = new_node;
    else this->_head = new_node;
    this->_tail = new_node;
    ++this->_size;
}

template<typename T>
inline bool LinkedList<T>::RemoveFirst() {
    if (this->_head == nullptr) return false;
    delete this->_head;
    this->_head = this->_head->next;
    this->_head->prev = nullptr;
    --this->_size;
    return true;
}

template<typename T>
inline bool LinkedList<T>::RemoveLast() {
    if (this->_tail == nullptr) return false;
    delete this->_tail;
    this->_tail = this->_tail->prev;
    this->_tail->next = nullptr;
    --this->_size;
    return true;
}

template<typename T>
inline bool LinkedList<T>::Remove(T object) {
    if (this->_size < 1 ) return false;
    if (this->_head == nullptr) throw std::out_of_range("LinkedList::Remove: nullptr head bug");
    auto current_node = this->_head;
    while (current_node->data != object) {
        current_node = current_node->next;
        if (current_node == nullptr) return false;
    }
    if (current_node->next == nullptr && current_node->prev == nullptr) {
        delete current_node;
        this->_head = nullptr;
        this->_tail = nullptr;
        --this->_size;
        return true;
    }
    auto next_node = current_node->next;
    auto prev_node = current_node->prev;
    delete current_node;
    --this->_size;

    if (next_node != nullptr && prev_node != nullptr) {
        prev_node->next = next_node;
        next_node->prev = prev_node;
    }
    else if (next_node == nullptr) this->_tail = prev_node;
    else this->_head = next_node;
    return true;
}

template<typename T>
inline bool LinkedList<T>::Remove(DoublyNode<T> *node) {
    if (node == nullptr) return false;
    if (node->next == nullptr && node->prev == nullptr) return false;
    if (node->next == nullptr) this->RemoveFirst();
    else if (node->prev == nullptr) this->RemoveLast();
    else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    return true;
}

template<typename T>
inline long long LinkedList<T>::Find(T object) {
    auto current_node = this->_head;
    if (current_node == nullptr) return -1;
    for (unsigned int i = 0; i < this->_size; ++i) {
        if ((*this)[i] == object) return i;
    }
    return -1;
}

template<typename T>
inline T LinkedList<T>::First() const {
    if (this->_head == nullptr) throw std::out_of_range("LinkedList::First: First is nullptr");
    return this->_head->data;
}

template<typename T>
inline T LinkedList<T>::Last() const {
    if (this->_tail == nullptr) throw std::out_of_range("LinkedList::Last: Last is nullptr");
    return this->_tail->data;
}

template<typename T>
inline void LinkedList<T>::Swap(const unsigned long long index1, const unsigned long long index2) {
    if (index1 < 0 || index2 < 0)throw std::out_of_range("LinkedList::Swap: index is negative");
    if (this->Size() <2) throw std::out_of_range("LinkedList::Swap: size is less than 2");
    if (index1 == index2) return;
    if (index1>this->Size()-1 || index2>this->Size()-1) throw std::out_of_range("LinkedList::Swap: index is out of range");

    DoublyNode<T>* first = this->_head;
    DoublyNode<T>* second = this->_head;

    for (unsigned long long i = 0; i < index1; ++i) first = first->next;
    for (unsigned long long i = 0; i < index2; ++i) second = second->next;

    T temp = first->data;
    first->data = second->data;
    second->data = temp;
}


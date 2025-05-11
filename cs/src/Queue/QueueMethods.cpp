

template<typename T>
inline Queue<T>::Queue(const std::initializer_list<T> init) {
    for (auto i = 0; i < init.size(); ++i) this->Enqueue(init.begin()[i]);
}


template <typename T>
inline void Queue<T>::Enqueue(T item) {
    auto target_node = new SinglyNode<T>;
    target_node->data = item;
    target_node->next = nullptr;

    if (this->head == nullptr) this->head = target_node;

    else if (this->tail == nullptr) {
        this->tail = target_node;
        this->head->next = this->tail;
    }
    else {
        this->tail->next = target_node;
        this->tail = target_node;
    }
    ++this->size;
}

template<typename T>
inline T Queue<T>::Dequeue() {
    if (this->head == nullptr) throw std::out_of_range("Queue::Dequeue : queue is empty");
    auto result = this->head->data;
    auto old_head = this->head;
    this->head = this->head->next;
    delete old_head;
    --this->size;
    return result;
}


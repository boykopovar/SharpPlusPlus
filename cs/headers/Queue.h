#ifndef QUEUE_H
#define QUEUE_H

#include"structs.h"


template <typename T>
class Queue {
public:
    Queue() = default;
    Queue(std::initializer_list<T> init);
    Queue(const Queue<T> &) = delete;
    Queue<T> &operator=(const Queue<T> &) = delete;

    void Enqueue(T item);
    T Dequeue();

    bool IsEmpty() const {return this->size == 0;};
    unsigned long long Size() const {return this->size;};


private:
    unsigned long long size = 0;
    SinglyNode<T>* head = nullptr;
    SinglyNode<T>* tail = nullptr;
};

#include "../src/Queue/queue_inc.h"

#endif //QUEUE_H

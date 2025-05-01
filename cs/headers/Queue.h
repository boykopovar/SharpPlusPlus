#ifndef QUEUE_H
#define QUEUE_H

#include "../types.h"
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


private:
    SinglyNode<T>* head = nullptr;
    SinglyNode<T>* tail = nullptr;
};

#include "../src/Queue/queue_inc.h"

#endif //QUEUE_H

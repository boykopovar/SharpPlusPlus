#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <ostream>
#include"structs.h"


template <typename T>
class LinkedList {
public:
    LinkedList() = default;
    LinkedList(const LinkedList<T> &) = delete;
    LinkedList<T> &operator=(const LinkedList<T> &) = delete;

    void AddFirst(T object);
    void AddLast(T object);

    void RemoveFirst();
    void RemoveLast();
    void Remove(T object);
    void Remove(DoublyNode<T>* node);

    DoublyNode<T>* Find(T object);
    DoublyNode<T>* First() const;
    DoublyNode<T>* Last() const;

    [[nodiscard]] unsigned long long Size() const {return this->_size;}

private:
    DoublyNode<T>* _head = nullptr;
    DoublyNode<T>* _tail = nullptr;
    unsigned long long _size = 0;
};

#endif //LINKEDLIST_H

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <ostream>

#include "General.h"
#include"structs.h"


template <typename T>
class LinkedList {
public:
    LinkedList() = default;
    LinkedList(std::initializer_list<T> init);
    LinkedList(const LinkedList<T> &) = delete;
    ~LinkedList();

    LinkedList<T> &operator=(const LinkedList<T> &);

    void AddFirst(T object);
    void AddLast(T object);

    bool RemoveFirst();
    bool RemoveLast();
    bool Remove(T object);
    bool Remove(DoublyNode<T>* node);
    void Swap(unsigned long long index1, unsigned long long index2);

    long long Find(T object);
    [[nodiscard]] T First() const;
    [[nodiscard]] T Last() const;

    T& operator[](long long index) const;
    T& operator[](long long index);
    [[nodiscard]] unsigned long long Size() const {return this->_size;}

    template<typename U>
    friend std::ostream &operator<<(std::ostream &out, const LinkedList<U> &list);

private:
    T& _link_by_index(unsigned long long index) const;
    DoublyNode<T>* _head = nullptr;
    DoublyNode<T>* _tail = nullptr;
    unsigned long long _size = 0;
};

#include"../src/LinkedList/linkedlist_inc.h"

#endif //LINKEDLIST_H

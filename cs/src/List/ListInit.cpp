#include "../../headers/List.h"

template<typename T>
List<T>::List(const List &other) : _array(new T[other._capacity]), _size(other._size), _capacity(other._capacity){
    for (unsigned long i = 0; i < other._size; ++i) {
        this->_array[i] = other._array[i];
    }
}

template <typename T>
List<T>::List(unsigned long capacity, const bool default_init)
{
    this->_array = default_init ? new T[capacity]() : new T[capacity];
    this->_capacity = capacity;
    this->_size = default_init ? capacity : 0;
}

template<typename T>
List<T>::List(std::initializer_list<T> init) {
    this->_capacity = init.size();
    this->_size = init.size();
    this->_array = new T[this->_capacity];
    for (unsigned long i = 0; i < this->_size; ++i) {
        this->_array[i] = init.begin()[i];
    }
}
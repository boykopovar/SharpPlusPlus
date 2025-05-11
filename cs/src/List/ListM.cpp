#include "../../headers/List.h"


template<typename T>
inline unsigned long List<T>::Size() const {
    return this->_size;
}

template<typename T>
inline unsigned long List<T>::capacity() const {
    return this->_capacity;
}

template<typename T>
inline void List<T>::SetCapacity(const unsigned long new_capacity) {
    if (new_capacity < this->_size) throw std::runtime_error("New capacity can't be less than current size");
    this->_newMemory(new_capacity);
}

template<typename T>
inline void List<T>::append(T item) {
    if (this->_capacity < this->_size + 1) {
        auto new_capacity = this->_capacity > 0 ? this->_capacity * 2 : 1;
        this->_newMemory(new_capacity);
    }
    this->_array[this->_size] = item;
    ++this->_size;
}

template<typename T>
inline void List<T>::Swap(long long index1, long long index2) {
    T temp = this[index1];
    this[index1] = this[index2];
    this[index2] = temp;
}


template<typename T>
inline void List<T>::_newMemory(const unsigned long new_size) {
    if (new_size == this->_capacity) return;
    if (new_size < this->_size) throw std::runtime_error("New size can't be less than current size");
    auto new_array = new T[new_size];
    for (int i = 0; i < this->_size; i++) {
        new_array[i] = this->_array[i];
    }
    this->_capacity = new_size;
    delete[] this->_array;
    this->_array = new_array;
}

template<typename T>
inline List<T> List<T>::GetRange(const unsigned long start, const unsigned long count) const {
    if (start + count > this->_size) throw std::out_of_range("In List::GetRange");
    List<T> new_list(count);
    for (unsigned long i = start; i < start + count; ++i) {
        new_list.append(this->_array[i]);
    }
    return new_list;
}

template<typename T>
inline void List<T>::Clear() {
    delete[] this->_array;
    this->_array = nullptr;
    this->_size = 0;
    this->_capacity = 0;
}

template<typename T>
void List<T>::Insert(T item, unsigned long index) {

}

template<typename T>
inline long long List<T>::Binsearch(T item) const {
    if (this->_size == 0) return -1;
    unsigned long iterations = 0;
    for (unsigned long i = (this->_size - 1) / 2; iterations < this->_size; ++iterations) {
        if (this->_array[i] == item)return i;
        if (this->_array[i] > item)--i;
        else ++i;
    }
    return -1;
}


template<typename T>
inline List<T>::~List() {
    delete[] _array;
}

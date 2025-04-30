#include "../../headers/List.h"


template<typename T>
List<T>& List<T>::operator=(const List<T> &other) {
    if (this == &other) return *this;
    if (!(this->_size == other._size && this->_capacity == other._capacity)) {
        delete[] this->_array;
        this->_array = new T[other._capacity];
    }
    this->_size = other._size;
    this->_capacity = other._capacity;
    for (unsigned long i = 0; i < other._size; ++i) {
        this->_array[i] = other._array[i];
    }
    return *this;
}

template <typename T>
T& List<T>::operator[](long long index)
{
    if (index >= this->_size || (index<0 && -index>this->_size-1))  throw std::out_of_range("[List] Index is out of range");
    return _array[index >= 0 ? index : this->_size+index];
}

template <typename T>
const T& List<T>::operator[](long long index) const
{
    if (index >= this->_size || (index<0 && -index>this->_size-1))  throw std::out_of_range("[List const] Index is out of range");
    return _array[index >= 0 ? index : this->_size+index];
}

template<typename T>
List<T> List<T>::operator+(const List<T> &other) const{
    auto new_list = List<T>(this->_capacity + other._capacity);
    for (unsigned long i = 0; i < this->_size; ++i) {
        new_list.append(this->_array[i]);
    }
    for (unsigned long i = 0; i < other._size; ++i) {
        new_list.append(other._array[i]);
    }
    return new_list;
}

template<typename T>
void List<T>::operator+=(const List<T> &other) {
    this->SetCapacity(this->_size + other._size);
    for (unsigned long i = 0; i < other._size; ++i) {
        this->append(other._array[i]);
    }
}

template<typename T>
List<List<T>> List<T>::operator%(const unsigned long items) const {
    if (items == 0)throw std::invalid_argument("Items can't be zero");
    List<List<T>> new_list;
    for (unsigned long i = 0;i<this->Size();++i) {
        List<T> sub_list(items);
        unsigned long j=0;
        for (; j<items && i+j<this->_size;++j ) {
            sub_list.append(this->_array[i+j]);
        }
        i+=j - 1;
        new_list.append(sub_list);
    }
    return new_list;
}


template<typename T>
List<List<T>> List<T>::operator/(const unsigned long parts) const {
    if (parts == 0)throw std::invalid_argument("Parts can't be zero");
    auto max_sub_list = this->_size/parts;
    const auto max_sub_list_double = static_cast<long double>(this->_size)/parts;
    if (max_sub_list !=max_sub_list_double) ++max_sub_list;

    List<List<T>> new_list(parts);
    unsigned long global_index = 0;
    for (unsigned long i = 0;i<parts;++i) {
        List<T> sub_list(max_sub_list);
        for (unsigned long j = 0;j<max_sub_list && global_index<this->Size();++j) {
            sub_list.append(this->_array[global_index]);
            ++global_index;
        }
        new_list.append(sub_list);
    }
    return new_list;
}
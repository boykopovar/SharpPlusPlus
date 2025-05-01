#include "../../headers/LinkedList.h"

template<typename T>
inline T& LinkedList<T>::operator[](const long long index) {
    return this->_link_by_index(index);
}

template<typename T>
inline T& LinkedList<T>::operator[](const long long index) const{
    return this->_link_by_index(index);
}

template<typename T>
inline T& LinkedList<T>::_link_by_index(unsigned long long index) const {
    if (index >=this->_size) throw std::out_of_range("LinkedList::operator[]: Index out of range");

    auto current_node = this->_head;
    for (unsigned long long i = 0; i <= index; ++i) {
        if (i==index) return current_node->data;
        current_node = current_node->next;
    }
    throw std::out_of_range("LinkedList::operator[]: Not found");
}

template<typename T>
inline std::ostream& operator<<(std::ostream &out, const LinkedList<T>& list) { return no_marks_list_out(out, list); }

inline std::ostream& operator<<(std::ostream &out, const LinkedList<unsigned char>& list) {return single_mark_list_out(out, list); }
inline std::ostream& operator<<(std::ostream &out, const LinkedList<char>& list) {return single_mark_list_out(out, list); }


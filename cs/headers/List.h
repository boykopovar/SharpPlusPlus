#ifndef LIST_H
#define LIST_H

#include <stdexcept>
#include <ostream>
#include <sstream>
#include "General.h"
#include "structs.h"


template <typename T>
class List
{
public:
    explicit List(unsigned long capacity = 0, bool default_init = false);
    List(std::initializer_list<T> init);
    List(const List& other);
    ~List();

    void append(T item);

    [[nodiscard]] List GetRange(unsigned long start, unsigned long count) const;
    [[nodiscard]] unsigned long Size() const;
    [[nodiscard]] unsigned long capacity() const;
    void SetCapacity(unsigned long new_capacity);
    long long Binsearch(T item) const;
    void Clear();
    void Insert(T item, unsigned long index);

    void Sort(SortType sort_type = QuickSort);
    void Swap(long long index1, long long index2);

    T* begin() {return &this->_array[0];};
    T* end() {return &this->_array[this->_size];}

    T& operator[](long long index);
    const T& operator[](long long index) const;

    bool operator==(const List& other) const;
    bool operator!=(const List& other) const {return !this->operator==(other);}

    List<T> operator+(const List<T>& other) const;
    void operator+=(const List<T>& other);
    List<T>& operator=(const List<T>& other);
    List<List<T>> operator%(unsigned long items) const;
    List<List<T>> operator/(unsigned long parts) const;

    template<typename U>
    friend std::ostream& operator<<(std::ostream &out, const List<U>& list);

private:
    T* _array = nullptr;
    unsigned long _size = 0;
    unsigned long _capacity = 0;

    void _newMemory(unsigned long new_size);
    void _quickSort(unsigned long left=0, long long right=-1);
    void _heapSort();
    void _heapify(long long i, long long size);
    void _mergeSort();
    void _mergeSort(long long left, long long right, T* temp);
    void _interpolationSort();
    void _sort(SortType sort_type);
    void _swap(long long index1, long long index2);
};

namespace std {
    template<typename T>
    struct hash<List<T>> {
        unsigned long long operator()(const List<T>& list) const noexcept {
            unsigned long long res_hash = 0;
            std::hash<T> hasher;
            for (unsigned long i = 0; i < list.Size(); ++i) {
                res_hash ^= hasher(list[i]) + 0x9e3779b9 + (res_hash << 6) + (res_hash >> 2);
            }
            return res_hash;
        }
    };
}

#include "../src/List/list_inc.h"

#endif //LIST_H


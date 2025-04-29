#ifndef STRUCTS_H
#define STRUCTS_H

struct Range {
    unsigned long start;
    unsigned long size;
    Range(const unsigned long start, const unsigned long size) : start(start), size(size) {}
};

template <typename T>
struct SinglyNode {
    T data;
    SinglyNode* next = nullptr;
};

template <typename T>
struct DoublyNode {
    T data;
    DoublyNode* next = nullptr;
    DoublyNode* prev = nullptr;
};

    enum SortType {
        QuickSort,
        HeapSort,
        MergeSort,
        InterpolationSort,
    };

#endif //STRUCTS_H

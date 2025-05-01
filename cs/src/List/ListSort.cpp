#include "../../headers/List.h"

template<>
inline void List<int>::Sort(const SortType sort_type) { _sort(sort_type); }

template<>
inline void List<long>::Sort(const SortType sort_type) { _sort(sort_type); }

template<>
inline void List<long long>::Sort(const SortType sort_type) { _sort(sort_type); }

template<>
inline void List<unsigned>::Sort(const SortType sort_type) { _sort(sort_type); }

template<>
inline void List<unsigned long long>::Sort(const SortType sort_type) { _sort(sort_type); }

template<>
inline void List<double>::Sort(const SortType sort_type) { _sort(sort_type); }

template<>
inline void List<long double>::Sort(const SortType sort_type) { _sort(sort_type); }

template<typename T>
inline void List<T>::_sort(const SortType sort_type) {
    switch (sort_type) {
        case QuickSort: _quickSort(); break;
        case HeapSort: _heapSort(); break;
        case MergeSort: _mergeSort(); break;
        case InterpolationSort: _interpolationSort(); break;
    }
}

template<typename T>
inline void List<T>::_quickSort(const unsigned long left, long long right) {
    if (right == -1) right = this->_size - 1;
    if (left >= right || this->_size <= 1) return;

    T pivot = this->_array[(left + right) / 2];
    unsigned long i = left, j = right;

    while (i <= j) {
        while (this->_array[i] < pivot) i++;
        while (this->_array[j] > pivot) j--;
        if (i <= j) {
            this->_swap(i, j);
            ++i;
            --j;
        }
    }
    this->_quickSort(left, j);
    this->_quickSort(i, right);
}

template<typename T>
inline void List<T>::_swap(long long index1, long long index2) {
    T buf = this->_array[index1];
    this->_array[index1] = this->_array[index2];
    this->_array[index2] = buf;
}

template<typename T>
inline void List<T>::_heapSort() {
    if (this->_size <= 1) return;

    for (long long i = this->_size / 2 - 1; i >= 0; --i) {
        this->_heapify(i, this->_size);
    }

    for (long long i = this->_size - 1; i > 0; --i) {
        this->_swap(0, i);
        this->_heapify(0, i);
    }
}

template<typename T>
inline void List<T>::_heapify(const long long i, const long long size) {
    long long max = i;
    long long left = 2 * i + 1;
    long long right = 2 * i + 2;

    if (left < size && this->_array[left] > this->_array[max]) max = left;
    if (right < size && this->_array[right] > this->_array[max]) max = right;
    if (max != i) {
        this->_swap(i, max);
        this->_heapify(max, size);
    }
}


template<typename T>
inline void List<T>::_mergeSort() {
    if (this->_size <= 1) return;
    T *temp = new T[this->_size];
    this->_mergeSort(0, this->_size - 1, temp);
    delete[] temp;
}

template<typename T>
inline void List<T>::_mergeSort(const long long left, const long long right, T *temp) {
    if (left >= right) return;
    const long long mid = (left + right) / 2;
    _mergeSort(left, mid, temp);
    _mergeSort(mid + 1, right, temp);

    long long i = left, j = mid + 1, temp_index = left;
    while (i <= mid && j <= right) {
        temp[temp_index++] = (this->_array[i] <= this->_array[j] ? this->_array[i++] : this->_array[j++]);
    }

    while (i <= mid) temp[temp_index++] = this->_array[i++];
    while (j <= right) temp[temp_index++] = this->_array[j++];
    for (i = left; i <= right; ++i) this->_array[i] = temp[i];
}

template<typename T>
inline void List<T>::_interpolationSort() {
    if (this->_size <= 1) return;

    T min = this->_array[0];
    T max = this->_array[0];

    for (unsigned long i = 1; i < this->_size; ++i) {
        if (this->_array[i] < min) min = this->_array[i];
        if (this->_array[i] > max) max = this->_array[i];
    }

    if (min == max) return;
    T *temp = new T[this->_size];
    auto *count = new unsigned long [this->_size]();

    for (unsigned long i = 0; i < this->_size; ++i) {
        double k = static_cast<double>(this->_array[i] - min) / (max - min);
        const auto pos = static_cast<unsigned long>(k * (this->_size - 1));
        ++count[pos];
    }

    for (unsigned long i = 1; i < this->_size; ++i) count[i] += count[i - 1];
    for (long long i = this->_size - 1; i >= 0; --i) {
        double k = static_cast<double>(this->_array[i] - min) / (max - min);
        auto pos = static_cast<unsigned long>(k * (this->_size - 1));
        temp[--count[pos]] = this->_array[i];
    }

    for (unsigned long i = 0; i < this->_size; ++i) this->_array[i] = temp[i];

    delete[] temp;
    delete[] count;
}




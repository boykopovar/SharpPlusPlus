#include "../../headers/BitArray.h"

BitArray::BitReference BitArray::operator[](const unsigned long long index) {
    if (index>= this->_bitsCount) throw std::out_of_range("BitArray::operator[] - Index is out of range!");
    return {this->_numbers[_word_index(index)], this->_bit_offset(index), *this};
}

bool BitArray::operator[](const unsigned long long index) const {
    if (index>= this->_bitsCount) throw std::out_of_range("BitArray::operator[] const - Index is out of range!");
    return (this->_numbers[_word_index(index)] >> this->_bit_offset(index)) & 1;
}

BitArray::BitReference &BitArray::BitReference::operator=(const bool value) {
    if (value)this->_word |= (1ULL << _offset);
    else this->_word &= ~(1ULL << _offset);
    return *this;
}






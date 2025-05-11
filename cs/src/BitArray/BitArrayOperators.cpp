#include "../../headers/BitArray.h"

BitArray::BitReference BitArray::operator[](const unsigned long long index) {
    if (index>= this->_bitsCount) throw std::out_of_range("BitArray::operator[] - Index is out of range!");
    return {this->_numbers[_word_index(index)], this->_bit_offset(index), *this};
}

bool BitArray::operator[](const unsigned long long index) const {
    if (index>= this->_bitsCount) throw std::out_of_range("BitArray::operator[] const - Index is out of range!");
    const bool bit = (this->_numbers[_word_index(index)] >> this->_bit_offset(index)) & 1;
    return this->_isReversed ? !bit : bit;
}

bool BitArray::operator==(const BitArray &other) const {
    if (this->Size() != other.Size()) return false;
    for (unsigned long long i = 0; i < this->Size(); ++i) {
        if ((*this)[i] != other[i]) return false;
    }
    return true;
}


BitArray::BitReference &BitArray::BitReference::operator=(bool value) {
    if (this->_parent._isReversed) value = !value;
    const bool current_value = (this->_word >> this->_offset) & 1ULL;

    if (current_value == value) return *this;

    if (value) {
        this->_word |= (1ULL << _offset);
        this->_parent._trueCount += this->_parent._isReversed ? -1 : 1;
    }
    else {
        this->_word &= ~(1ULL << _offset);
        this->_parent._trueCount -= this->_parent._isReversed ? -1 : 1;
    }
    return *this;
}






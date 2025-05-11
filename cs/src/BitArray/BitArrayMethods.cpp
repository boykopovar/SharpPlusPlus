#include "../../headers/BitArray.h"


BitArray::BitArray(const unsigned long long size, const bool default_value) {
    this->_bitsCount = size;
    unsigned long long array_size = size / sizeof(unsigned long long);
    if (size % sizeof(unsigned long long) != 0) ++array_size;
    this->_numbers = List<unsigned long long>(array_size);

    for (unsigned long long i = 0; i < size; ++i) {
        if (i+1 % sizeof(unsigned long long) != 0) this->_numbers.append(default_value);
        (*this)[i] = default_value;
    }

    if (default_value) this->_trueCount = size;
}

BitArray::BitArray(const std::initializer_list<bool> init) : BitArray(init.size(), false){
    for (unsigned long long i = 0; i < init.size(); ++i) {
        if (init.begin()[i] == true) (*this)[i] = true;
    }
}


bool BitArray::AllTrue() const {
    return this->_trueCount == this->_bitsCount;
}

bool BitArray::HasTrue() const {
    return this->_trueCount > 0;
}

unsigned long long BitArray::TrueCount() const {
    return this->_trueCount;
}

void BitArray::Flip(const unsigned long long index) {
    (*this)[index] = !(*this)[index];
}

void BitArray::Flip() {
    this->_isReversed = !this->_isReversed;
    this->_trueCount = this->_bitsCount - this->_trueCount;
}



void BitArray::Set(const unsigned long long index, const bool value) {
    (*this)[index] = value;
}

void BitArray::Set(const bool value) {
    this->_isReversed = false;
    for (unsigned long long i = 0; i < this->_bitsCount; ++i) {
        (*this)[i] = value;
    }
    if (value) this->_trueCount = this->_bitsCount;
    else this->_trueCount = 0;
}

unsigned long long BitArray::Size() const {
    return this->_bitsCount;
}

bool BitArray::IsTrue(const unsigned long long index) const {
    return (*this)[index];
}

String BitArray::ToString() const {
    const auto chars = new char[this->_bitsCount+1];
    unsigned long long i = 0;
    for (; i < this->_bitsCount; ++i) {
        chars[i] = static_cast<char>('0' + (*this)[i]);
    }
    chars[i] = '\0';
    String result = chars;
    delete[] chars;
    return result;
}

unsigned long long BitArray::ToNumber() const {
    unsigned long long result = 0;
    for (unsigned long long i = 0; i < this->_bitsCount; ++i) {
        result += (*this)[i] * (IntPow(10, static_cast<long long>(i)));
    }
    return result;
}


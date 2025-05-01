#ifndef BITARRAY_H
#define BITARRAY_H
#include "string.h"

class BitArray {

public:
    explicit BitArray(unsigned long long size, bool default_value=false);
    BitArray(std::initializer_list<bool> init);

    [[nodiscard]] bool AllTrue() const;
    [[nodiscard]] bool HasTrue() const;
    [[nodiscard]] unsigned long long TrueCount() const;

    void Flip(unsigned long long index);
    void Flip();

    void Set(unsigned long long index, bool value);
    void Set(bool value);

    [[nodiscard]] unsigned long long Size() const;
    [[nodiscard]] bool IsTrue(unsigned long long index) const;
    [[nodiscard]] string ToString() const;

    [[nodiscard]] unsigned long long ToNumber() const;

    class BitReference {
    private:
        unsigned long long& _word;
        unsigned long long _offset = 0;
        BitArray& _parent;
    public:
        BitReference(unsigned long long& word, const unsigned long long offset, BitArray& parent) : _word(word), _offset(offset), _parent(parent){}
        BitReference(BitReference&) = delete;
        operator bool() const {return (this->_word >> this->_offset)&1;}
        BitReference& operator=(bool value);
    };

    BitReference operator[](unsigned long long index);
    bool operator[](unsigned long long index) const;
    explicit operator bool() const{return this->HasTrue();}
    friend std::ostream& operator<<(std::ostream& os, const BitArray& bits) {return os<<bits.ToString();}

private:
    bool _isReversed = false;
    unsigned long long _bitsCount = 0;
    unsigned long long _trueCount = 0;

    unsigned long long _word_size = sizeof(unsigned long long) * 8; //в битах
    [[nodiscard]] unsigned long _bit_offset(const unsigned long long pos) const {return pos % _word_size;}
    [[nodiscard]] unsigned long _word_index(const unsigned long long pos) const {return pos / _word_size;}

    List<unsigned long long> _numbers;
};

#endif //BITARRAY_H

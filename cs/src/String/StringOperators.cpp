#include "../../headers/string.h"


String String::operator[](const long long index) const{
    return String(this->_symbols[index]);
}

String String::operator+(const String& other) const {
    return String(this->_symbols + other._symbols);
}

void String::operator+=(const String& other) {
    this->_symbols += other._symbols;
}


bool String::operator==(const String& other) const {
    if (this->Size()!=other.Size()) return false;
    for (unsigned long i = 0; i<this->Size(); ++ i) {
        if (this->_symbols[i] != other._symbols[i]) return false;
    }
    return true;
}

String String::operator()(const unsigned long start, const long long size) const {
    return this->Substr(start, size);
}

String String::operator[](const Range range) const {
    return this->Substr(range.start, range.size);
}


string string::operator[](const long long index) const{
    return string(this->_symbols[index]);
}

string string::operator+(const string& other) const {
    return string(this->_symbols + other._symbols);
}

void string::operator+=(const string& other) {
    this->_symbols += other._symbols;
}


bool string::operator==(const string& other) const {
    for (unsigned long i = 0; i<this->Size(); ++ i) {
        if (this->_symbols[i] != other._symbols[i]) return false;
    }
    return true;
}

string string::operator()(const unsigned long start, const long long size) const {
    return this->Substr(start, size);
}

string string::operator[](const Range range) const {
    return this->Substr(range.start, range.size);
}
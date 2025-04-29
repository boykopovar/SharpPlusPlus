#include "../../headers/string.h"


string::string(const char* text) {
    this->_symbols = _chars_to_list32(text);
}

string::string(const char32_t c) {
    this->_symbols.append(c);
}

string::string(const char32_t* text) {
    for (unsigned long i = 0; text[i] != '\0'; ++i) {
        this->_symbols.append(text[i]);
    }
}

string::string(const List<char32_t>& text) {
    this->_symbols = text;
}

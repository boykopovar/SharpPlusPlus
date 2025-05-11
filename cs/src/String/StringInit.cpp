#include "../../headers/string.h"


String::String(const char* text) {
    this->_symbols = _chars_to_list32(text);
}

String::String(const char32_t c) {
    this->_symbols.append(c);
}


String::String(const char32_t* text) {
    for (unsigned long i = 0; text[i] != '\0'; ++i) {
        this->_symbols.append(text[i]);
    }
}


String::String(const List<char32_t>& text) {
    this->_symbols = text;
}

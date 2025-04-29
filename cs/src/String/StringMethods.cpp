#include "../../headers/string.h"


unsigned long string::Size() const {
    return this->_symbols.Size();
}


long long string::Find(const string& c, const unsigned long start) const {
    if (c.Size()!=1) throw std::runtime_error("c.Size()!=1");
    for (unsigned long i = start; i < this->Size(); ++i) {
        if ((*this)[i] == c) return i;
    }
    return -1;
}



string string::Substr(const unsigned long start, const long long size) const {
    const auto len = size == -1 ? this->Size() - start : size;
    if (size > this->Size()-start) throw std::out_of_range("string::Substr");
    return string(_symbols.GetRange(start, len));
}


List<string> string::Split(string delim) const
{
    if (delim.Size()!=1) throw std::runtime_error("delim must be single character");
    List<string> tokens;
    std::string token;
    unsigned long start=0, end = this->Find(delim);
    while (end != -1)
    {
        if (end != 0)
        {
            tokens.append(this->Substr(start, end - start));
        }
        start = end + 1;
        end = this->Find(delim, start);
    }
    if (start<this->Size())
    {
        tokens.append(this->Substr(start, this->Size() - start));
    }
    return tokens;
}

List<char32_t> string::_chars_to_list32(const char* chars) {
    List<char32_t> result;
    unsigned long pos = 0;

    while (chars[pos] != '\0') {
        char32_t c = '?';

        //1 байт
        if (static_cast<unsigned char>(chars[pos]) < IntPow(2, 7)) {
            c = static_cast<unsigned char>(chars[pos]);
            pos+=1;
        }

        //2 байта
        else if (static_cast<unsigned char>(chars[pos]) >= 3 * IntPow(2, 6) &&
            static_cast<unsigned char>(chars[pos]) < 7 * IntPow(2, 5))
        {
            c = (static_cast<unsigned char>(chars[pos]) - (3 * IntPow(2, 6))) * IntPow(2, 6);
            c += static_cast<unsigned char>(chars[pos+1]) - 2 * IntPow(2, 6);
            pos+=2;
        }

        //3 байта
        else if (static_cast<unsigned char>(chars[pos]) >= 7 * IntPow(2, 5) &&
            static_cast<unsigned char>(chars[pos]) < 15 * IntPow(2, 4))
        {
            c = (static_cast<unsigned char>(chars[pos]) - (7 * IntPow(2, 5))) * IntPow(2, 12);
            c += (static_cast<unsigned char>(chars[pos+1]) - (2 * IntPow(2, 6))) * IntPow(2, 6);
            c += static_cast<unsigned char>(chars[pos+2]) - 2 * IntPow(2, 6);
            pos+=3;
        }

        //4 байта
        else if (static_cast<unsigned char>(chars[pos]) >= 15 * IntPow(2, 4))
        {
            c = (static_cast<unsigned char>(chars[pos]) - (15 * IntPow(2, 4))) * IntPow(2, 18);
            c += (static_cast<unsigned char>(chars[pos+1]) - (2 * IntPow(2, 6))) * IntPow(2, 12);
            c += (static_cast<unsigned char>(chars[pos+2]) - (2 * IntPow(2, 6)) ) * IntPow(2, 6);
            c += static_cast<unsigned char>(chars[pos+3]) - 2 * IntPow(2, 6);
            pos+=4;
        }
        else pos+=1;
        result.append(c);
    }
    return result;
}

char* string::c_str() const {
    const unsigned long max_size = this->_symbols.Size() * 4 + 1;
    auto c_str = new char[max_size];
    unsigned long pos = 0;

    for (unsigned long i = 0; i < this->_symbols.Size(); ++i) {
        const char32_t c = this->_symbols[i];
        //if (pos>=max_size) std::cout<<"Превысили размер\n";
        // 1 байт
        if (c <= IntPow(2, 7) - 1) c_str[pos++] = static_cast<char>(c);

        // 2 байта
        else if (c<= IntPow(2, 11) - 1) {
            c_str[pos++] = static_cast<char>((3 * IntPow(2, 6)) + (c / IntPow(2, 6)));
            c_str[pos++] = static_cast<char>((2 * IntPow(2, 6)) + (c % IntPow(2, 6)));
        }

        // 3 байта
        else if (c<= IntPow(2, 16) - 1) {
            c_str[pos++] = static_cast<char>((7 * IntPow(2, 5)) + (c / IntPow(2, 12)));

            c_str[pos++] = static_cast<char>((2 * IntPow(2, 6)) + ((c / IntPow(2, 6)) % IntPow(2, 6) ));
            c_str[pos++] = static_cast<char>((2 * IntPow(2, 6)) + (c % IntPow(2, 6)));
        }

        // 4 байта
        else if (c<= IntPow(2, 21) - 1) {
            c_str[pos++] = static_cast<char>((15 * IntPow(2, 4)) + (c / IntPow(2, 18)));

            c_str[pos++] = static_cast<char>((2 * IntPow(2, 6)) + ((c / IntPow(2, 12)) % IntPow(2, 6) ));
            c_str[pos++] = static_cast<char>((2 * IntPow(2, 6)) + ((c / IntPow(2, 6)) % IntPow(2, 6) ));
            c_str[pos++] = static_cast<char>((2 * IntPow(2, 6)) + (c % IntPow(2, 6)));
        }
        // else {
        //     std::cout<<"c: " << static_cast<int>(c)<< '\n';
        // }
    }
    c_str[pos] = '\0';
    return c_str;
}
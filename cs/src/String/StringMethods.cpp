#include "../../headers/string.h"



unsigned long String::Size() const {
    return this->_symbols.Size();
}


long long String::Find(String sub, const unsigned long start) const {
    if (sub.Size() == 0) return -1;
    if (sub.Size() > this->Size()) return -1;

    for (unsigned long i = start; i < this->Size() - sub.Size(); ++i) {
        bool match = true;
        for (unsigned long j = 0; j < sub.Size(); ++j) {
            if ((*this)[i+j] != sub[j]) {
                match = false;
                break;
            }
        }
        if (match) return i;
    }
    return -1;
}




String String::Substr(const unsigned long start, const long long size) const {
    const auto len = size == -1 ? this->Size() - start : size;
    if (size > this->Size()-start) throw std::out_of_range("string::Substr");
    return String(_symbols.GetRange(start, len));
}


// List<string> string::Split(string delim) const
// {
//     if (delim.Size()!=1) throw std::runtime_error("delim must be single character");
//     List<string> tokens;
//     std::string token;
//     unsigned long start=0, end = this->Find(delim);
//     while (end != -1)
//     {
//         if (end != 0)
//         {
//             tokens.append(this->Substr(start, end - start));
//         }
//         start = end + 1;
//         end = this->Find(delim, start);
//     }
//     if (start<this->Size())
//     {
//         tokens.append(this->Substr(start, this->Size() - start));
//     }
//     return tokens;
// }

List<String> String::Split(const String& delim) const
{
    if (delim.Size() == 0) throw std::runtime_error("string::Split: Delimiter cannot be empty");
    List<String> tokens;
    unsigned long start = 0, end = this->Find(delim, start);
    while (end != -1) {
        if (end!= static_cast<long long>(start)) tokens.append(this->Substr(start, end - start));
        start = end + delim.Size();
        end = this->Find(delim, start);
    }

    if (start < this->Size()) tokens.append(this->Substr(start, this->Size() - start));
    return tokens;
}

String& String::Strip() {
    if (this->Size() == 0) return *this;
    unsigned long long start = 0, end = this->Size()-1;
    for (unsigned long long i = 0; i < this->Size()-1; ++i) {
        if ((*this)[i] == " ") start = i+1;
        else if ((*this)[i] == "\n") start = i+1;
        else break;
    }
    for (unsigned long long i = this->Size()-1; i >0; --i) {
        if ((*this)[i] == " ") end = i;
        else if ((*this)[i] == "\n") end = i;
        else break;
    }
    const unsigned long long new_size = end - start;
    (*this) = this->Substr(start, new_size);
    return *this;
}

bool String::IsNumber() const
{
    const auto c_str = this->c_str();

    for (unsigned long long i = 0; true; ++i)
    {
        const auto& c = c_str[i];
        if (c == '\0') break;
        if (!isdigit(c))
        {
            delete[] c_str;
            return false;
        }
    }

    delete[] c_str;
    return true;
}

long double String::ToDouble() const {
    long double result = 0.0;
    long double sign = 1.0;
    bool point = false;
    bool has_sign = false;
    long double dec_factor = 1.0;

    for (unsigned long long i = 0; i < this->Size(); ++i) {
        if (const auto c = this->_symbols[i]; c == u'-' && !has_sign) {
            sign = -1.0;
            has_sign = true;
        }
        else if ((c == u'.' || c == u',') && !point) point = true;
        else if (c>=u'0' && c <= u'9') {
            const unsigned short digit = static_cast<int>(c) - u'0';
            if (point) {
                dec_factor *= 0.1;
                result += digit * dec_factor;
            }
            else result = result * 10.0 + digit;
        }
        else throw std::invalid_argument("Invalid character for number");
    }
    return sign * result;
}

long long String::ToInt() const
{
    return static_cast<long long>(this->ToDouble());
}

void String::Append(const char* symbols, const unsigned long long size)
{
    const auto c_str = new char[size+1];
    for (unsigned long long i = 0; i < size; ++i) c_str[i] = symbols[i];
    c_str[size] = '\0';

    (*this) += c_str;
    delete[] c_str;
}


void String::_fromLongDouble(long double number) {
    if (number == 0.0L) {
        this->_symbols.append(u'0');
        return;
    }
    const bool is_negative = number < 0.0L;
    if (is_negative) number = -number;

    auto int_part = static_cast<long long>(number);
    long double double_part = number - int_part;

    List<char32_t> int_symbols;
    if (int_part == 0) int_symbols.append(u'0');
    else {
        while (int_part > 0) {
            const char32_t digit = u'0' + (int_part %10);
            int_symbols.append(digit);
            int_part /= 10;
        }
    }

    for (unsigned long long i = 0, j = int_symbols.Size() - 1; i < j; ++i, --j) {
        const char32_t temp = int_symbols[i];
        int_symbols[i] = int_symbols[j];
        int_symbols[j] = temp;
    }
    for (unsigned long long i = 0; i < int_symbols.Size(); ++i) this->_symbols.append(int_symbols[i]);

    if (double_part > 0.0L) {
        this->_symbols.append(u'.');
        for (unsigned long long i = 0; i < 6 && double_part > 0.0L; ++i) {
            double_part *= 10.0L;
            const unsigned short digit = static_cast<unsigned short>(double_part);
            this->_symbols.append(digit);
            double_part -= digit;
        }
    }
    if (is_negative) {
        List<char32_t> temp_symbols;
        temp_symbols.append(u'-');
        for (unsigned long long i = 0; i< this->_symbols.Size(); ++i) {
            temp_symbols.append(this->_symbols[i]);
        }
        this->_symbols = temp_symbols;
    }
}

List<char32_t> String::_chars_to_list32(const char* chars) {
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

char* String::c_str() const {
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
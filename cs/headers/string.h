#ifndef STRING_H
#define STRING_H

#include "List.h"
#include "General.h"
#include "structs.h"

class String {
public:
    String() = default;
    String(const char* text);
    String (const std::string& s) {this->_symbols = _chars_to_list32(s.c_str());}

    explicit String(const char32_t* text);
    explicit String(char32_t c);

    explicit String(const long double number){this->_fromLongDouble(number);}
    explicit String(const long long number){this->_fromLongDouble(static_cast<long double>(number));}
    explicit String(const int number){this->_fromLongDouble(number);}
    explicit String(const unsigned long long number){this->_fromLongDouble(number);}

    [[nodiscard]] char* c_str() const;
    [[nodiscard]] List<String> Split(const String& delim = " ") const;
    String& Strip();
    [[nodiscard]] bool IsNumber() const;

    [[nodiscard]] long long Find(String sub, unsigned long start = 0) const;
    [[nodiscard]] unsigned long Size() const;

    [[nodiscard]] String Substr(unsigned long start, long long size = -1) const;
    String operator() (unsigned long start, long long size = -1) const;

    String operator[](long long index) const;
    String operator[](Range range) const;

    String operator+(const String& other) const;
    void operator+=(const String& other);

    bool operator==(const String& other) const;
    bool operator!=(const String& other) const{return !(*this == other);};
    bool operator>(const String& other) const{return this->Size()>other.Size();}
    bool operator<(const String& other) const{return this->Size()<other.Size();}
    bool operator>=(const String& other) const{return this->Size() >= other.Size();}
    bool operator<=(const String& other) const{return this->Size() <= other.Size();}

    friend std::ostream& operator<<(std::ostream &out, const String &str);
    friend std::ostream& operator<<(std::ostream &out, const List<String>& list);
    [[nodiscard]] unsigned long long GetHash() const {return std::hash<List<char32_t>>()(this->_symbols);}

    [[nodiscard]] long double ToDouble() const;
    [[nodiscard]] long long ToInt() const;


private:
    List<char32_t> _symbols;
    List<char32_t> _chars_to_list32(const char* chars);
    List<char*> _c_strs_list;

    void _fromLongDouble(long double number);

    explicit String(const List<char32_t>& text);
};

typedef String str;

namespace std {
    template<>
    struct hash<String> {unsigned long long operator()(const String& s) const noexcept {return s.GetHash();}};
}

#endif //STRING_H

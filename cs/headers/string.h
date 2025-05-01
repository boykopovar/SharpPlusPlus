#ifndef STRING_H
#define STRING_H

#include "List.h"
#include "General.h"
#include "structs.h"

class string {
public:
    string() {};

    string(const char* text);
    explicit string(const char32_t* text);
    explicit string(char32_t c);

    [[nodiscard]] char* c_str() const;
    [[nodiscard]] List<string> Split(string delim = " ") const;

    [[nodiscard]] long long Find(const string& c, unsigned long start = 0) const;
    [[nodiscard]] unsigned long Size() const;

    [[nodiscard]] string Substr(unsigned long start, long long size = -1) const;
    string operator() (unsigned long start, long long size = -1) const;

    string operator[](long long index) const;
    string operator[](Range range) const;

    string operator+(const string& other) const;
    void operator+=(const string& other);

    bool operator==(const string& other) const;

    friend std::ostream& operator<<(std::ostream &out, const string &str);
    friend std::ostream& operator<<(std::ostream &out, const List<string>& list);

private:
    List<char32_t> _symbols;
    List<char32_t> _chars_to_list32(const char* chars);

    explicit string(const List<char32_t>& text);
};

typedef string str;

#endif //STRING_H

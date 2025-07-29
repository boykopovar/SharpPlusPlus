#include "cs/types.h"

int main() {
    Dictionary<DateTime, String> dict;

    dict[DateTime::Now()] = "тест";
    dict[DateTime(1, 1, 1970)] = "qwer";

    std::cout << DateTime("12.12.2012 12:12:12").ToString(false) << '\n';
    std::cout << String("qwe").Split();
}
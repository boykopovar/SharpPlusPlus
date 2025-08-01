#include "cs/types.h"

int main() {
    Dictionary<DateTime, String> dict;
    dict[DateTime::Now()] = "тест";
    std::cout << dict[DateTime::Now()] << '\n';

    String a = "тест";
    a.Append("тест");
    std::cout << a;
}

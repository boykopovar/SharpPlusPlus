#include "cs/types.h"


int main() {
    Dictionary<DateTime, String> dict;

    dict[DateTime(2025, 07, 30)] = "\nкак сам";
    dict[DateTime::Now()] = "тест\n";

    print(dict[{input("Введите год: ").ToInt(), 07, 30}]);
}
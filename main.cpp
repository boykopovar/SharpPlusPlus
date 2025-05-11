#include "cs/types.h"

int main() {
    Dictionary<int, String> dict;
    dict[123] = "привет";
    dict[321] = "hello";
    std:: cout << dict[123] << '\n';
}
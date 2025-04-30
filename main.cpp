#include "cs/types.h"

int main() {
    BitArray bits = {true, false, false, true};    // 1001
    bits[2] = true;      // 1011
    std::cout << bits << std::endl; // 1011
    std::cout << bits.TrueCount() << std::endl; // 3
    return 0;
}
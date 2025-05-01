#include "cs/types.h"


int main() {
    // === LinkedList Example ===
    std::cout<< " === LinkedList Example ===\n";
    LinkedList<int> linked = {1, 2, 3, 4, 5, 6, 7, 8, 9 ,10};

    linked.Remove(9);
    linked.AddFirst(3);

    std::cout << linked << "\n\n";
}
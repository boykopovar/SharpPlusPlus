#include "cs/types.h"


int main() {
    // === List Example ===
    std::cout << " === List Example ===\n";

    List<int> numbers = {3, 1, 2};
    numbers += {2, 4};
    numbers.Sort();
    std::cout<<numbers<<'\n'; // [1, 2, 2, 3, 4]
    std::cout<< numbers.GetRange(1, 2) << '\n'; // [2, 2]

    List<int> list = {1, 2, 3, 4, 5, 6, 7, 8, 9 ,10};
    std::cout<<list / 3<<'\n'; // [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10]]
    std::cout<<list % 3<<"\n\n"; // [[1, 2, 3], [4, 5, 6], [7, 8, 9], [10]]


    // === string example ===
    std::cout << " === string Example ===\n";
    string a = "Hello";
    string b = " мир!";
    std::cout << (a + b).Split() << '\n'; // ["Hello", "мир!"]
    std::cout<< a[0]<<'\n'; // H
    auto c = a + b + "!!";
    std::cout<< c(4, 7)<<"\n\n"; // o мир!!


    // === Queue example ===
    std::cout << " === Queue Example ===\n";
    Queue<int> queue;
    queue.Enqueue(42);
    queue.Enqueue(11);
    std::cout << queue.Dequeue() << ' ' << queue.Dequeue() << "\n\n"; // 42 11


    // === BitArray Example ===
    std::cout<< " === BitArray Example ===\n";
    BitArray bits(5);
    bits.Set(true);
    bits[3] = false;
    bits.Flip();
    std::cout << bits << std::endl; // 00010


    // === LinkedList Example ===
    std::cout<< " === LinkedList Example ===\n";
    LinkedList<int> linked = {1, 2, 3, 4, 5, 6, 7, 8, 9 ,10};
    linked.Remove(9);
    linked.AddFirst(3);
    std::cout << linked << "\n\n";


    // === print example ===
    std::cout << " === print Example ===\n";
    print(42, "hello", 3.14); // 42 hello 3.14
}
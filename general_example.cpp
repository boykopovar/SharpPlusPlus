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
    string a = "Hello";
    string b = " мир!";
    std::cout << (a + b).Split() << '\n'; // ["Hello", "мир!"]
    std::cout<< a[0]<<'\n'; // H
    auto c = a + b + "!!";
    std::cout<< c(4, 7)<<"\n\n"; // o мир!!


    // === Queue example ===
    Queue<int> queue;
    queue.Enqueue(42);
    queue.Enqueue(11);
    std::cout << queue.Dequeue() << ' ' << queue.Dequeue() << "\n\n"; // 42 11


    // === print example ===
    print(42, "hello", 3.14); // 42 hello 3.14
}
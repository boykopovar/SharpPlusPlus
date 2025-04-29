// #define NO_INSTALL_UTF8
#include "cs/types.h"

int main()
{
    List<int> list = {1, 5, 3, 4, 5, 2, 7, 1, 3, 1};
    list.Sort(InterpolationSort);
    std::cout<< list <<'\n';

    string a = "Привет, как";
    std::cout<< (a + " дела ?").Split()[2] <<'\n';

    a+= " дела?";
    print(a.Find("?"));

    Queue<string> q;
    q.Enqueue(a);
    q.Enqueue("Да, все норм.");
    print(q.Dequeue());
}

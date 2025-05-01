#ifndef CS_TOOLS_H
#define CS_TOOLS_H

#include <iostream>
#include "src/String/string_include.h"
#include "src/List/list_include.h"
#include "src/Queue/queue_include.h"
#include "src/BitArray/bitarray_include.h"
#include "src/Nums.cpp"
#include "src/LinkedList/linkedlist_include.h"
#include "src/general/general_include.h"


template<typename T>
void print(T&& last) {
    std::cout<<last<<std::endl;
}

template <typename T, typename... Args>
void print(T&& first, Args&&... args) {
    std::cout<<first<<' ';
    print(std::forward<Args>(args)...);
}

inline long long Binpow(const long long digit, long long exp, const long long mod)
{
    if (mod==0) throw std::invalid_argument("mod cannot be zero");
    if (exp<0) throw std::invalid_argument("exp cannot be zero");
    long long result = 1;
    long long base = digit % mod;
    while (exp > 0)
    {
        if (exp%2 == 1) result = result*base % mod;
        base = base*base % mod;
        exp/=2;
    }
    return result;
}

#ifdef _WIN32
#ifndef NO_INSTALL_UTF8

    #include <Windows.h>
    struct InstallUtf8 {
        InstallUtf8() {
            SetConsoleOutputCP(CP_UTF8);
            SetConsoleCP(CP_UTF8);
            //system("chcp 65001 > nul");

            // HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
            // DWORD mode = 0;
            // GetConsoleMode(hStdin, &mode);
            // mode &= ~ENABLE_ECHO_INPUT;
            // SetConsoleMode(hStdin, mode);
        }
    };
    #if __cplusplus >= 201703L
        inline InstallUtf8 Instance;
    #else
        static InstallUtf8 instance;
    #endif

#endif
#endif



#endif //CS_TOOLS_H

#ifndef CS_TOOLS_H
#define CS_TOOLS_H

#include <iostream>
#include "headers/General.h"
#include "headers/LinkedList.h"
#include "headers/List.h"
#include "headers/BitArray.h"
#include "headers/Queue.h"
#include "headers/string.h"


template<typename T>
inline void print(T&& last) {
    std::cout<<last<<std::endl;
}

template <typename T, typename... Args>
inline void print(T&& first, Args&&... args) {
    std::cout<<first<<' ';
    print(std::forward<Args>(args)...);
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

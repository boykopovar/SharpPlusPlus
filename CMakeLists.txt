cmake_minimum_required(VERSION 3.30)
project(SharpPlusPlus)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME}
        main.cpp
        cs/headers/LinkedList.h
        cs/src/LinkedList/linkedlist_include.h
        cs/src/LinkedList/LinkedListMethods.cpp
        #        cs/headers/BitArray.h
#        cs/src/BitArray/BitArrayOperators.cpp
#        cs/src/BitArray/BitArrayMethods.cpp
#        cs/src/BitArray/bitarray_include.h
)

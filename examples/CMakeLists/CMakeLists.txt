cmake_minimum_required(VERSION 3.30)
project(SharpPlusPlus)

set(CMAKE_CXX_STANDARD 17)

add_library(SharpPlusPlusLib STATIC cs/types.cpp)
target_include_directories(SharpPlusPlusLib PUBLIC ${CMAKE_SOURCE_DIR}/cs)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE SharpPlusPlusLib)

set_target_properties(SharpPlusPlusLib PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

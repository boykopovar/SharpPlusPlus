#ifndef GENERAL_TOOLS_H
#define GENERAL_TOOLS_H

#include <ostream>

template<typename T>
std::ostream& no_marks_list_out(std::ostream& out, const T& list);

template<typename T>
std::ostream& single_mark_list_out(std::ostream& out, const T& list);

long long IntPow(const long long base, const long long exp);

#include "../src/General/general_inc.h"

#endif //GENERAL_TOOLS_H

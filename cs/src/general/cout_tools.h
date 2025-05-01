#ifndef COUT_TOOLS_H
#define COUT_TOOLS_H

#include <ostream>

template<typename T>
std::ostream& no_marks_list_out(std::ostream& out, const T& list);

template<typename T>
std::ostream& single_mark_list_out(std::ostream& out, const T& list);

#endif //COUT_TOOLS_H

#include "cout_tools.h"


template<typename T>
std::ostream& no_marks_list_out(std::ostream& out, const T& list) {
    out<<'[';
    for(int i = 0; i < list.Size(); ++i) {
        out <<list[i];
        if (i!= list.Size()-1) out<< ',' << ' ';
    }
    return out << ']';
}


template<typename T>
std::ostream& single_mark_list_out(std::ostream& out, const T& list) {
    out<<'[';
    for(int i = 0; i < list.Size(); i++) {
        out << '\''<<list[i]<<'\'';
        if (i!= list.Size()-1) out<< ',' << ' ';
    }
    return out << ']';
}

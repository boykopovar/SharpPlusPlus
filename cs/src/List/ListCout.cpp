#include "../../headers/List.h"

template<typename T>
std::ostream& no_marks_list_out(std::ostream& out, const List<T>& list) {
    out<<'[';
    for(int i = 0; i < list.Size(); i++) {
        out <<list[i];
        if (i!= list.Size()-1) out<< ',' << ' ';
    }
    return out << ']';
}

template<typename T>
std::ostream& single_mark_list_out(std::ostream& out, const List<T>& list) {
    out<<'[';
    for(int i = 0; i < list.Size(); i++) {
        out << '\''<<list[i]<<'\'';
        if (i!= list.Size()-1) out<< ',' << ' ';
    }
    return out << ']';
}


inline std::ostream& operator<<(std::ostream &out, const List<long long>& list) { return no_marks_list_out(out, list); }
inline std::ostream& operator<<(std::ostream &out, const List<long>& list){ return no_marks_list_out(out, list); }

inline std::ostream& operator<<(std::ostream &out, const List<unsigned>& list){ return no_marks_list_out(out, list); }
inline std::ostream& operator<<(std::ostream &out, const List<int>& list){ return no_marks_list_out(out, list); }

inline std::ostream& operator<<(std::ostream &out, const List<unsigned short>& list) { return no_marks_list_out(out, list); }
inline std::ostream& operator<<(std::ostream &out, const List<short>& list) { return no_marks_list_out(out, list); }

inline std::ostream& operator<<(std::ostream &out, const List<long double>& list) { return no_marks_list_out(out, list); }
inline std::ostream& operator<<(std::ostream &out, const List<double>& list) { return no_marks_list_out(out, list); }

inline std::ostream& operator<<(std::ostream &out, const List<unsigned char>& list) {return single_mark_list_out(out, list); }
inline std::ostream& operator<<(std::ostream &out, const List<char>& list) {return single_mark_list_out(out, list); }
inline std::ostream& operator<<(std::ostream &out, const List<bool>& list) { return no_marks_list_out(out, list); }

template <typename U>
inline std::ostream& operator<<(std::ostream &out, const List<List<U>>& list) {return no_marks_list_out(out, list); }

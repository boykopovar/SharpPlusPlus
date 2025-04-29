#include "../../headers/List.h"


inline std::ostream& operator<<(std::ostream &out, const List<long long>& list) {
    out<<'[';
    for(int i = 0; i < list.Size(); i++) {
        out << list[i];
        if (i!= list.Size()-1) out<< ',' << ' ';
    }
    return out << ']';
}
inline std::ostream& operator<<(std::ostream &out, const List<long>& list) {
    out<<'[';
    for(int i = 0; i < list.Size(); i++) {
        out << list[i];
        if (i!= list.Size()-1) out<< ',' << ' ';
    }
    return out << ']';
}

inline std::ostream& operator<<(std::ostream &out, const List<unsigned>& list) {
    out<<'[';
    for(int i = 0; i < list.Size(); i++) {
        out <<list[i];
        if (i!= list.Size()-1) out<< ',' << ' ';
    }
    return out << ']';
}
inline std::ostream& operator<<(std::ostream &out, const List<int>& list) {
    out<<'[';
    for(int i = 0; i < list.Size(); i++) {
        out <<list[i];
        if (i!= list.Size()-1) out<< ',' << ' ';
    }
    return out << ']';
}

inline std::ostream& operator<<(std::ostream &out, const List<unsigned char>& list) {
    out<<'[';
    for(int i = 0; i < list.Size(); i++) {
        out << '\''<<list[i]<<'\'';
        if (i!= list.Size()-1) out<< ',' << ' ';
    }
    return out << ']';
}
inline std::ostream& operator<<(std::ostream &out, const List<char>& list) {
    out<<'[';
    for(int i = 0; i < list.Size(); i++) {
        out << '\''<<list[i]<<'\'';
        if (i!= list.Size()-1) out<< ',' << ' ';
    }
    return out << ']';
}

inline std::ostream& operator<<(std::ostream &out, const List<long double>& list) {
    out<<'[';
    for(int i = 0; i < list.Size(); i++) {
        out <<list[i];
        if (i!= list.Size()-1) out<< ',' << ' ';
    }
    return out << ']';
}
inline std::ostream& operator<<(std::ostream &out, const List<double>& list) {
    out<<'[';
    for(int i = 0; i < list.Size(); i++) {
        out <<list[i];
        if (i!= list.Size()-1) out<< ',' << ' ';
    }
    return out << ']';
}

template <typename U>
inline std::ostream& operator<<(std::ostream &out, const List<List<U>>& list) {
    out<<'[';
    for(int i = 0; i < list.Size(); i++) {
        out << list[i];
        if (i!= list.Size()-1) out<< ',' << ' ';
    }
    return out << ']';
}

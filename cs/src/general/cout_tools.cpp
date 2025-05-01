

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

inline long long IntPow(const long long base, const long long exp) {
    if (exp==0) return 1;
    if (exp==1) return base;
    return base * IntPow(base, exp-1);
}

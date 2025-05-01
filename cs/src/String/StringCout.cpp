

std::ostream& operator<<(std::ostream &out, const string &str) {
    const auto chars = str.c_str();
    out<<chars;
    delete[] chars;
    return out;
}

std::ostream& operator<<(std::ostream &out, const List<string>& list) {
    out<<'[';
    for(int i = 0; i < list.Size(); i++) {
        out << '\"'<<list[i]<< '\"';
        if (i!= list.Size()-1) out<< ',' << ' ';
    }
    return out << ']';
}


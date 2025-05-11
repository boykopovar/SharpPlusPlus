#ifndef PAIR_H
#define PAIR_H

template <typename T1, typename T2>
struct Pair {
    T1 Item1;
    T2 Item2;

    inline Pair() = default;
    inline Pair(T1 Item1, T2 Item2) : Item1(Item1), Item2(Item2) {}
    inline Pair(const Pair& other) : Item1(other.Item1), Item2(other.Item2) {}

    inline bool operator==(const Pair& other) const {return Item1 == other.Item1 && Item2 == other.Item2;}
    inline bool operator!=(const Pair& other) const {return !(*this == other);}
    inline bool operator<(const Pair& other) const {return Item1 < other.Item1;}
    inline bool operator>(const Pair& other) const {return Item1 > other.Item1;}

    inline bool operator<=(const Pair& other) const {return !(*this > other);}
    inline bool operator>=(const Pair& other) const {return !(*this < other);}
    friend inline std::ostream &operator<<(std::ostream &os, Pair<T1, T2> pair) {return os << '(' << pair.Item1 << ',' << ' ' << pair.Item2 << ')';}

};

namespace std {
    template<typename T1, typename T2>
    struct hash<Pair<T1, T2>> {
        unsigned long long operator()(const Pair<T1, T2>& pair) const noexcept {
            unsigned long long res_hash = 0;
            res_hash ^= std::hash<T1>()(pair.Item1) + 0x9e3779b9 + (res_hash << 6) + (res_hash >> 2);
            res_hash ^= std::hash<T2>()(pair.Item2) + 0x9e3779b9 + (res_hash << 6) + (res_hash >> 2);
            return res_hash;
        }
    };
}

#endif //PAIR_H

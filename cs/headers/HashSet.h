#ifndef HASHSET_H
#define HASHSET_H
#include "Dictionary.h"

template<typename ValueType>
class HashSet {
    public:
        HashSet() = default;
        HashSet(std::initializer_list<ValueType> init){for (const auto& item : init) this->Insert(item);}
        bool Contains(ValueType value) const{return this->_dict.ContainsKey(value);}
        void Insert(const ValueType& value){this->_dict[value] = true;}
        unsigned long long Size() const {return this->_dict.Size();}
        List<ValueType> ToList() const;
        void Clear() {this->_dict.Clear();}

        friend std::ostream& operator<<(std::ostream& os, HashSet<ValueType>& set) {return os << set.ToList();}

    private:
        Dictionary<ValueType, bool> _dict = Dictionary<ValueType, bool>();
};

#include "../src/HashSet/inc_hashset.h"

#endif //HASHSET_H

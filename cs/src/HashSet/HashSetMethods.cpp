

template<typename ValueType>
inline List<ValueType> HashSet<ValueType>::ToList() const {
    auto list_dict = this->_dict.ToList();
    List<ValueType> res_list(this->Size());
    for (unsigned long long i = 0; i < list_dict.Size(); ++i) {
        res_list.append(list_dict[i].Item1);
    }
    return res_list;
}


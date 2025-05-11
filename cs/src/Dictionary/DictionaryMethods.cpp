
template<typename KeyType, typename ValueType>
inline Dictionary<KeyType, ValueType>::Dictionary(std::initializer_list<Pair<KeyType, ValueType> > init) {
    for (auto i = init.begin(); i != init.end(); ++i) {
        (*this)[i->Item1] = i->Item2;
    }
}


template<typename KeyType, typename ValueType>
inline void Dictionary<KeyType, ValueType>::_insert(KeyType key, ValueType value) {
    if (this->_fullness() > 0.71) this->_rehash();
    auto target_bucket = this->_getHash(key);
    for (unsigned long long i = 0; i < this->_buckets[target_bucket].Size(); ++i) {
        if (this->_buckets[target_bucket][i].Item1 == key) {
            this->_buckets[target_bucket][i].Item2 = value;
            return;
        }
    }
    this->_buckets[target_bucket].append({key, value});
    ++this->_size;
}

template<typename KeyType, typename ValueType>
inline bool Dictionary<KeyType, ValueType>::ContainsKey(KeyType key) const {
    auto target_bucket = this->_getHash(key);
    for (unsigned long long i = 0; i < this->_buckets[target_bucket].Size(); ++i) {
        if (this->_buckets[target_bucket][i].Item1 == key) return true;
    }
    return false;
}

template<typename KeyType, typename ValueType>
inline ValueType Dictionary<KeyType, ValueType>::_get(const KeyType& key) const{
    auto target_bucket = this->_getHash(key);
    for (unsigned long long i = 0; i < this->_buckets[target_bucket].Size(); ++i) {
        if (this->_buckets[target_bucket][i].Item1 == key) return this->_buckets[target_bucket][i].Item2;
    }
    throw std::out_of_range("Key not found");
}

template<typename KeyType, typename ValueType>
inline ValueType& Dictionary<KeyType, ValueType>::_getExistingLink(KeyType& key) {
    auto target_bucket = this->_getHash(key);
    for (unsigned long long i = 0; i < this->_buckets[target_bucket].Size(); ++i) {
        if (this->_buckets[target_bucket][i].Item1 == key) return this->_buckets[target_bucket][i].Item2;
    }
    throw std::out_of_range("Key not found");
}

template<typename KeyType, typename ValueType>
inline ValueType& Dictionary<KeyType, ValueType>::_getLink(KeyType& key) {
    auto target_bucket = this->_getHash(key);
    for (unsigned long long i = 0; i < this->_buckets[target_bucket].Size(); ++i) {
        if (this->_buckets[target_bucket][i].Item1 == key) return this->_buckets[target_bucket][i].Item2;
    }
    this->_insert(key, ValueType());
    return this->_buckets[target_bucket][_buckets[target_bucket].Size()-1].Item2;
}

template<typename KeyType, typename ValueType>
inline void Dictionary<KeyType, ValueType>::_rehash() {
    //std::cout << "Проводится рехэширование. До рехеширования: " << this->_buckets << std::endl;
    auto new_size = this->_buckets.Size()*2;
    List<List<Pair<KeyType, ValueType>>> new_buckets = List<List<Pair<KeyType, ValueType>>>(new_size, true);
    for (unsigned long long i = 0; i < this->_buckets.Size(); ++i) {
        for (unsigned long long j = 0; j < this->_buckets[i].Size(); ++j) {
            new_buckets[this->_getHash(this->_buckets[i][j].Item1, new_size)].append({this->_buckets[i][j].Item1, this->_buckets[i][j].Item2});
        }
    }
    this->_buckets = new_buckets;
    //std::cout << "После рехеширования: " << this->_buckets << std::endl;
}

template<typename KeyType, typename ValueType>
inline bool Dictionary<KeyType, ValueType>::_isEqual(const Dictionary<KeyType, ValueType> &other) const {
    if (this->_buckets.Size() != other._buckets.Size()) return false;
    for (unsigned long long i = 0; i < this->_buckets.Size(); ++i) {
        if (this->_buckets[i] != other._buckets[i]) return false;
    }
    return true;
}


template<typename KeyType, typename ValueType>
inline List<Pair<KeyType, ValueType>> Dictionary<KeyType, ValueType>::ToList() const{
    List<Pair<KeyType, ValueType>> list(this->_buckets.Size());
    for (unsigned long long i = 0; i < this->_buckets.Size(); ++i) {
        for (unsigned long long j = 0; j < this->_buckets[i].Size(); ++j) {
            list.append(this->_buckets[i][j]);
        }
    }
    return list;
}



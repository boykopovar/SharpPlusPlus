#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "List.h"
#include "Pair.h"

template<typename KeyType, typename ValueType>
class Dictionary {
public:
    template <typename T>
    class DictValueProxy {
    public:
        DictValueProxy() = delete;
        DictValueProxy(DictValueProxy& other) = delete;
        DictValueProxy(Dictionary<KeyType, ValueType>* dict, KeyType key) : _dict(dict), _key(key) {}

        DictValueProxy& operator=(ValueType value) {_dict->_getLink(this->_key) = value; return *this;}
        DictValueProxy& operator=(const DictValueProxy& other) {_dict->_getLink(this->_key) = other._dict->_get(this->_key); return *this;}


        operator ValueType() {return _dict->_get(this->_key);}
        ValueType* operator->() {return &_dict->_getExistingLink(this->_key);}
        ValueType& operator*() {return _dict->_getExistingLink(this->_key);}

        bool operator==(const DictValueProxy &other) const {return this->_dict->_get(this->_key) == other._dict->_get(other._key);}
        bool operator==(T other) const {return this->_dict->_get(this->_key) == other;}
        friend bool operator==(const T& first, const DictValueProxy& second) {return first == second._dict->_get(second._key);}

        bool operator!=(DictValueProxy &other) const {return this->_dict->_get(this->_key) != other._dict->_get(other._key);}
        bool operator!=(T other) const {return this->_dict->_get(this->_key) != other;}
        friend bool operator!=(const T& first, const DictValueProxy& second) {return first != second._dict->_get(second._key);}

        bool operator>(DictValueProxy &other) const {return this->_dict->_get(this->_key) > other._dict->_get(other._key);}
        bool operator>(T other) const {return this->_dict->_get(this->_key) > other;}
        friend bool operator>(const T& first, const DictValueProxy& second) {return first > second._dict->_get(second._key);}

        bool operator<(DictValueProxy &other) const {return this->_dict->_get(this->_key) < other._dict->_get(other._key);}
        bool operator<(T other) const {return this->_dict->_get(this->_key) < other;}
        friend bool operator<(const T& first, const DictValueProxy& second) {return first < second._dict->_get(second._key);}

        bool operator>=(DictValueProxy &other) const {return this->_dict->_get(this->_key) >= other._dict->_get(other._key);}
        bool operator>=(T other) const {return this->_dict->_get(this->_key) >= other;}
        friend bool operator>=(const T& first, const DictValueProxy& second) {return first >= second._dict->_get(second._key);}

    private:
        Dictionary<KeyType, ValueType>* _dict;
        KeyType _key;
    };

    Dictionary() = default;
    Dictionary(std::initializer_list<Pair<KeyType, ValueType>> init);
    ~Dictionary() = default;


    [[nodiscard]] unsigned long long Size() const {return this->_size;}

    DictValueProxy<ValueType> operator[](KeyType key) {return DictValueProxy<ValueType>(this, key);}
    const ValueType& operator[](KeyType key) const {return this->_get(key);}
    bool operator==(const Dictionary &dict) const{return this->_isEqual(dict);}
    bool operator != (const Dictionary &dict) const {return !this->_isEqual(dict);}

    List<Pair<KeyType, ValueType>> ToList() const;
    bool ContainsKey(KeyType key) const;
    void Clear(){this->_size = 0; this->_buckets.Clear();}

    friend std::ostream& operator<<(std::ostream& os, const Dictionary<KeyType, ValueType>& dict) {return os<< dict.ToList();}
    [[nodiscard]] unsigned long long GetHash() const{return std::hash<List<List<Pair<KeyType, ValueType>>>>()(this->_buckets);}

private:


    void _rehash();
    unsigned long long _getHash(const KeyType& key, unsigned long long size = 0) const{return std::hash<KeyType>()(key)%(size == 0 ? this->_buckets.capacity() : size);};
    void _insert(KeyType key, ValueType value);
    ValueType _get(const KeyType& key) const;
    ValueType& _getExistingLink(KeyType& key);
    ValueType& _getLink(KeyType& key);
    [[nodiscard]] float _fullness() const {return static_cast<float>(this->_size) / static_cast<float>(this->_buckets.capacity());}

    bool _isEqual(const Dictionary<KeyType, ValueType>& other) const;

    unsigned long long _size = 0;
    List<List<Pair<KeyType, ValueType>>> _buckets = List<List<Pair<KeyType, ValueType>>>(16, true);
};

namespace std {
    template<typename KeyType, typename ValueType>
    struct hash<Dictionary<KeyType, ValueType>> {
        unsigned long long operator()(const Dictionary<KeyType, ValueType>& dict) const {return dict.GetHash();}
    };
}

#include "../src/Dictionary/dictionary_inc.h"

#endif //DICTIONARY_H

#ifndef SORTEDDICTIONARY_H
#define SORTEDDICTIONARY_H

#include "structs.h"
#include "List.h"
#include "Pair.h"



template <typename KeyType, typename T>
class SortedDictionary {

public:
    SortedDictionary() = default;
    ~SortedDictionary(){this->clear(root);};
    SortedDictionary(const SortedDictionary<KeyType, T> &) = delete;
    SortedDictionary<KeyType, T> &operator=(const SortedDictionary<KeyType, T> &) = delete;

    void Insert(KeyType key, const T& data){insert(root, key, data);};
    void Remove(KeyType key){this->root = remove(root, key);};
    T* Find(KeyType key);
    List<Pair<KeyType, T>> ToList()const {List<Pair<KeyType, T>> list; this->toList(root, list); return list;};

    void balance(BinaryNode<KeyType, T>* &node);
    void right_rotate(BinaryNode<KeyType, T>* &y);
    void left_rotate(BinaryNode<KeyType, T>* &x);
    long long height(BinaryNode<KeyType, T> *node);

    List<Pair<unsigned long long, unsigned long long>>CountNodes() const;
    friend std::ostream& operator<<(std::ostream& os, const SortedDictionary<KeyType, T> &dict) {return os << dict.ToList();}

private:
    BinaryNode<KeyType, T> *root = nullptr;

    void insert(BinaryNode<KeyType, T>* &node, KeyType key, const T& data);
    BinaryNode<KeyType, T>* remove(BinaryNode<KeyType, T> *node, KeyType key);
    BinaryNode<KeyType, T>* search(BinaryNode<KeyType, T> *node, KeyType key);
    void clear(BinaryNode<KeyType, T> *node);
    void toList(BinaryNode<KeyType, T> *node, List<Pair<KeyType, T>> &list) const;


};

#include "../src/SortedDictionary/sorteddictionary_include.h"

#endif //SORTEDDICTIONARY_H

// #include "../../headers/SortedDictionary.h"


template<typename KeyType, typename T>
inline void SortedDictionary<KeyType, T>::insert(BinaryNode<KeyType, T> *&node, KeyType key, const T &data) {
    if (!node) {
        node = new BinaryNode<KeyType, T>{key, data, nullptr, nullptr};
        return;
    }

    if (key < node->key) this->insert(node->left, key, data);
    else if (key > node->key) this->insert(node->right, key, data);
    else node->data = data;

    this->balance(node);
}


template<typename KeyType, typename T>
inline BinaryNode<KeyType, T> *SortedDictionary<KeyType, T>::remove(BinaryNode<KeyType, T> *node, KeyType key) {
    if (!node) return nullptr;

    if (key < node->key) node->left = this->remove(node->left, key);
    else if (key > node->key) node->right = this->remove(node->right, key);
    else {
        if (!node->left) {
            BinaryNode<KeyType, T>* right_child = node->right;
            delete node;
            return right_child;
        }
        if (!node->right) {
            BinaryNode<KeyType, T>* left_child = node->left;
            delete node;
            return left_child;
        }

        // два потомка
        BinaryNode<KeyType, T> * min_node = node->right;
        while (min_node && min_node->left)min_node = min_node->left;
        node->key = min_node->key;
        node->data = min_node->data;
        node->right = remove(node->right, min_node->key);
    }
    return node;
}

template<typename KeyType, typename T>
inline BinaryNode<KeyType, T>* SortedDictionary<KeyType, T>::search(BinaryNode<KeyType, T> *node, KeyType key) {
    if (!node) return nullptr;
    if (key < node->key) return search(node->left, key);
    if (key > node->key) return search(node->right, key);
    return node;
}

template<typename KeyType, typename T>
inline void SortedDictionary<KeyType, T>::toList(BinaryNode<KeyType, T> *node, List<Pair<KeyType, T> > &list) const {
    if (!node) return;
    toList(node->left, list);
    list.append(Pair<KeyType, T>(node->key, node->data));
    toList(node->right, list);
}

template<typename KeyType, typename T>
inline T *SortedDictionary<KeyType, T>::Find(KeyType key) {
    BinaryNode<KeyType, T> *res_node = this->search(root, key);
    return res_node ? &res_node->data : nullptr;
}

template<typename KeyType, typename T>
inline void SortedDictionary<KeyType, T>::clear(BinaryNode<KeyType, T> *node) {
    if (!node) return;
    clear(node->left);
    clear(node->right);
    delete node;
}

template<typename KeyType, typename T>
inline List<Pair<unsigned long long, unsigned long long> > SortedDictionary<KeyType, T>::CountNodes() const {
    List<Pair<unsigned long long, unsigned long long> > result;
    if (root == nullptr) return result;

    Queue<BinaryNode<KeyType, T> *> q;
    q.Enqueue(root);

    unsigned long long level = 0;
    while (!q.IsEmpty()) {
        const unsigned long long level_size = q.Size();
        result.append(Pair<unsigned long long, unsigned long long>(level, level_size));

        for (unsigned long i = 0; i < level_size; i++) {
            BinaryNode<KeyType, T> *node = q.Dequeue();

            if (node->left) q.Enqueue(node->left);
            if (node->right) q.Enqueue(node->right);
        }
        ++level;
    }
    return result;
}

template<typename KeyType, typename T>
inline void SortedDictionary<KeyType, T>::balance(BinaryNode<KeyType, T>* &node) {
    long long balance_factor = height(node->left) - height(node->right);

    if (balance_factor > 1) {
        if (height(node->left) >= height(node->right)) this->right_rotate(node);
        else {
            this->left_rotate(node->left);
            this->right_rotate(node);
        }
    }
    else if (balance_factor < -1) {
        if (height(node->right->right) >= height(node->right->left)) {
            this->left_rotate(node);
        }
        else {
            this->right_rotate(node->right);
            this->left_rotate(node);
        }
    }
}

template<typename KeyType, typename T>
inline long long SortedDictionary<KeyType, T>::height(BinaryNode<KeyType, T> *node) {
    if (!node) return 0;
    return 1 + std::max(height(node->left), height(node->right));
}

template<typename KeyType, typename T>
inline void SortedDictionary<KeyType, T>::right_rotate(BinaryNode<KeyType, T>* &y) {
    BinaryNode<KeyType, T> *x = y->left;
    BinaryNode<KeyType, T> *T2 = x->right;

    x->right = y;
    y->left = T2;
    y = x;
}

template<typename KeyType, typename T>
inline void SortedDictionary<KeyType, T>::left_rotate(BinaryNode<KeyType, T>* &x) {
    BinaryNode<KeyType, T> *y = x->right;
    BinaryNode<KeyType, T> *T2 = y->left;

    y->left = x;
    x->right = T2;
    x = y;
}













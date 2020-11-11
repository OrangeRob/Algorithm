#ifndef __BINARYSEARCHTREE_H__
#define __BINARYSEARCHTREE_H__

template<typename Key, typename Value>
class BinarySearchTree {
private:
    struct Node {
        Key key;
        Value value;
        Node* left;
        Node* right;

        Node(Key key, Value value) {
            this->key = key;
            this->value = value;
            this->left = nullptr;
            this->right = nullptr;
        }
    };

    Node* root;
    int count;

public:
    BinarySearchTree() {
        root = nullptr;
        count = 0;
    }

    ~BinarySearchTree() {
        // TODO:
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    void insert(Key key, Value value) {
        root = _insert(root, key, value);
    }

    bool contain(Key key) {
        return _contain(root, key);
    }

    Value* search(Key key) {
        return _search(root, key);
    }

private:
    Node* _insert(Node* node, Key key, Value value) {
        if(node == nullptr) {
            count++;
            return new Node(key, value);
        }

        if(key > node->key)
            node->right = _insert(node->right, key, value);
        else if(key < node->key)
            node->left = _insert(node->left, key, value);
        else
            node->value = value;

        return node;
    }

    bool _contain(Node* node, Key key) {
        if(node == nullptr)
            return false;

        if(key > node->key)
            return _contain(node->right, key);
        else if(key < node->key)
            return _contain(node->left, key);
        else
            return true;
    }

    Value* _search(Node* node, Key key) {
        if(node == nullptr)
            return nullptr;

        if(key > node->key)
            return _search(node->right, key);
        else if(key < node->key)
            return _search(node->left, key);
        else
            return &(node->value);
    }
};

#endif //__BINARYSEARCHTREE_H__

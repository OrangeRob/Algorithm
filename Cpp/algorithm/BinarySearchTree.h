#ifndef __BINARYSEARCHTREE_H__
#define __BINARYSEARCHTREE_H__

template<typename Key, typename Value>
class BST {
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
    BST() {
        root = nullptr;
        count = 0;
    }

    ~BST() {
        // TODO:
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    void insert(Key key, Value value) {
        root = insert(root, key, value);
    }

private:
    Node* insert(Node* node, Key key, Value value) {
        if(node == nullptr) {
            count++;
            return new Node(key, value);
        }

        if(key == node->key)
            node->value = value;
        else if(key < node->key)
            node->left = insert(node->left, key, value);
        else
            node->right = insert(node->right, key, value);

        return node;
    }
};

#endif //__BINARYSEARCHTREE_H__

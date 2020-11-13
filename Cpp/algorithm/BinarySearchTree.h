#ifndef __BINARYSEARCHTREE_H__
#define __BINARYSEARCHTREE_H__

#include <queue>

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

private:
    Node* root;
    int count;

public:
    BinarySearchTree() {
        root = nullptr;
        count = 0;
    }

    ~BinarySearchTree() {
        // TODO:
        destroy(root);
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    void insert(Key key, Value value) {
        root = __insert(root, key, value);
    }

    bool contain(Key key) {
        return __contain(root, key);
    }

    Value* search(Key key) {
        return __search(root, key);
    }

    void preOrder() {
        __preOrder(root);
    }

    void inOrder() {
        __inOrder(root);
    }

    void postOrder() {
        __postOrder(root);
    }

    void levelOrder() {
        std::queue<Node *> q;
        q.push(root);
        while(!q.empty()) {
            Node* node = q.front();
            q.pop();

            std::cout << node->key << std::endl;
            if(node->left != nullptr)
                q.push(node->left);
            if(node->right != nullptr)
                q.push(node->right);
        }
    }

private:
    Node* __insert(Node* node, Key key, Value value) {
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

    bool __contain(Node* node, Key key) {
        if(node == nullptr)
            return false;

        if(key > node->key)
            return _contain(node->right, key);
        else if(key < node->key)
            return _contain(node->left, key);
        else
            return true;
    }

    Value* __search(Node* node, Key key) {
        if(node == nullptr)
            return nullptr;

        if(key > node->key)
            return _search(node->right, key);
        else if(key < node->key)
            return _search(node->left, key);
        else
            return &(node->value);
    }

    void __preOrder(Node* node) {
        if(node != nullptr) {
            std::cout << node->key << std::endl;
            __preOrder(node->left);
            __preOrder(node->right);
        }
    }

    void __inOrder(Node* node) {
        if(node != nullptr) {
            __inOrder(node->left);
            std::cout << node->key << std::endl;
            __inOrder(node->right);
        }
    }

    void __postOrder(Node* node) {
        if(node != nullptr) {
            __postOrder(node->left);
            __postOrder(node->right);
            std::cout << node->key << std::endl;
        }
    }

    void __destroy(Node* node) {
        if(node != nullptr) {
            __destroy(node->left);
            __destroy(node->right);
            delete node;
            count--;
        }
    }
};

#endif //__BINARYSEARCHTREE_H__

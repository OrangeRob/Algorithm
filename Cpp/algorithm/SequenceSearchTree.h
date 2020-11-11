#ifndef __SEQUENCESEARCHTREE_H__
#define __SEQUENCESEARCHTREE_H__

template<typename Key, typename Value>
class SequenceSearchTree {
private:
    struct Node {
        Key key;
        Value value;
        Node* next;

        Node(Key key, Value value) {
            this->key = key;
            this->value = value;
            this->next = nullptr;
        }
    };

private:
    Node* head;
    int count;

public:
    SequenceSearchTree() {
        head = nullptr;
        count = 0;
    }

    ~SequenceSearchTree(){
        while(head != nullptr) {
            Node *delNode = head;
            head = head->next;
            delete delNode;
            count--;
        }

        assert( head == nullptr && count == 0 );
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    void insert(Key key, Value value) {
        Node* node = head;
        while(node != nullptr) {
            if(node->key == key) {
                node->value = value;
                return;
            }
            node = node->next;
        }

        Node* newNode = new Node(key, value);
        newNode->next = head;
        head = newNode;
        count++;
    }

    bool contain(Key key) {
        Node* node = head;
        while(node != nullptr) {
            if(node->key == key)
                return true;

            node = node->next;
        }
        return false;
    }

    Value* search(Key key) {
        Node* node = head;
        while(node != nullptr) {
            if(node->key == key)
                return &(node->value);

            node = node->next;
        }
        return nullptr;
    }
};

#endif //__SEQUENCESEARCHTREE_H__

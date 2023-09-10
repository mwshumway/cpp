#pragma once
#include <iostream>

template<class T>
class BST {
public:
    struct Node {
        Node* left;
        Node* right;
        T value;

        Node(T v) : left(nullptr), right(nullptr), value(v) {}
    };
private:
    Node* root;
    int Size;
public:
    BST() {
        root = nullptr;
        Size = 0;
    }

    ~BST() {
        root = nullptr;
    }

    const Node* getRootNode() const {
        return root;
    }

    bool _insert(Node*& node, T item) {
        if (item < node->value) {
            if(node->left != nullptr){
                _insert(node->left, item);
            }
            else{
                Node *newNode = new Node(item);
                node->left = newNode;
            }
        }
        else {
            if (node->right != nullptr) {
                _insert(node->right, item);
            }
            else {
                Node *newNode = new Node(item);
                node->right = newNode;
            }
        }
        return true;
    }

    bool insert(T item) {
        // return true if item was inserted, false if item was already in the tree
        if (root == nullptr) {
            Node* node = new Node(item);
            root = node;
            Size++;
            return true;
        }

        if (contains(item)) {
            return false;
        }
        Size++;
        return _insert(root, item);
    }

    bool _remove(Node* &node, T item) {
        if (item < node->value) {
            return _remove(node->left, item);
        }
        else if (item > node->value) {
            return _remove(node->right, item);
        }
        else {
            // case 1: no children
            if ((node->left == nullptr) && (node->right == nullptr)) {
                delete node;
                node = nullptr;
            }
            else if ((node->left == nullptr) || (node->right == nullptr)) {
                Node* temp = node;
                if (node->left == nullptr) {
                    node = temp->right;
                }
                else {
                    node = temp->left;
                }
                delete temp;
            }
            else {
                Node* temp = node->left;
                while (temp->right != nullptr) {
                    temp = temp->right;
                }
                node->value = temp->value;
                _remove(node->left, node->value);
            }
            return true;
        }
    }

    bool remove(T item) {
        // return true if item was removed, false if item wasn't in the tree
        if (!contains(item)) {
            return false;
        }
        Size--;
        return _remove(root, item);
    }
    bool find(Node* node, int item) const {
        // return true if item is in the subtree, false otherwise
        if (node == nullptr) {
            return false;
        }
        else if (node->value == item) {
            return true;
        }
        else if (item < node->value) {
            return find(node->left, item);
        }
        else {
            return find(node->right, item);
        }
    }

    bool contains (T item) const{
        // return true if item is in the tree, false otherwise
        return find(this->root, item);
    }

    void clear() {
        // remove all nodes from the tree
        root = nullptr;
        Size = 0;
    }

    int size() const {
        // return the number of nodes in the tree
        return Size;
    }
};

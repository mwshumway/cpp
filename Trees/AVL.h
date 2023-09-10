#pragma once
#include <iostream>

template<class T>
class AVL {
public:
    struct Node {
        Node* left;
        Node* right;
        T value;
        int height;

        Node(T v) : left(nullptr), right(nullptr), value(v), height(1) {}
    };
private:
    Node* root;
    int Size;
public:

    AVL() {
        root = nullptr;
        Size = 0;
    }

    ~AVL() {
        root = nullptr;
    }

    const Node* getRootNode() const {
        // implement getRootNode here
        // return a pointer to the tree's root node
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
        rebalance(node);
        return true;
    }

    bool insert(T item) {
        // implement insert here
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
            bool isRemoved = _remove(node->left, item);
            if (isRemoved) {
                rebalance(node);
            }
            return isRemoved;
        }
        else if (item > node->value) {
            bool isRemoved = _remove(node->right, item);
            if (isRemoved) {
                rebalance(node);
            }
            return isRemoved;
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
                rebalance(node);
            }
            return true;
        }
    }

    bool remove(T item) {
        // implement remove here
        // return true if item was removed, false if item wasn't in the tree
        if (!contains(item)) {
            return false;
        }
        Size--;
        return _remove(root, item);
    }
    bool find(Node* node, int item) const {
        // implement find here
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

    bool contains(T item) const {
        // implement contains here
        // return true if item is in the tree, false otherwise
        return find(root, item);
    }

    void clear() {
        // implement clear here
        // remove all nodes from the tree
        root = nullptr;
        Size = 0;
    }

    int size() const {
        // implement size here
        // return the number of nodes in the tree
        return Size;
    }

    int calculate_height(Node* node) {
        // base case
        if (node == nullptr) {
            return 0;
        }
        else {
            int left = calculate_height(node->left);
            int right = calculate_height(node->right);
            int max;
            max = std::max(left, right);
            return max + 1;
        }
    }

    int calculate_difference(Node* node) {
        int left = calculate_height(node->left);
        int right = calculate_height(node->right);
        return left-right;
    }

    void promote_left(Node*& node) {
        Node* temp = node->left;
        node->left = temp->right;
        temp->right = node;
        node = temp;
        node->height = calculate_height(node);
        node->right->height = calculate_height(node->right);
    }

    void promote_right(Node*& node) {
        Node* temp = node->right;
        node->right = temp->left;
        temp->left = node;
        node = temp;
        node->height = calculate_height(node);
        node->left->height = calculate_height(node->left);
    }

    void rebalance(Node*& node) {
        // implement rebalance here
        if (calculate_difference(node) > 1) {
            // left is heavy
            if (calculate_difference(node->left) < 0) {
                promote_right(node->left);
                update_height(node->left);
                promote_left(node);
                update_height(node);
            }
            else {
                promote_left(node);
                update_height(node);
            }
        }
        else if (calculate_difference(node) < -1) {
            // right is heavy
            if (calculate_difference(node->right) > 0) {
                promote_left(node->right);
                update_height(node->right);
                promote_right(node);
                update_height(node);
            }
            else {
                promote_right(node);
                update_height(node);
            }
        }
        else {
//            node->height = calculate_height(node);
            update_height(root);

        }
    }

    void update_height (Node* node) {
        if (node == nullptr) {
            return;
        }
        else {
            update_height(node->left);
            update_height(node->right);

            node->height = calculate_height(node);
        }
    }
};
#pragma once
#include <iostream>

struct Node {
    Node* left;
    Node* right;
    int value;

    Node(int v) : left(nullptr), right(nullptr), value(v) {}
};

bool find(Node* root, int item) {
    // implement find here
    // return true if item is in the subtree, false otherwise
    if (root == nullptr) {
        return false;
    }
    else if (root->value == item) {
        return true;
    }
    else if (item < root->value) {
        return find(root->left, item);
    }
    else {
        return find(root->right, item);
    }
}

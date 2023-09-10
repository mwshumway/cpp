#pragma once
#include <iostream>

struct Node {
    Node* left;
    Node* right;
    int value;
    int height;

    Node(int v) : left(nullptr), right(nullptr), value(v), height(1) {}
};

// Hint: you might find it helpful to write an update_height function that takes
// a Node* and updates its height field based on the heights of its children

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

void promote_left(Node*& root) {
    Node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    root = temp;
    root->height = calculate_height(root);
    root->right->height = calculate_height(root->right);
}

void promote_right(Node*& root) {
    Node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    root = temp;
    root->height = calculate_height(root);
    root->left->height = calculate_height(root->left);
}

void rebalance(Node*& root) {
    // implement rebalance here
    if (calculate_difference(root) > 1) {
        // left is heavy
        if (calculate_difference(root->left) < 0) {
            promote_right(root->left);
            promote_left(root);
        }
        else {
            promote_left(root);
        }
    }
    if (calculate_difference(root) < -1) {
        // right is heavy
        if (calculate_difference(root->right) > 0) {
            promote_left(root->right);
            promote_right(root);
        }
        else {
            promote_right(root);
        }
    }
}

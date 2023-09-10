#pragma once
#include <iostream>


template <class T>
class SLList {
public:
    struct Node {
        Node* next;
        T value;

        Node(T v) : next(nullptr), value(v) {}
    };

    SLList() : first(nullptr), size_LL(0) {}

    ~SLList() {
        this->clear();
    }

    const Node* get_head() const {
        if (first == nullptr) {
            return nullptr;
        }
        else {
            return first;
        }
    }

    void push_back(T item) {
        // case 1: ll is empty
        if (first == nullptr) {
            Node* addMe = new Node(item);
            first = addMe;
            size_LL++;
        }
            // case 2: ll is not empty
        else {
            Node* temp = first;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            Node* addMe = new Node(item);
            temp->next = addMe;
            size_LL++;
        }
    }

    void pop_back() {
        Node* temp = first;
        // case 1: ll is empty
        if (first == nullptr) return;
            // case 2: length of ll >= 2
        else if (temp->next) {
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
            size_LL--;
        }
            // case 3: length of ll == 1
        else {
            delete temp;
            first = nullptr;
            size_LL--;
        }
    }

    const T& front() const {
        // For this method, we assume that the LL is not empty
        if (first == nullptr) {
            throw std::runtime_error("Linked List is empty.");
        }
        else{
            return first->value;
        }
    }

    int size() const {
        return size_LL;
    }

    void clear() {
        while (first != nullptr) {
            Node* temp = first->next;
            delete first;
            first = temp;
        }
        size_LL = 0;
    }

private:
    Node* first;
    size_t size_LL;
};

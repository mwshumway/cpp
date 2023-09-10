#pragma once
#include <iostream>

#include <iostream>
#include <string>

template<class T>
class DLList {
public:
    struct Node {
        Node* prev;
        Node* next;
        T value;

        Node(T v) : prev(nullptr), next(nullptr), value(v) {}
    };
private:
    size_t sizeLL;
    Node* first;

public:

    DLList() : sizeLL(0), first(nullptr) {}

    ~DLList() {
        this->clear();
    }

    const Node* get_head() const {return first;}

    void push_front(T item) {
        Node* addMe = new Node(item);
        // case 1: list is empty
        if (first == nullptr) {
            first = addMe;
        }
            // case 2: list has at least one non-null element
        else {
            addMe->next = first;
            first->prev = addMe;
            first = addMe;
        }
        sizeLL++;
    }

    void push_back(T item) {
        Node* addMe = new Node(item);
        // case 1: list is empty
        if (first == nullptr) {
            first = addMe;
        }
            // case 2: list is nonempty
        else {
            Node* temp = first;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            // temp now points to last element in list
            temp->next = addMe;
            addMe->prev = temp;
        }
        sizeLL++;
    }

    void insert(T item, int position) {

        if (position > sizeLL) {
            throw std::out_of_range("index is out of range");
        }
        else {
            Node* addMe = new Node(item);
            if (sizeLL == 0 && position == 0) {
                first = addMe;
                sizeLL++;
            }
            else {
                sizeLL++;
                int count = 0;
                Node* temp = first;
                while (count < position) {
                    count++;
                    temp = temp->next;
                }
                // temp now points to node at position

                // if adding to the end of the list, temp will point at null
                if (temp == nullptr) {
                    int c = 0;
                    Node* temp2 = first;
                    while (c < position - 1) {
                        c++;
                        temp2 = temp2->next;
                    }
                    // temp now points to node just before position
                    temp2->next = addMe;
                    addMe->prev = temp2;
                }
                else {

                    addMe->prev = temp->prev;
                    temp->prev = addMe;
                    addMe->next = temp;
                    if (addMe->prev) {
                        addMe->prev->next = addMe;
                    }
                    else {
                        first = addMe;
                    }
                }
            }
        }
    }

    void pop_front() {
        // need new first to be current first->next
        if (sizeLL == 0) {
            throw std::length_error("List is empty");
        }
        else if (sizeLL == 1) {
            delete first;
            sizeLL--;
        }
        else {
            // length 2 or more
            Node* temp = first;
            first = first->next;
            first->prev = nullptr;
            delete temp;
            sizeLL--;
        }
    }
    void pop_back() {
        if (sizeLL == 0) {
            throw std::length_error("List is empty");
        }
        else if (sizeLL == 1) {
            delete first;
            sizeLL--;
        }
        else {
            // length 2 or more
            Node* temp = first;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            // temp points at last in list
            temp->prev->next = nullptr;
            delete temp;
            sizeLL--;
        }
    }
    void remove(int position) {
        // check if position is out of range
        if (position >= sizeLL) {
            throw std::out_of_range("index is out of range");
        }
        else if (position == 0) {
            Node* temp = first;
            first = temp->next;
            if (first) {
                first->prev = nullptr;
            }
            delete temp;
            sizeLL--;
        }
        else {
            int count = 0;
            Node* temp = first;
            while (count < position) {
                temp = temp->next;
                count++;
            }
            // temp now points to node at position
            temp->prev->next = temp->next;
            if (temp->next) {
                temp->next->prev = temp->prev;
            }
            delete temp;
            sizeLL--;
        }
    }

    const T& front() const {
        if (!sizeLL) {
            throw std::length_error("List is empty");
        }
        else {
            return first->value;
        }
    }
    const T& back() const {
        if (!sizeLL) {
            throw std::length_error("List is empty");
        }
        else {
            Node* temp = first;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            return temp->value;
        }
    }
    const T& at(int index) const {
        if (index >= sizeLL) {
            throw std::out_of_range("Index out of range");
        }
        else {
            int count = 0;
            Node* temp = first;
            while (count < index) {
                count++;
                temp = temp->next;
            }
            return temp->value;
        }
    }

    bool contains(const T& item) const {
        if (!sizeLL) {
            return false;
        }
        else {
            const Node* temp = first;
            while (temp != nullptr) {
                if (temp->value == item) {
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }
    }

    int size() const {
        return sizeLL;
    }

    void clear() {
        Node* temp = first;
        while (temp != nullptr) {
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
        sizeLL = 0;
    }
};
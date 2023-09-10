#pragma once
#include <iostream>
#include <functional>
#include <string>

const size_t INITIAL_BUCKETS = 10;
const size_t GROW_FACTOR = 2;
const double MAX_LOAD_FACTOR = 0.8;


template<class T>
class HashSet {
private:
    class Node {
    public:
        size_t key;
        T value;
        Node* next;

        Node(size_t key, T value) {
            this->key = key;
            this->value = value;
            this->next = nullptr;
        };
    };
    Node** hashArr = new Node*[INITIAL_BUCKETS];
    int size_ = 0;
    int capacity = INITIAL_BUCKETS;


public:
    HashSet() {
        size_ = 0;
        capacity = INITIAL_BUCKETS;
        for (int i = 0; i < INITIAL_BUCKETS; i++) {
            hashArr[i] = nullptr;
        }
    }

    ~HashSet() {
        clear();
    }

    bool insert(T item) {
        // implement insert here
        // return true if item was inserted, false if item was already in the set
        if (contains(item)) {
            return false;
        }
        else {
            std::size_t hashcode = std::hash<T>()(item) % capacity;
            Node* temp = hashArr[hashcode];
            if (temp == nullptr) {
                hashArr[hashcode] = new Node(hashcode, item);
            }
            else {
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = new Node(hashcode, item);
            }
            size_++;
            return true;
        }
    }

    bool remove(T item) {
        // implement remove here
        // return true if item was removed, false if item wasn't in the set
        // case 1: item not in the map
        if (!contains(item)) {
            return false;
        }
        std::size_t code = std::hash<T>()(item) % capacity;
        Node* temp = hashArr[code];
        size_--;
        // case 2: first node found in the array contains the item
        if (temp->value == item) {
            if (temp->next == nullptr) {
                hashArr[code] = nullptr;
                delete temp;
            } else {
                hashArr[code] = temp->next;
                delete temp;
            }
            return true;
        }

        // case 3: item is found beyond that
        while (temp->next != nullptr) {
            if (temp->next->value == item) {
                if (temp->next->next == nullptr) {
                    delete temp->next;
                    temp->next = nullptr;
                } else {
                    delete temp->next;
                    temp->next = temp->next->next;
                }
                return true;
            }
        }
    }

    bool contains(T item) const {
        // implement contains here
        // return true if item is in the set, false otherwise
        size_t code = std::hash<T>()(item) % capacity;
        Node* temp = hashArr[code];
        while (temp != nullptr) {
            if (temp->value == item) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void clear() {
        // implement clear here
        // remove all elements from the set
        for(int i = 0; i < capacity; i ++){
            Node*tempPtr = hashArr[i];
            while(tempPtr != nullptr){
                remove(tempPtr->value);
                tempPtr = tempPtr->next;

            }
        }
        size_ = 0;
    }

    int size() const {
        // implement size here
        // return the number of elements in the set
        return size_;
    }
};

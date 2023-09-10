#pragma once

#include <iostream>
#include <string>

using namespace std;

template<class T>
class Vector {
public:
    class Iterator {
    private:
        T* ptr;
    public:
        Iterator(T* p) {
            ptr = p;
        }

        ~Iterator() {
            ptr = nullptr;
        }

        T& operator*() {
            return *ptr;
        }

        Iterator& operator++() {
            this->ptr++;
            return *this;
        }

        bool operator==(const Iterator& other) const {
            return *ptr == other->ptr;
        }

        bool operator!=(const Iterator& other) const {
            return ptr != other.ptr;
        }
    };

    Iterator begin() {
        return Iterator(vectArr);
    }

    Iterator end() {
        return Iterator(vectArr + vectorSize);
    }

    Vector() : vectorSize(0), capacity(20), vectArr(new T[capacity]) {}

    ~Vector() {
        delete[] vectArr;
    }

    void push_back(T item) {
        vectArr[vectorSize] = item;
        vectorSize++;
    }

    void insert(T item, int position) {
        if (position > vectorSize) {
            throw out_of_range("index out of range");
        }
        for (int i = vectorSize; i > position; i--) {
            vectArr[i] = vectArr[i-1];
        }
        vectArr[position] = item;
        vectorSize++;
    }

    void remove(int position) {
        // start at position
        // vector[pos] = vector[pos + 1]
        if (position >= vectorSize) {
            throw out_of_range("index out of range");
        }
        for (int i = position; i < vectorSize; i++) {
            vectArr[i] = vectArr[i+1];
        }
        vectorSize--;
    }

    T& operator[](int index) {
        if (index >= vectorSize) {
            throw out_of_range("index out of range");
        }
        else {
            return vectArr[index];
        }
    }

    int size() const {
        return vectorSize;
    }

    void clear() {
        vectorSize = 0;
    }
private:
    size_t vectorSize;
    size_t capacity;
    T* vectArr;
};

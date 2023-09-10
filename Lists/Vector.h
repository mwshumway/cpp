#pragma once

#include <iostream>
#include <string>

using namespace std;


template<class T>
class Vector {
private:
    size_t vectorSize;
    size_t capacity;
    T* vectArr;

public:
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
};

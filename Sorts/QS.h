#pragma once

#include <vector>
#include <iostream>

template<class T>
int medianOfThree(std::vector<T>& array, int left, int right) {

    int middleIndex = (left + right) / 2;

    if (array[left] > array[middleIndex]) {
        std::swap(array[left], array[middleIndex]);
    }
    if (array[left] > array[right]) {
        std::swap(array[left], array[right]);
    }
    if (array[middleIndex] > array[right]) {
        std::swap(array[middleIndex], array[right]);
    }
    return middleIndex;
}

template<class T>
int partition(std::vector<T>& array, int left, int right) {
    int pivotIndex = medianOfThree(array, left, right);
    std::swap(array[left], array[pivotIndex]);
    pivotIndex = left;
    int up = left + 1;
    int down = right;
    do {
        while ((array[up] <= array[pivotIndex]) && (up <= down)) {
            up ++;
        }
        while ((array[down] > array[pivotIndex]) && (down >= up)) {
            down --;
        }
        if (up < down) {
            std::swap(array[up], array[down]);
        }
    } while (up < down);

    std::swap(array[left], array[down]);
    return down;
}

template<class T>
void _sort(std::vector<T>& array, int left, int right) {
    if (left < right) {
        int newIndex = partition(array, left, right);

        _sort(array, left, newIndex - 1);
        _sort(array, newIndex + 1, right);
    }
}

template<class T>
void sort(std::vector<T>& array) {
    // implement sort here
    // hint: you'll probably want to make a recursive sort_helper function
    _sort(array, 0, array.size() - 1);
}

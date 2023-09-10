#pragma once

#include <vector>

template<class T>
class VectorSet {
private:
    std::vector<T> data;
public:
    bool contains(T item) const {
        // implement contains here
        for (const T& element : data) {
            if (element == item) {
                return true;
            }
        }
        return false;
        // return true if item is in the set and false if not
    }

    bool insert(T item) {
        // implement insert here
        if (contains(item)) {
            return false;
        }
        else {
            data.push_back(item);
            return true;
        }
        // return true if item is inserted and false if item is already in the
        // set
    }

    bool remove(T item) {
        // implement remove here
        if (!contains(item)) {
            return false;
        }
        else {
            int pos;
            for (int i = 0; i < data.size(); i++) {
                if (data[i] == item) {
                    pos = i;
                }
            }
            data.erase(data.begin() + pos);
            return true;
        }

        // return true if item is removed and false if item wasn't in the set
    }

    int size() const {
        // implement size here
        return data.size();
        // return the number of items in the set
    }

    bool empty() const {
        // implement empty here
        if (!data.size()) {
            return true;
        }
        else {
            return false;
        }
        // return true if the set is empty and return false otherwise
    }

    void clear() {
        // implement clear here
        data.clear();
        // remove all items from the set
    }
};


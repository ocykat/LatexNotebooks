#pragma once

#include <iostream>
#include "array-list.h"
#include "../util/util.h"

template <typename Key>
class Heap {
private:
    ArrayList<Key> keys;

    int getParent(int i) {
        return (i - 1) / 2;
    }

    int getLeft(int i) {
        return i * 2 + 1;
    }

    int getRight(int i) {
        return i * 2 + 2;
    }

    void swapKeys(int i, int j) {
        util::swap(keys[i], keys[j]);
    }

    void heapify(int i) {
        int smallest = i;
        int left = getLeft(i);
        int right = getRight(i);
        if (left < keys.getSize() && keys[left] < keys[smallest]) {
            smallest = left;
        }
        if (right < keys.getSize() && keys[right] < keys[smallest]) {
            smallest = right;
        }
        if (smallest != i) {
            swapKeys(i, smallest);
            heapify(smallest);
        }
    }

public:
    bool isEmpty() {
        return keys.getSize() == 0;
    }

    void buildHeap(Key* a, int n) {
        for (int i = 0; i < n; i++) {
            keys.pushBack(a[i]);
        }
        for (int i = keys.getSize() / 2; i > -1; i--) {
            heapify(i);
        }
    }

    void push(Key key) {
        keys.pushBack(key);
        int i = keys.getSize() - 1;
        int parent = getParent(i);
        while (i > 0 && keys[i] < keys[parent]) {
            swapKeys(i, parent);
            i = parent;
            parent = getParent(i);
        }
    }

    Key pop() {
        assert(keys.getSize() > 0 && "Heap::top(): heap is empty");
        int top = keys[0];
        keys[0] = keys[keys.getSize() - 1];
        keys.popBack();
        heapify(0);
        return top;
    }

    Key top() {
        assert(keys.getSize() > 0 && "Heap::top(): heap is empty");
        return keys[0];
    }

    friend std::ostream& operator<<(std::ostream& os, const Heap& heap) {
        os << heap.keys;
        return os;
    }
};

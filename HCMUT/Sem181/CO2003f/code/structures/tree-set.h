#pragma once

#include <cassert>
#include "avl-tree.h"
#include "array-list.h"

template <typename T>
class TreeSet {
private:
    AVLTree<T> tree;
    int size;

public:
    TreeSet() : size(0) {}

    int getSize() const {
        return size;
    }

    void push(T key) {
        tree.push(key);
        size++;
    }

    void pop(T key) {
        assert(tree.hasKey(key) && "TreeSet::pop(): invalid key");
        tree.pop(key);
        size--;
    }

    void hasKey(T key) {
        return tree.hasKey(key);
    }

    T getMin() {
        return tree.getMin();
    }

    T getMax() {
        return tree.getMax();
    }

    ArrayList<T> getEntries() {
        return tree.getArrayList();
    }

    ~TreeSet() = default;
};

#pragma once

#include <cassert>
#include "avl-tree.h"
#include "key-value-pair.h"

template <typename Key, typename Value>
class TreeMap {
    using KeyValuePair = KeyValuePair<Key, Value>;

private:
    AVLTree<KeyValuePair> tree;
    int size;

public:
    TreeMap() : size(0) {}

    int getSize() const {
        return size;
    }

    void push( Key key, Value value) {
        tree.push(KeyValuePair(key, value));
        size++;
    }

    void pop(Key key) {
        KeyValuePair refEntry(key);
        assert(tree.hasKey(refEntry) && "TreeMap::pop(): invalid key");
        tree.pop(refEntry);
        size--;
    }

    bool hasKey(Key key) const {
        KeyValuePair refEntry(key);
        return tree.hasKey(refEntry);
    }

    Value get(Key key) const {
        KeyValuePair refEntry(key);
        return tree.get(refEntry).value;
    }

    Value getMin() const {
        return tree.getMin().value;
    }

    Value getMax() const {
        return tree.getMax().value;
    }

    ArrayList<KeyValuePair> getEntries() {
        return tree.getArrayList();
    }

    ~TreeMap() = default;
};

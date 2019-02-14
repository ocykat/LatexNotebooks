#pragma once

#include "singly-linked-list.h"

template <typename Key>
class Stack {
private:
    SinglyLinkedList<Key> linkedList;

public:
    Stack() = default;

    int getSize() const {
        return linkedList.getSize();
    }

    bool isEmpty() const {
        return linkedList.getSize() == 0;
    }

    void push(Key key) {
        linkedList.pushFront(key);
    }

    Key pop() {
        assert(linkedList.getSize() > 0 && "Stack::pop(): empty");
        return linkedList.popFront();
    }

    Key getTop() const {
        assert(linkedList.getSize() > 0 && "Stack::getTop(): empty");
        return linkedList.getFront();
    }

    friend std::ostream& operator<<(std::ostream& os, const Stack& stack) {
        os << "Stack[ " << stack.linkedList << " ]";
        return os;
    }

    ~Stack() = default;
};

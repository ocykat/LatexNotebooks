#pragma once

#include <cassert>
#include "doubly-linked-list.h"

template <typename Key>
class Queue {
private:
    DoublyLinkedList<Key> linkedList;

public:
    Queue() = default;

    int getSize() const {
        return linkedList.getSize();
    }

    void enqueue(Key key) {
        linkedList.pushBack(key);
    }

    Key dequeue() {
        assert(linkedList.getSize() > 0 && "Queue::dequeue(): empty");
        return linkedList.popFront();
    }

    Key getFront() const {
        assert(linkedList.getSize() > 0 && "Queue::getTop(): empty");
        return linkedList.getFront();
    }

    friend std::ostream& operator<<(std::ostream& os, const Queue& queue) {
        os << "Queue[ " << queue.linkedList << " ]";
        return os;
    }

    ~Queue() = default;
};
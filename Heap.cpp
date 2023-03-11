/*
    @file Heap.cpp

    Implementation file for the Heap class

    @Note This is the implementation of a min-heap
*/

#include "Heap.hpp"

// add an element to the tree
void Heap::enqueue(HNode* newElement) {

    // Add a new leaf
    tree.push_back(0);
    int index = tree.size() - 1;

    // Demote parents that are larger than the new element
    while ((index > 1) && (tree[index / 2]->value > newElement->value)) {
        tree[index] = tree[index / 2];
        index = index /  2;
    }

    // Store the new element into the vacant slot
    tree[index] = newElement;
}

// remove the smallest element
HNode* Heap::dequeue() {

    // @TODO Implement dequeue
}

// fix the heap from a specific index up
void Heap::fix_up(const int&) {

    // @TODO Implement fix_up
}

// fix the tree after replacing the smallest element
void Heap::fix_down(const int&) {

    // @TODO Implement fix_down
}

void Heap::clear() {

    // @TODO Implement clear
}

/*
    @file Heap.cpp

    Implementation file for the Heap class

    @Note This is the implementation of a min-heap
*/

#include "Heap.hpp"

// Helper functions

template<class T>
void swap(T a, T b) {
    T temp = a;
    a = b;
    b = temp;
}

int PARENT(const int i) {
    return (i - 1) / 2;
}

// add an element to the tree
// @TODO implement position
void Heap::enqueue(HNode* newElement) {

    // Add a new leaf
    tree.push_back(nullptr);
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

    // The root of a min-heap is the smallest element
    HNode* min = tree[1];

    // Remove last element
    int lastIndex = tree.size();
    HNode* last = tree.back();
    tree.pop_back();

    if(lastIndex > 1) {
        tree[1] = last;
        fix_down(position); // @TODO figure out what should be passed here
    }

    return min;
}

// fix the heap from a specific index up
void Heap::fix_up(const int& i) {

    // check if the node at index `i` and its parent violate the heap property
    if (i && tree[PARENT(i)] > tree[i])
    {
        // swap the two if heap property is violated
        swap(tree[i], tree[PARENT(i)]);

        // call fix_up-up on the parent
        fix_up(PARENT(i));
    }
}

// fix the tree after replacing the smallest element
void Heap::fix_down(const int&) {

    HNode* root = tree[1];
    int lastIndex = tree.size() - 1;

    // Promote children of removed root while they are larger than last
    int index = 1;
    bool more = true;

    while (more) {

        int childIndex = 2 * index;

        if (childIndex <= lastIndex) {

            // Get smaller child, left child first
            HNode* child = tree[2 * index];

            // Use right child instead if it is smaller
            if ((2 * index + 1 <= lastIndex) && (tree[2 * index + 1] < child)) {
                childIndex = 2 * index + 1; child = tree[2 * index + 1];
            }

            // Check if larger child is smaller than root; if so promote child
            if (child < root) {
                tree[index] = child;
                index = childIndex;
            }

            // Root is smaller than both children
            else {
                more = false;
            }
        }

        // No children
        else {
            more = false;
        }
    }

    // Store root element in vacant slot
    tree[index] = root;
}

void Heap::clear() {

    // @TODO Implement clear
}

/*
    @file Heap.cpp

    Implementation file for the Heap class

    @Note this is the implementation of a min-heap
    @Note root element is at index 1 of the vector
*/

#include "Heap.hpp"

// Helper functions

// Swaps a & b
template<class T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// @param i Index of the current element
// @retval Returns the parent's index
int PARENT(const int i) {
    return i / 2;
}

// @param i Index of the current element
// @retval Returns the left child's index
int LEFT(const int i) {
    return 2 * i;
}

// @param i Index of the current element
// @retval Returns the right child's index
int RIGHT(const int i) {
    return (2 * i) + 1;
}

// @param i Index of the current element
// @retval true - Element at 'i' is NOT the root
// @retval false - Element at 'i' is the root
bool notRoot(const int i) {
    return i > 1;
}

// @return Returns the index of the root of the heap
int ROOT() {
    return 1;
}

// @param tree The vector storing the heap
// @return The last index of the tree
int LAST_INDEX(std::vector<HNode*> tree) {
    return tree.size() - 1;
}

// add an element to the tree
void Heap::enqueue(HNode* newElement) {

    // Add a new leaf, its value is not important
    HNode* newNode;
    newNode = new HNode('\0', 0);
    tree.push_back(newNode);
    int index = LAST_INDEX(tree);

    // Demote parents that are larger than the new element
    while (notRoot(index) && (*newElement < *tree[PARENT(index)])) {
        tree[index] = tree[PARENT(index)];
        index = PARENT(index);
    }

    // Store the new element into the vacant slot
    tree[index] = newElement;
    // Update the index of the last element added
    position = index;
    // Increment the number of elements stored
    ++count;
}

// remove the smallest element
HNode* Heap::dequeue() {

    // The root of a min-heap is the smallest element
    HNode* min = tree[ROOT()];

    // Get the index of the last element of the heap
    int lastIndex = LAST_INDEX(tree);

    // Record the value of the last element
    HNode* lastElement = tree.back();

    // Remove the last element
    tree.pop_back();
    --count;

    // If the last element removed was not the root
    if(notRoot(lastIndex)) {

        // The new root is the last element
        tree[ROOT()] = lastElement;
        // Re-heap downward
        fix_down(position); // @TODO figure out what should be passed here
    }

    return min;
}

// fix the heap from a specific index up
void Heap::fix_up(const int& i) {

    // check if the node at index 'i' and its parent violate the heap property
    if (tree[i] < tree[PARENT(i)])
    {
        // swap the two if heap property is violated
        swap(tree[i], tree[PARENT(i)]);

        // call fix_up-up on the parent
        return fix_up(PARENT(i));
    }
}

// fix the tree after replacing the smallest element
// @TODO figure out parameter
void Heap::fix_down(const int&) {

    HNode* root = tree[ROOT()];
    int lastIndex = LAST_INDEX(tree);

    // Promote children of removed root while they are larger than last
    int index = ROOT();
    bool more = true;

    while (more) {

        int childIndex = LEFT(index);

        if (childIndex <= lastIndex) {

            // Get smaller child, left child first
            HNode* child = tree[LEFT(index)];

            // Use right child instead if it is smaller
            if ((RIGHT(index) <= lastIndex) && (*tree[RIGHT(index)] < *child)) {
                childIndex = RIGHT(index);
                child = tree[RIGHT(index)];
            }

            // Check if larger child is smaller than root; if so promote child
            if (*child < *root) {
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

    // While the heap has items, keep dequeueing
    while (count > 0) {
        dequeue();
    }
}

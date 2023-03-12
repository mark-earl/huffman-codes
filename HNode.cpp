// hnode.cpp -- heap node class
// c. 2015 A. Deeter

#include "HNode.hpp"

// constructor for leaf nodes
HNode::HNode(const char& character, const int& frequency) {

    // For leaf nodes, the value member is the character...
    value = character;
    // ...and the weight member the frequency count.
    weight = frequency;
}

// constructor for internal nodes
HNode::HNode(HNode* l, HNode* r) {

    // For internal nodes value is null
    value = '*';
    // The weight is the combined count of the nodes in the subtrees.
    weight = l->weight + r->weight;

    // Preserve tree linkages
    left = l;
    right = r;
}

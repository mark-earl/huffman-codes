// hnode.cpp -- heap node class
// c. 2015 A. Deeter

#include "HNode.hpp"

// helper functions

// @param root The root of the heap
// @retval The total number of nodes in the tree/subtree from root
int totalNodes(HNode* root)
{
    if (root == nullptr)
        return 0;

    int l = totalNodes(root->left);
    int r = totalNodes(root->right);

    return 1 + l + r;
}

// constructor for leaf nodes
HNode::HNode(const char& character, const int& frequency) {

    // For leaf nodes, the value member is the character...
    value = character;
    // ...and the weight member the frequency count.
    weight = frequency;
}

// constructor for internal nodes
HNode::HNode(HNode* l, HNode* r) {

    // For internal nodes value is null (already set)
    // The weight is the combined count of the nodes in the subtrees.
    weight = totalNodes(this);
}

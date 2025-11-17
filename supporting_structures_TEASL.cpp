#include <vector>
#include "supporting_structures_EASL.cpp"

struct TEASL_Node {
    /* data container */
    int Version; // version of identifier
    TEASL_Node* left_pointer; // pointer to ternary tree node (left)
    Node* equal_node_pointer; // pointer to EASL node (centre)
    TEASL_Node* right_pointer; // pointer to ternary tree node (right)
};

#include "utils/inter.h"

int main(void)
{
    // Initialize the tree with some nodes
    node_t *first_node = create_node(0);
    node_t *second_node = create_node(9);
    node_t *third_node = create_node(0);
    node_t *fourth_node = create_node(7);
    node_t *fifth_node = create_node(0);
    node_t *sixth_node = create_node(5);

    // Link the nodes to form a tree structure
    first_node->left = second_node;
    first_node->right = third_node;
    second_node->left = fourth_node;
    second_node->right = fifth_node;
    third_node->left = sixth_node;

    return 0;
}
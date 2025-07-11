#include <stdio.h>
#include <stdlib.h>
#include "inter.h"

/**
 * @return
 */
tree_node_t *create_node(int new_data)
{
    tree_node_t *new_node = malloc(sizeof(tree_node_t));

    if (new_node == NULL)
    {
        printf("Memory allocation failed in create_node!\n");
        return NULL;
    }

    new_node->data = new_data;
    new_node->left_child = NULL;
    new_node->right_child = NULL;

    return new_node;
}

/**
 *
 */
void display_tree(tree_node_t *node)
{
    if (node->left_child == NULL && node->right_child == NULL)
    {
    }
}
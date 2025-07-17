#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "inter.h"

node_t *create_node(int new_data)
{
    node_t *new_node = malloc(sizeof(node_t));

    if (!new_node)
    {
        fprintf(stderr, "Memory allocation failed in create_node!\n");
        return NULL;
    }

    new_node->data = new_data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void print_tree(node_t *node)
{
    if (node->left == NULL && node->right == NULL)
    {
    }
}
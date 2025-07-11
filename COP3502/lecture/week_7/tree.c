#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    return 0;
}

tree_node_t create_node(int new_data)
{
    tree_node_t *new_node = malloc(sizeof(tree_node_t));

    if (new_node == NULL)
    {
        printf("Memory allocation failed in create_node!\n");
        return NULL;
    }

    new_node->data = data;
    new_node->left_child = NULL;
    new_node->right_child = NULL;

    return new_node;
}

void display_tree(tree_node_t *node)
{
    if (node->left_child == NULL && node->right_child == NULL)
    {
    }
}
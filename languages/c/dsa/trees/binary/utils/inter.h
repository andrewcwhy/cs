#ifndef INTER_H
#define INTER_H

typedef struct tree_node
{
    int data;
    struct tree_node *left;
    struct tree_node *right;
} tree_node_t;

tree_node_t *create_node(int new_data);
void display_tree(tree_node_t *node);

#endif
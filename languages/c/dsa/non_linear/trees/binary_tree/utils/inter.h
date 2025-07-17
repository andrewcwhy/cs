#ifndef INTER_H
#define INTER_H

typedef struct node
{
    int data;
    struct node_t *left;
    struct node_t *right;
} node_t;

node_t *create_node(int new_data);
void print_tree(node_t *node);

#endif
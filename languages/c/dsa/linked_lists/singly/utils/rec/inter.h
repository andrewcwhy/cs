#ifndef INTER_H
#define INTER_H

typedef struct Node
{
    int data;
    struct Node *next;
} node_t;

// Function prototypes (declarations)
node_t *create_node(int new_data);
void count_nodes(node_t *head);
void print_ll(node_t *head);

#endif
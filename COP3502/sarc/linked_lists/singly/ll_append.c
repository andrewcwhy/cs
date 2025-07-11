#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    node_t *next;
} node_t;

typedef struct ll
{
    node_t *head;
} ll_t;

node_t *append_rec(node_t *head);
ll_t *append_iter(ll_t *list);

int main(void)
{
    return 0;
}

node_t *create_node(int new_data)
{
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

node_t *append_rec(node_t *head)
{
    if (head->next == NULL)
    {
        new_node->data = 0;
        head->next = NULL;
        return new_node;
    }
    return append_rec(head->next);
}

ll_t *append_iter(ll_t *list, int new_data)
{
    node_t *new_node = malloc(sizeof(node_t));
    while (cur->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new_tail_node;
    return new_tail_node;
}
#include <stdio.h>
#include <stdlib.h>
#include "inter.h"

/**
 * Create a new node with the given data.
 * @param new_data The data to be stored in the new node.
 */
node_t *create_node(int new_data)
{
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

/**
 * Count the number of nodes in a linked list.
 *
 * @param head Pointer to the first node of the linked list.
 */
void count_nodes(node_t *head)
{
    int count = 0;
    for (node_t *curr = head; curr != NULL; curr = curr->next)
    {
        count++;
    }

    if (count == 0)
    {
        printf("No nodes in the list.\n");
    }
    else
    {
        printf("The list contains %d node%s.\n",
               count,
               (count == 1) ? "" : "s");
    }
}

void print_ll(node_t *head)
{
    for (node_t *curr = head; curr != NULL; curr = curr->next)
    {
        printf("Data: %d\n", curr->data);
        printf("Address: %p\n", curr);
        if (curr->next != NULL)
        {
            printf("Next Address: %p\n", curr->next);
        }
        else
        {
            printf("Next Address: NULL\n");
        }
    }
}
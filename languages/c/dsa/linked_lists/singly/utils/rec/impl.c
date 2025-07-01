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
    if (head == NULL)
    {
        return;
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
    count_nodes(head->next);
}

void print_ll(node_t *head)
{
    if (head == NULL)
    {
        return;
    }
    printf("Data: %d\n", head->data);
    printf("Address: %p\n", head);
    if (head->next != NULL)
    {
        printf("Next Address: %p\n", head->next);
    }
    else
    {
        printf("Next Address: NULL\n");
    }
    print_ll(head->next);
}
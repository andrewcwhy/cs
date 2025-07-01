#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "utils/iter/inter.h"

bool search_iter(node_t *head, int target);
bool search_rec(node_t *head, int target);
node_t *create_node(int new_data);

int main(void)
{
    node_t *head = create_node(9);
    node_t *second = create_node(7);
    node_t *third = create_node(28);

    head->next = second;
    head->next->next = third;

    int target = 7;

    if (search_rec(head, target))
    {
        printf("Element %d found in the linked list.\n", target);
    }
    else
    {
        printf("Element %d not found in the linked list.\n", target);
    }

    print_ll(head);
    count_nodes(head);

    return 0;
}

bool search_iter(node_t *head, int target)
{
    node_t *curr = head;

    while (curr != NULL)
    {
        if (curr->data == target)
        {
            return true;
        }

        curr = curr->next;
    }

    return false;
}

bool search_rec(node_t *head, int target)
{
    if (head == NULL)
    {
        return false;
    }

    if (head->data == target)
    {
        return true;
    }

    return search_rec(head->next, target);
}
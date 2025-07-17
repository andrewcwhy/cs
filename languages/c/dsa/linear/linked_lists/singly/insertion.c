#include <stdio.h>
#include "utils/inter.h"

node_t *ins_start(node_t *head, int new_data);
void ins_end(node_t *head, int new_data);

int main(void)
{
    node_t *head = create_node(9);
    node_t *second = create_node(7);
    node_t *third = create_node(28);
    head->next = second;
    head->next->next = third;

    head = ins_start(head, 3);
    ins_end(head, 5);

    print_ll(head);
    count_nodes(head);

    return 0;
}

node_t *ins_start(node_t *head, int new_data)
{
    node_t *new_node = create_node(new_data);
    // Change the next pointer of the new node to point to the current head.
    new_node->next = head;
    return new_node;
}

void ins_end(node_t *head, int new_data)
{
    node_t *new_node = create_node(new_data);
    node_t *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    // Change the next pointer of the last node to point to the new node.
    curr->next = new_node;
}
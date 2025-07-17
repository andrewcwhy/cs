#include <stdio.h>
#include "utils/inter.h"

int main(void)
{
    node_t *head = create_node(9);
    node_t *second = create_node(7);
    node_t *third = create_node(5);

    head->next = second;
    head->next->next = third;

    print_ll(head);

    return 0;
}
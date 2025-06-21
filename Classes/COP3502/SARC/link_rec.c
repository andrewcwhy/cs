#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node_t;

int count_nodes(node_t *head);

int main(void)
{
    node_t *head = malloc(sizeof(node_t));
    node_t *second = malloc(sizeof(node_t));
    head->data = 4;
    head->next = second;
    second->data = 6;
    second->next = NULL;

    int counted = count_nodes(head);
    printf("Number of nodes: %d\n", counted);

    free(head);
    free(second);

    return 0;
}

int count_nodes(node_t *head)
{
    int count = 0;
    if (head == NULL)
    {
        return 0;
    }
    count++;
    return count + count_nodes(head->next);
}
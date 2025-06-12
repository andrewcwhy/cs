#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    node_t *next;
} node_t;

typedef struct LinkedList {
    node_t *head;
} ll_t;
 n    
void insert(LinkedList *LL, int n);

int main(void) {

}

void insert(ll_t *LL, int n)
{
    node_t *new_node = malloc(sizeof(Node));
    node_t *head = LinedList->head;
    new_node->data = n;
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = new_node;
}
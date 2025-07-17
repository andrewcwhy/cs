#ifndef INTER_H
#define INTER_H

#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} node_t;

typedef struct queue
{
    int size;
    node_t *head;
    node_t *tail;
} queue_t;

queue_t *create_queue();
int dequeue(queue_t *queue, bool *status);
void destroy_queue(queue_t *queue);
bool is_empty(queue_t *queue);
bool is_full(queue_t *queue);
void enqueue(queue_t *queue, int data);
int peek(queue_t *queue, bool *status);
void print_queue(queue_t *queue);
int size(queue_t *queue);

#endif
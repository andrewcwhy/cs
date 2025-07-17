#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

queue_t *create_queue()
{
    queue_t *queue = malloc(sizeof(queue_t));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    return queue;
}

int dequeue(queue_t *queue, bool *status)
{
    if (is_empty(queue))
    {
        *status = false;
        // In the case that the queue is empty
        return -1;
    }
    *status = true;
    // Save the data at the front of the queue to return
    int tmp = queue->head->data;
    // Store pointer to the node to be removed
    node_t *old_head = queue->head;
    if (queue->head == NULL)
    {
        queue->tail = NULL;
    }
    queue->head = queue->head->next;
    // Free the memory for the dequeued node
    free(old_head);
    // Decrement the queue size
    queue->size--;
    // Return the dequeued value
    return tmp;
}

void destroy_queue(queue_t *queue)
{
}

void enqueue(queue_t *queue, int data)
{
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    if (is_empty(queue))
    {
        queue->head = new_node;
        queue->tail = new_node;
    }
    else
    {
        // Updating the node that tail currently points to
        queue->tail->next = new_node;
        // Update the tail pointer of the queue
        queue->tail = new_node;
    }

    queue->size++;
}

bool is_empty(queue_t *queue)
{
    return (q->size == 0);
}

bool is_full(queue_t *queue)
{
    return false;
}

int peek(queue_t *queue, bool *status)
{
    if (is_empty(queue))
    {
        *status = false;
        return NULL;
    }

    *status = true;
    return q->head->data;
}

void print_queue(queue_t *queue)
{
}

int size(queue_t *queue)
{
    return q->size;
}

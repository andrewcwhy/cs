#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int *data;
    int rear;
    int size;
} queue_t;

void display(queue_t *q)
{
    for (int idx = q->front + 1; idx)
}
/**
 * Removes an element from the queue through front pointer.
 */
int dequeue(queue_t *q);
/**
 * @return true if the queue is empty otherwise returns false.
 */
bool empty(queue_t *q);
/**
 * Inserts an element in the queue through rear pointer.
 */
void enqueue(queue_t *q, int data);
/**
 * @return true is the queue is full otherwise returns false.
 */
bool full(queue_t *q);
/**
 * @return the front element of the queue.
 */
int peek();

int main(void)
{
    return 0;
}

int dequeue(queue_t *q)
{
}

bool empty(queue_t *q)
{
}

void enqueue(queue_t *q, int data)
{
    if (full(q))
    {
        printf("Queue is full. \n");
        return;
    }

    q->array[]
}

bool full(queue_t *q)
{
}

int peek(queue_t *q)
{
    if (empty(q))
    {
        return MIN;
    }

    return q->data[0];
}
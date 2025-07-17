#include <stdio.h>
#include <stdlib.h>

typedef struct task
{
    char name[100];
    struct task *next;
} task_t;

typedef struct task_queue
{
    task_t *front;
    task_t *rear;
} task_queue_t;

typedef struct task_stack
{
    task_t *top;
} task_stack_t;

// - Queue operations
void enqueue(task_queue_t *queue, const char *task_name);
void dequeue(task_queue_t *queue);
void print_queue(const task_queue_t *queue);
// - Stack operations
void push(task_stack_t *stack, const char *task_name);
char *pop(task_stack_t *stack);
void print_stack(const task_stack_t *stack);
// - Task manager operations
void add_task(task_queue_t *queue, task_stack_t *undo_stack, const char *task_name);
void process_task(task_queue_t *queue, task_stack_t *undo_stack);
void undo(task_queue_t *queue, task_stack_t *undo_stack, task_stack_t *redo_stack);
void redo(task_queue_t *queue, task_stack_t *undo_stack, task_stack_t *redo_stack);

int main(void)
{
    task_queue_t queue = {NULL, NULL};
    task_stack_t undo_stack = {NULL};
    task_stack_t redo_stack = {NULL};

    add_task(&queue, &undo_stack, "Email Client");
    add_task(&queue, &undo_stack, "Compile Report");
    print_queue(&queue);
    print_stack(&undo_stack);
    print_stack(&redo_stack);

    processTask(&queue, &undo_stack);
    print_queue(&queue);
    print_stack(&undo_stack);
    print_stack(&redo_stack);
    undo(&queue, &undo_stack, &redo_stack);
    print_queue(&queue);
    print_stack(&undo_stack);
    print_stack(&redo_stack);

    redo(&queue, &undo_stack, &redo_stack);
    print_queue(&queue);
    print_stack(&undo_stack);
    print_stack(&redo_stack);

    return 0;
}

// - Queue operations
void enqueue(task_queue_t *queue, const char *task_name)
{
}

void dequeue(task_queue_t *queue)
{
}

void print_queue(const task_queue_t *queue)
{
}

// - Stack operations

/**
 * Inserts an element at the top of the stack.
 */
void push(task_stack_t *stack, const char *task_name)
{
}

char *pop(task_stack_t *stack)
{
}

void print_stack(const task_stack_t *stack)
{
}

// - Task manager operations
void add_task(task_queue_t *queue, task_stack_t *undo_stack, const char *task_name)
{
}

void process_task(task_queue_t *queue, task_stack_t *undo_stack)
{
}

void undo(task_queue_t *queue, task_stack_t *undo_stack, task_stack_t *redo_stack)
{
}

void redo(task_queue_t *queue, task_stack_t *undo_stack, task_stack_t *redo_stack)
{
}
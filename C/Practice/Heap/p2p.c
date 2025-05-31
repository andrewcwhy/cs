#include <stdio.h>
#include <stdlib.h>

void allocate_int(int **ptr_ptr, int val);

int main(void)
{
    int *my_int_ptr = NULL;

    allocate_int(&my_int_ptr, 42);

    printf("Allocated value = %d\n", *my_int_ptr);
    free(my_int_ptr);

    return 0;
}

void allocate_int(int **ptr_ptr, int val)
{
    // Requests to bytes to hold single int from the heap.
    // new_ptr holds the address of a newly allocated sizeof(int)-byte block on the heap
    // It returns an int * pointing to that newly allocated memory. 
    int *new_ptr = malloc(sizeof(int));
    // We are copying the value of new_ptr (the heap address returned by malloc)
    *ptr_ptr = new_ptr;
    // new_ptr is our newly allocated block of memory
    // Writing *new_ptr = val; stores the integer val into that heap location.
    *new_ptr = val;
}
#include <stdio.h>

void ex1(void);

int main()
{
    ex1();

    return 0;
}

/**
 * A pointer is a variable that stores the memory address of another variable as its value.
 * A pointer variable points to a data type (like int) of the same type, and is created with * operator
 * The address of the variable is assigned to the pointer.
 */

void ex1(void)
{
    int my_age = 19;        // An int variable
    int *pointer = &my_age; // A pointer variable that stores the address of my_age

    printf("Hello, I am Andrew. I am %d\n", my_age);
    printf("Memory address of my_age: %p\n", &my_age);
    printf("Memory address of my_age with the pointer %p\n", pointer);
}
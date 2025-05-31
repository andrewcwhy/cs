// Pointers as function arguments

#include <stdio.h>

void increment(int *ptr);

// Calling function
int main(void)
{
    int num = 10;

    // Call `inc` with the address of `num` (actual argument).
    increment(&num);
    
    printf("Value of the variable num = %d", num);

    return 0;
}

// Called function
// `ptr` is a parameter (formal argument) of type "pointer to integer."
void increment(int *ptr)
{
    // Dereference `ptr` to modify the integer it points to.
    *ptr += 1;
}
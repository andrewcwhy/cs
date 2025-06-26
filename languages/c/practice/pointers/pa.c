#include <stdio.h>

// int - 4 bytes = 32 bits
// char - 1 byte = 8 bits
// float - 4 bytes = 32 bits
// Left most bit stores the information that whether the integer is positive or negative. This is called a sign bit

int main(void)
{
    int var = 1025;
    // Store address of var variable
    int *iptr = &var;

    // Dereferencing ptr to access the value
    printf("Value of var is %d.\n", *iptr);
    printf("Address of var is %p.\n", iptr);

    char lttr = 'A';
    char *cptr = &lttr;

    printf("Value of lttr is %c.\n", *cptr);
    printf("Address of lttr is %p\n", cptr);

    return 0;
}
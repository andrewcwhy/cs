// Pointer to Pointer

#include <stdio.h>

void e1();
void e2();

int main(void)
{
    e2();
    return 0;
}

void e1()
{
    int var = 5;

    // ptr1 points to var
    int *ptr1 = &var;

    // ptr2 points to ptr1 (which itself points to var)
    int **ptr2 = &ptr1;

    // Dereferencing - use %d
    printf("var = %d\n", var);
    printf("*ptr1 = %d\n", *ptr1);
    printf("**ptr2 = %d\n", **ptr2);

    // Show addresses:
    printf("&var = %p\n", &var);
    printf("ptr1 (=&var) = %p\n", ptr1);
    printf("&ptr1 = %p\n", &ptr1);
    printf("ptr2 (=&ptr1) = %p\n", ptr2);
}

void e2()
{
    int var = 5;
    // Holds the address of var
    int *x = &var;
    // Dereference x to modify the value stored at the address it points to.
    *x = 6;
    // Holds the address of x
    int **y = &x;
    // Holds the address of y.c
    int ***z = &y;

    printf("Dereferencing:\n");
    printf("  var               = %d\n", var);
    printf("  *x (value at x)   = %d\n", *x);
    printf("  **y (value at y)  = %d\n", **y);
    printf("  ***z (value at z) = %d\n\n", ***z);

    // Show addresses at each level of indirection
    printf("Addresses at each level:\n");
    printf("  Address of var    = %p\n", &var);
    printf("  x (=&var)         = %p\n", x);
    printf("  Address of x      = %p\n", &x);
    printf("  y (=&x)           = %p\n", y);
    printf("  Address of y      = %p\n", &y);
    printf("  z (=&y)           = %p\n", z);
    printf("  Address of z      = %p\n\n", &z);
}
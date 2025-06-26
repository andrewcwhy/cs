#include <stdio.h>

void pass_by_ref(int *num);

int main(void)
{
    int x = 10;
    print("Before pass_by_ref: %d\n", x);
    pass_by_ref(&x);
    printf("Outside pass_by_ref: %d", x);
    return 0;
}

void pass_by_ref(int *num)
{
    *num = 20; // This change will affect the original variable
    printf("Inside pass_by_ref: %d\n", *num);
}
// Pass by value is a method of passing arguments to functions where the function receives a copy of the variable's value, meaning any modifications made to the parameter within the function do not affect the original variable.

#include <stdio.h>

void pass_by_val(int num);

int main(void)
{
    int x = 10;

    printf("Before pass_by_val: %d\n", x);
    pass_by_val(x);                       // Pass by value, num is passed as a copy
    printf("After pass_by_val: %d\n", x); // num remains unchanged

    return 0;
}

void pass_by_val(int num)
{
    num = 20; // This change will not affect the original num
    printf("Inside pass_by_val: %d\n", num);
}
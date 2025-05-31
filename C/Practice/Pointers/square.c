#include <stdio.h>

void square(int *num);

int main(void)
{
    int num = 10;

    square(&num);
    
    printf("Result: %d\n", num);

    return 0;
}

void square(int *num)
{
    *num *= *num;
}
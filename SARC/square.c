#include <stdio.h>

int sqr(int val);

int main()
{
    int val = 10;
    int result = sqr(val);

    printf("Result: %d\n", result);

    return 0;
}

// Function definition
int sqr(int val)
{
    return val * val;
}

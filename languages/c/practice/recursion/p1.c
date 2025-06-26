#include <stdio.h>

void rec(int n);

int main(void)
{
    rec(1);

    return 0;
}

void rec(int n)
{
    // Base condition
    if (n == 6)
    {
        return;
    }

    // Recursion case (recursive call)
    printf("Recursion Level: %d\n", n);
    rec(n + 1);
}
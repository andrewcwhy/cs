#include <stdio.h>

int rec_sum(int n);

int main(void)
{
    int sum = rec_sum(5);

    printf("%d", sum);

    return 0;
}

int rec_sum(int n)
{
    if (n == 0)
    {
        return 0;
    }

    int res = n + rec_sum(n - 1);
    return res;
}

// main(): rec_sum(5)
// - rec_sum(5): res = 5 + rec_sum(4)
// - rec_sum(4): res = 4 + rec_sum(3)
// - rec_sum(3): res = 3 + rec_sum(2)
// - rec_sum(0): return

// Data of a recursive function is stored in the stack.
// This stack frame is removed when the function returns.
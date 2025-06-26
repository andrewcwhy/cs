#include <stdio.h>

int power(int n, int m);

int main(void)
{
    int n = 2, m = 3;
    int res = power(n, m);
    printf("%d raised to the power of %d is: %d\n", n, m, res);
    return 0;
}

int power(int n, int m)
{
    // Base condition to stop recursion
    if (m == 0)
    {
        return 1;
    }

    // Recursive case
    return n * power(n, m - 1);
}

// power(2, 3) calls power(2,2) and returns res = 2 * power(2, 2)
// power(2, 2) calls power(2,2) and returns res = 2 * power(2, 1)
// power(2, 1) calls power(2,2) and returns res = 2 * power(2, 0)
// power(2, 0) hits the base case (m == 0) and returns 1

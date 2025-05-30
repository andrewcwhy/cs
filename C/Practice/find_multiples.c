#include <stdio.h>

int find_multiples(const int array[], int start, int end, int target);

int main()
{
    int array[] = {10, 6, 4, 5, 20};
    size_t length = sizeof(array) / sizeof(array[0]);

    int target = 2;

    if (target == 0) {
        printf("Target cannot be zero.\n");
        return 1;
    }

    int matched = find_multiples(array, 0, length - 1, target);
    if (matched > 0)
    {
        printf("There are %d multiple(s) of %d.\n", matched, target);
    }
    else
    {
        printf("There are no multiples of %d.\n", target);
    }

    return 0;
}

int find_multiples(const int array[], int start, int end, int target)
{
    int count = 0;

    if (array[start] % target == 0)
    {
        count++;
    }

    if (start == end)
    {
        return count;
    }

    return count + find_multiples(array, start + 1, end, target);
}
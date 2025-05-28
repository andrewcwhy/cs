#include <stdio.h>

int find_multiples(const int array[], int start, int end, int target);

int main()
{
    int array[] = {10, 6, 4, 5, 20};
    size_t length = sizeof(array) / sizeof(array[0]);

    int target = 5;

    int counted = find_multiples(array, 0, length - 1, target);
    printf("There are %d multiple(s) of %d.\n", counted, target);

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
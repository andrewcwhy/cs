#include <stdio.h>

int find_multiples(const int arr[], int start, int end, int target);

int main(void)
{
    // `arr[]` is internally a pointer
    int arr[] = {10, 6, 4, 5, 20};
    size_t length = sizeof(arr) / sizeof(arr[0]);

    int target = 2;

    if (target == 0) {
        printf("Target cannot be zero.\n");
        return 1;
    }

    int matched = find_multiples(arr, 0, length - 1, target);
    
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

int find_multiples(const int arr[], int start, int end, int target)
{
    int count = 0;

    if (arr[start] % target == 0)
    {
        count++;
    }

    if (start == end)
    {
        return count;
    }

    return count + find_multiples(arr, start + 1, end, target);
}
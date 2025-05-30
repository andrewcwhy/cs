#include <stdio.h>

// Function declaration
int linear_search(const int arr[], size_t len, int target);

int main(void)
{
    int arr[] = {8, 2, 2, 4, 5, 6, 7};
    size_t len = sizeof(arr) / sizeof(arr[0]);
    int target = 9;

    int index = linear_search(arr, len, target);

    if (index != -1)
    {
        printf("Target %d found at index %d.\n", target, index);
    }
    else
    {
        printf("Target %d not found.\n", target);
    }

    return 0;
}

// Function definition
int linear_search(const int arr[], size_t len, int target)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == target)
        {
            return i; // Found value
        }
    }
    return -1; // Not found after scanning all elements
}
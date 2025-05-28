#include <stdio.h>

// Function prototype
int binary_search(int array[], int length, int target);

int main()
{
    int data[] = {1, 2, 5, 6, 8, 11};
    int length = sizeof(data) / sizeof(data[0]);
    int target = 5;

    int result = binary_search(data, length, target);

    if (result == 1)
    {
        printf("%d\n", result);
        printf("Target found.");
    }
    else
    {
        printf("%d\n", result);
        printf("Target not found.");
    }

    return 0;
}

// Function definition
int binary_search(int array[], int length, int target)
{
    int left = 0;
    // last index = 5
    int right = length - 1;

    // loop that runs as long as left index is less than, or equal to, the right index.

    // An if-statement that compares the middle value with the target value, and returns the index if the target value is found.
    // An if-statement that checks if the target value is less than, or larger than, the middle value, and updates the "left" or "right" variables to narrow down the search area.

    while (left <= right)
    {
        // 5/2 = 2.5, floor to 2 is the first index used to check if the middle value (2)  is equal to the target value (5)
        int middle = (left + right) / 2;

        if (array[middle] == target)
        {
            return 1;
        }
        else if (array[middle] < target)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }

    return -1;
}
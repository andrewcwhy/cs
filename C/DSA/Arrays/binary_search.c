#include <stdio.h>

// Function declaration
int binary_search(const int arr[], size_t len, int target);

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    size_t len = sizeof(arr) / sizeof(arr[0]);
    int target = 5;

    int idx = binary_search(arr, len, target);

    if (idx != -1)
    {
        printf("Element %d found at index %d.\n", target, idx);
    }
    else
    {
        printf("Element %d not found.\n", target);
    }

    return 0;
}

// Function definition
int binary_search(const int arr[], size_t len, int target)
{
    /**
     * idx of the first value in the arr
     * first idx = 0
     * first value = 1
     */
    int left = 0;
    /**
     * represents the idx of the last value in the arr
     * last idx = 6
     * last value = 7
     */
    int right = len - 1;

    // loop that runs as long as left idx is less than, or equal to, the right idx.
    while (left <= right)
    {
        /** 0+6/2 = 3 is the first index to check if the middle value (4) is equal to the target value 2 */
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}
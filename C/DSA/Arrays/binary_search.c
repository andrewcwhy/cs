#include <stdio.h>

// ----- Function Prototypes (Declarations) -----

int binary_search_iter(const int arr[], int len, int target);
int binary_search_rec(const int arr[], int left, int right, int target);

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int len = sizeof(arr) / sizeof(arr[0]);
    int target = 5;

    if (len == 0)
    {
        printf("Error: Cannot search in an empty array.\n");
        // 1 indicates an error occurred and exits the program
        return 1;
    }

    printf("Searching for %d in the array...\n", target);

    // Perform iterative binary search and test the result
    int res_iter = binary_search_iter(arr, len, target);
    if (res_iter != -1)
    {
        printf("Iterative: Element %d found at index %d.\n", target, res_iter);
    }
    else
    {
        printf("Iterative: Element %d not found.\n", target);
    }

    // Perform recursive binary search and test the result
    int res_rec = binary_search_rec(arr, 0, len - 1, target);
    if (res_rec != -1)
    {
        printf("Recursive: Element %d found at index %d.\n", target, res_rec);
    }
    else
    {
        printf("Recursive: Element %d not found.\n", target);
    }

    // 0 indicates successful execution
    return 0;
}

// ----- Function Definitions -----

int binary_search_iter(const int arr[], int len, int target)
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

    // Loop that runs as long as left index is less than, or equal to, the right index.
    while (left <= right)
    {
        /**
         * mid = 0 + (6 - 0) / 2 = 6 / 2 = 3.
         * 3 is the first index to check if the middle value (4) is equal to the target value 2.
         */
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }

        else if (arr[mid] < target)
        {
            // if the target is greater, ignore the left half
            left = mid + 1;
        }

        else
        {
            // If the target is smaller, ignore the right half
            right = mid - 1;
        }
    }

    // Target not found in the array
    return -1;
}

int binary_search_rec(const int arr[], int left, int right, int target)
{
    // Base case
    if (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            return binary_search_rec(arr, mid + 1, right, target);
        }
        else
        {
            return binary_search_rec(arr, left, mid - 1, target);
        }
    }

    return -1;
}
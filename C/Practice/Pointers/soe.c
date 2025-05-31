// Arrays as function arguments

#include <stdio.h>

int sum_of_elems(const int arr[], size_t len);

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};
    size_t len = sizeof(arr) / sizeof(arr[0]);

    int total = sum_of_elems(arr, len);

    printf("Sum of elements = %d\n", total);

    return 0;
}

int sum_of_elems(const int arr[], size_t len)
{
    int i, sum = 0;

    for (i = 0; i < len; i++)
    {
        sum += arr[i];
    }

    return sum;
}
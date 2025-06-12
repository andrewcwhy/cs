// This algorithm is not suitable for large data sets as its average and worst-case time complexity are quite high.

#include <stdio.h>


// Function declaration (prototype): Informs the compiler of the function’s name, return type, and parameter types without providing its body
void bubble_sort(int arr[], int len);
void print_arr(const int arr[], int len);

int main(void)
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};

    int len = sizeof(arr) / sizeof(arr[0]);

    bubble_sort(arr, len);

    print_arr(arr, len);

    return 0;
}

void bubble_sort(int arr[], int len);

void print_arr(const int arr[], int len)
{
    printf("Sorted array with bubble sort method");
    for (int i = 0; i < len; i++)
    {
        printf("%d", arr[i]);
    }
}
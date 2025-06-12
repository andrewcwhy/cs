// Given two sorted arrays of size n that contains integers find the ones that are common to both lists.

#include <stdio.h>

void display_common_nums(const int arr1[], const int arr2[], int len);

int main(void)
{
    int arr1[] = {-3, 0, 7, 10};
    int arr2[] = {0, 2, 6, 10};
    int len = sizeof(arr1) / sizeof(arr1[0]); // assuming both arrays have same size

    display_common_nums(arr1, arr2, len);

    return 0;
}

void display_common_nums(const int arr1[], const int arr2[], int len)
{
    int i = 0, j = 0;

    while (i < len && j < len)
    {
        if (arr1[i] == arr2[j]) {
            printf("%d is common\n", arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j]) {
            i++;
        }
        else {
            j++;
        }
    }
}
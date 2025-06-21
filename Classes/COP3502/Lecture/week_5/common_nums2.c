// Given two sorted arrays of size n that contains integers find the ones that are common to both lists.

#include <stdio.h>

void display_common_nums(const int arr1[], const int arr2[], int len1, int len2);

int main(void)
{
    int arr1[] = {-3, 0, 7, 10};
    int arr2[] = {-5, -3, 0, 2, 6, 10, 12};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);

    display_common_nums(arr1, arr2, len1, len2);

    return 0;
}

void display_common_nums(const int arr1[], const int arr2[], int len1, int len2)
{
    int i = 0, j = 0;

    printf("Common numbers: ");

    while (i < len1 && j < len2)
    {
        if (arr1[i] == arr2[j])
        {
            printf("%d ", arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    printf("\n");
}
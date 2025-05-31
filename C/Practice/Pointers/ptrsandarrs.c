#include <stdio.h>

int main(void)
{
    int arr[] = {2, 4, 5, 8, 1};

    // Gives the base address (which is the same as &arr[0])
    printf("Base address: %p\n", arr);
    // Print the address of the first element in the array.
    printf("Address of the first element: %p\n", &arr[0]);

    printf("Value of the first element: %d\n", arr[0]);
    printf("value of the first element via pointer dereference: %d\n", *arr);

    return 0; 
}
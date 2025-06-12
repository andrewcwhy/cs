#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Declarations
    int *arr = NULL;
    int i, n;

    // Prompt the user for the size of the array
    printf("Enter the number of elements you want to store: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Error: Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the array with squares of indices
    for (i = 0; i < n; i++) {
        arr[i] = i * i; // Store squares of indices
    }

    // Display the contents of the array
    printf("\nArray elements:\n");
    for (i = 0; i < n; i++) {
        printf("arr[%d]: %d\n", i, arr[i]);
    }

    // Free the allocated memory
    free(arr);
    arr = NULL; // Set pointer to NULL to avoid dangling pointers

    // Allocate memory for a single integer and assign a value
    arr = malloc(sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Error: Memory allocation for single integer failed!\n");
        exit(EXIT_FAILURE);
    }

    *arr = 100; // Assign a value to the allocated integer
    printf("\nSingle integer value: %d\n", *arr);

    // Free memory for the single integer
    free(arr);
    arr = NULL; // Set pointer to NULL to prevent dangling pointer issues

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declaration
int linear_search(const int arr[], size_t len, int target);

int main(void)
{
    const size_t N = 1000000000;

    printf("Creating an array with %zu elements...\n", N);

    int *arr = malloc(N * sizeof(int));

    for (size_t i = 0; i < N; i++)
    {
        arr[i] = i;
    }

    int target = N - 1;
    printf("Searching for element %d in the array of %zu elements...\n", target, N);

    struct timespec start, end;
    timespec_get(&start, TIME_UTC);

    int idx = linear_search(arr, N, target);

    timespec_get(&end, TIME_UTC);

    long long elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);
    double elapsed_ms = elapsed_ns / 1e6; // Convert to milliseconds for readability

    printf("Search completed in %lld nanoseconds (%.2f ms).\n", elapsed_ns, elapsed_ms);

    if (idx < 0)
    {
        printf("Element %d not found.\n", target);
    }
    return 0;
}

// Function definition
int linear_search(const int arr[], size_t len, int target)
{
    for (int idx = 0; idx < len; idx++)
    {
        if (arr[idx] == target)
        {
            printf("Element %d found at index %d.\n", target, idx);
            return idx;
        }
    }
    return -1;
}
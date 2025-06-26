#include <stdio.h>
#include <stdlib.h>

void memory_hog(int size);

int main(void) {
    while (1) {
        memory_hog(1000000); // Allocate 1 million bytes (1 MB)
    }

    free(a);

    return 0;
}

void memory_hog(int size)
{
    int *a = malloc(size);
}
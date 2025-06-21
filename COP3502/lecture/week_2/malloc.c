#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *ptr = malloc(sizeof(int));
    if (ptr == NULL)
    {
        printf("Error: allocation unsuccessful.\n");
        return 1;
    }
    *ptr = 5;
    printf("%d\n", *ptr);
    return 0;
}

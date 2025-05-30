#include <stdio.h>

int main()
{
    int entryCount;

    printf("Enter the next measurement: ");
    scanf("%d", &entryCount);

    int measurements[entryCount];
    int input;

    for (int i = 0; i < entryCount; i++)
    {
        printf("Enter the next measurement: ");
        scanf("%d", &input);

        measurements[i] = input;
    }
}
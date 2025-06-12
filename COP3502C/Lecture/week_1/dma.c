#include <stdio.h>

int main()
{
    int entryCount;
    int input;
    int measurements[entryCount];

    printf("Enter the next measurement: ");
    scanf("%d", &entryCount);

    for (int i = 0; i < entryCount; i++)
    {
        printf("Enter the next measurement: ");
        scanf("%d", &input);

        measurements[i] = input;
    }

    return 0;
}
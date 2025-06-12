#include <stdio.h>
#include <string.h>

void rev_str(char str[], int start, int end);

int main(void)
{
    char str[] = "Hello, Andrew!";
    int length = strlen(str);

    printf("Original String: %s\n", str);
    rev_str(str, 0, length - 1);
    printf("Reversed String: %s\n", str);
    return 0;
}

void rev_str(char str[], int start, int end)
{

    // Base condition to stop
    if (start >= end)
        return;

    // Swap characters at start and end
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursively call the function for the next pair
    rev_str(str, start + 1, end - 1);
}
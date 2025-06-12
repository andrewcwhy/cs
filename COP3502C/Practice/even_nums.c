// Program to print the count of even numbers between 1–200. Also print their sum.

#include <stdio.h>

void even_nums(int start, int end, int *count, int *sum);

int main(void)
{
    int start_num, end_num;
    int count = 0, sum = 0;

    printf("Enter start number: \n");
    scanf("%d", &start_num);

    printf("Enter end number: \n");
    scanf("%d", &end_num);

    even_nums(start_num, end_num, &count, &sum);

    printf("Count of even numbers between %d and %d: %d\n", start_num, end_num, count);
    printf("Sum of even numbers between %d and %d: %d\n", start_num, end_num, sum);
    return 0;
}

void even_nums(int start, int end, int *count, int *sum)
{
    for (int i = start; i <= end; i++)
    {
        if (i % 2 == 0)
        {
            (*count)++;  // Dereference the pointer to increment the count
            (*sum) += i; // Dereference the pointer to add to the sum
        }
    }
}
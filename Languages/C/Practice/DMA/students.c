#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee
{
    char *first;
    char *last;
    int ID;
} employee_t;

employee_t *make_array(char **first_names, char **last_names, int *IDs, int n);

int main(void)
{
    return 0;
}

employee_t *make_array(char **first_names, char **last_names, int *IDs, int n)
{
    employee_t *array = malloc(sizeof(employee_t));

    for (int i = 0; i < n; i++)
    {
        array[i].first = malloc(sizeof(char) * strlen(first_names[i] + 1));
        array[i].last = malloc(sizeof(char) * strlen(last_names[i] + 1));
    }

    return array;
}

void free_employees(employee_t *array, int n);
{
    for (int i = 0; i < n, i++)
    {
        free(array[i].first);
        free(array[i].last);
    }
    free(array);
}
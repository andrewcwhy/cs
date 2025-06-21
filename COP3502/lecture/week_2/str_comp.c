#include <stdio.h>
#include <string.h>

void comparison(void);
void incorrect_comparison(void);

int main()
{
    comparison();

    return 0;
}

void comparison(void)
{
    char name1[100];
    char name2[100];

    printf("Enter the name of the first person: \n");
    scanf("%s", name1);

    printf("Enter the name of the second person: \n");
    scanf("%s", name2);

    int cmp = strcmp(name1, name2);

    if (cmp == 0)
    {
        printf("They have the same name.\n");
    }
    else
    {
        printf("They do not have the same name.\n");
    }
}

void incorrect_comparison(void)
{
    char name1[5];
    char name2[5];

    printf("Enter the name of the first person: \n");
    scanf("%s", name1);

    printf("Enter the name of the second person: \n");
    scanf("%s", name2);

    // In C, when you use == with array names, you are comparing their memory addresses (i.e., where they are located in memory).
    if (name1 == name2)
    {
        printf("They do not have the same name.\n");
    }
    else
    {
        printf("They are not the same!\n");
    }
}
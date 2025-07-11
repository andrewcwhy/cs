#include <stdio.h>

typedef struct aisle{
    int number;
    int items;
} aisle_t;

typedef struct item {
    char *name;
    double price;
} item_t;

int main()
{
    Aisle *aisles = malloc(sizeof(Aisle) *4);

    return 0;
}
#include <stdio.h>

typedef struct {
    int aisle_number;
    int items_number;
} Aisle;

typedef struct {
    char *name;
    double price;
} Item;

int main()
{
    Aisle *aisles = malloc(sizeof(Aisle) *4);

    return 0;
}
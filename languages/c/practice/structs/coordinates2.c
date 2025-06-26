#include <stdio.h>
#include <stdlib.h>

typedef struct Coordinate
{
    const char *name;
    int x;
    int y;
} coord_t;

coord_t new_coord(const char *name, int x, int y);
void display_coord(const coord_t coord);

int main(void)
{
    coord_t c1 = new_coord("c1", 10, 20);
    coord_t c2 = new_coord("c2", 40, 50);
    coord_t c3 = new_coord("c3", 70, 90);

    
    display_coord(c1);
    display_coord(c2);
    display_coord(c3);

    return 0;
}

coord_t new_coord(const char *name, int x, int y)
{
    coord_t coord;
    coord.name = name;
    coord.x = x;
    coord.y = y;
    return coord;
}

void display_coord(const coord_t coord)
{
    printf("%s: %d, %d\n", coord.name, coord.x, coord.y);
}
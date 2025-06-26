#include <stdio.h>
#include <stdlib.h>

typedef struct Point
{
    int x;
    int y;
} point_t;

point_t *create_point(int x, int y);
void display_point(const point_t *p);

int main(void)
{
    point_t p1;
    p1.x = 10;
    p1.y = 20;

    printf("Point p1: (%d, %d)\n", p1.x, p1.y);

    point_t *p2 = create_point(10, 20);

    p2->x = 30;
    (*p2).y = 40;

    display_point(p2);

    free(p2);
    return 0;
}

point_t *create_point(int x, int y)
{
    point_t *p = malloc(sizeof(point_t));
    if (p == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    // The -> operator dereferences the pointer and accesses a field. Writing `p->x` is exactly the same as writing `(*p).x`
    p->x = x;
    (*p).y = y;
    return p;
}

void display_point(const point_t point) {
    
}
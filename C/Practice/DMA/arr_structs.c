#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Point
{
    int x;
    int y;
    int z;
    // ptr to char array on the heap and will have the member pt to dynamically allocated mem
    char *desc;
} point_t;

void set_desc(point_t *p, const char *src);
point_t create_point(int x, int y, int z, const char *src);
void display_point(const point_t *point);
void free_point(point_t *p, int len);

int main(void)
{
    int len = 2;

    // ptr var stores the mem addr of a point struct
    // Will store the mem addr of the first point struct in arr of point structs
    point_t *arr = malloc(len * sizeof(point_t));

    // Gives access to the first point struct. dot x allows us to set the x member
    arr[0].x = 1;
    arr[0].y = 1;
    arr[0].z = 3;
    // `malloc(10)` gives 10 bytes of uninit mem
    // For string, it reservers one byte for the trailing `\0`
    // Theres room for at most 9 characters
    set_desc(&arr[0], "Andrew's House");

    arr[1].x = 2;
    // Equivalent to arr[1].y = 2;
    (*(arr + 1)).y = 2;
    arr[1].z = 8;
    set_desc(&arr[1], "The Great Library of Alexandria");

    len = 6;

    arr = realloc(arr, sizeof(point_t) * len);

    arr[2].x = 300;
    arr[2].y = 5;
    arr[2].z = 7;
    set_desc(&arr[2], "The Tower of Wisdom");

    arr[3].x = 9;
    arr[3].y = 423;
    arr[3].z = 12;
    set_desc(&arr[3], "The Castle of Dreams");

    arr[4] = create_point(4, 5, 9, "The Enchanted Forest");
    arr[5] = create_point(6, 7, 23, "The Valley of Shadows");

    for (int i = 0; i < len; i++)
    {
        printf("Point %d:\n", i + 1);
        display_point(&arr[i]);
    }

    free_point(arr, len);
    return 0;
}

void set_desc(point_t *p, const char *src)
{
    // Allocate memory for the description and copy the string
    p->desc = malloc(strlen(src) + 1);
    if ((*p).desc == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strcpy(p->desc, src);
}

// Creating a new point_t struct inside the function and then returning it by value.
point_t create_point(int x, int y, int z, const char *src)
{
    point_t p;
    p.x = x;
    p.y = y;
    p.z = z;
    // Allocate memory for the description and copy the string
    p.desc = malloc(strlen(src) + 1);
    if (p.desc == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strcpy(p.desc, src);
    return p;
}

// Prints the details of one point
void display_point(const point_t *point)
{
    printf("\tDescription: %s\n", point->desc);
    printf("\tCoordinates: (%d, %d, %d)\n", point->x, point->y, point->z);
}

void free_point(point_t *p, int len)
{
    if (p == NULL)
    {
        return;
    }
    for (int i = 0; i < len; i++)
    {
        free(p[i].desc);
    }
    free(p);
}
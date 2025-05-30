#include <stdio.h>

struct Coordinate
{
    int x;
    int y;
    int z;
};

struct Coordinate new_coordinate(int x, int y, int z);
void display_coordinate(const struct Coordinate coordinate);

int main(void)
{

    // Using new_coordinate() and display_coordinate()

    struct Coordinate coordinate1 = new_coordinate(9, 7, 5);
    printf("-----Coordinate 1-----\n");
    display_coordinate(coordinate1);

    // Using only new_coordinate()

    struct Coordinate coordinate2 = new_coordinate(4, 28, 7);
    printf("-----Coordinate 2-----\n");
    printf("x: %d\n", coordinate2.x);
    printf("y: %d\n", coordinate2.y);
    printf("z: %d\n", coordinate2.z);

    // Without using the new_coordinate() and display_coordinate()

    struct Coordinate coordinate3 = {.x = 1, .y = 96, .z = 7};
    printf("-----Coordinate 3-----\n");
    printf("x: %d\n", coordinate3.x);
    printf("y: %d\n", coordinate3.y);
    printf("z: %d\n", coordinate3.z);

    struct Coordinate coordinate4;
    coordinate4.x = 4;
    coordinate4.y = 36;
    coordinate4.z = 12;
    printf("-----Coordinate 4-----\n");
    printf("x: %d\n", coordinate4.x);
    printf("y: %d\n", coordinate4.y);
    printf("z: %d\n", coordinate4.z);

    return 0;
}

struct Coordinate new_coordinate(int x, int y, int z)
{
    struct Coordinate coordinate = {.x = x, .y = y, .z = z};
    return coordinate;
}

void display_coordinate(const struct Coordinate coordinate)
{
    printf("x: %d\n", coordinate.x);
    printf("y: %d\n", coordinate.y);
    printf("z: %d\n", coordinate.z);
}
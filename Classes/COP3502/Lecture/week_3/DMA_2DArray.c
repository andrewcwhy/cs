#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare variables
    int **temperatures = NULL; // Pointer to the 2D array
    int num_cities, num_months, i, j;


    // Prompt user for the number of cities
    printf("Enter the number of cities: ");
    scanf("%d", &num_cities);

    // Stack memory looks like this
    // +----------------+---------------------+
    // | Variable       | Value               |
    // +----------------+---------------------+
    // | num_cities     | 2                   |
    // | num_months     | 3                   |
    // | i              | Uninitialized       |
    // | j              | Uninitialized       |
    // | temperatures   | 0x1000              |
    // +----------------+---------------------+

    // Allocate memory for an array of int pointers (one per city)
    temperatures = malloc(sizeof(int *) * num_cities);
    if (temperatures == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for cities!\n");
        return 1;
    }

    // Prompt user for the number of months
    printf("Enter the number of months to track temperatures: ");
    scanf("%d", &num_months);

    // Allocate memory for each city's temperature array
    for (i = 0; i < num_cities; i++) {
        temperatures[i] = malloc(sizeof(int) * num_months);
        if (temperatures[i] == NULL) {
            fprintf(stderr, "Error: Memory allocation failed for temperatures of city %d!\n", i + 1);
            return 1;
        }
    }

    // Each pointer in the temperatures array now points to an array of num_months integers.
    
    // 0x1000: Pointer array (int* for each city)
    // +--------+--------+
    // | 0x2000 | 0x3000 |  (Points to the temperature arrays for cities)
    // +--------+--------+

    // 0x2000: City 1's temperature array
    // +----+----+----+
    // |    |    |    |  (Values initialized later)
    // +----+----+----+

    // 0x3000: City 2's temperature array
    // +----+----+----+
    // |    |    |    |  (Values initialized later)
    // +----+----+----+


    // Input temperatures for each city
    printf("\nEnter the temperatures for each city (in degrees):\n");
    for (i = 0; i < num_cities; i++) {
        printf("City %d:\n", i + 1);
        for (j = 0; j < num_months; j++) {
            printf("  Month %d: ", j + 1);
            scanf("%d", &temperatures[i][j]);
        }
    }

    // 0x1000: Pointer array (int* for each city)
    // +--------+--------+
    // | 0x2000 | 0x3000 |  (Points to temperature arrays)
    // +--------+--------+

    // 0x2000: City 1's temperature array
    // +----+----+----+
    // | 30 | 25 | 28 |  (Values entered by the user)
    // +----+----+----+

    // 0x3000: City 2's temperature array
    // +----+----+----+
    // | 22 | 19 | 21 |  (Values entered by the user)
    // +----+----+----+


    // Display the temperatures
    printf("\nMonthly temperatures for all cities:\n");
    for (i = 0; i < num_cities; i++) {
        printf("City %d: ", i + 1);
        for (j = 0; j < num_months; j++) {
            printf("%d ", temperatures[i][j]);
        }
        printf("\n");
    }

    // Free the allocated memory
    for (i = 0; i < num_cities; i++) {
        free(temperatures[i]); // Free each city's temperature array
        // 0x2000 and 0x3000: Memory is deallocated (contents are undefined)
    }
    free(temperatures); // Free the array of pointers
    // 0x1000: Memory is deallocated (contents are undefined)

    return 0;
}

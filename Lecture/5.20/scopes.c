#include <stdio.h>

/* Global variable – visible in all functions within this translation unit */
int global_variable = 9;

/* Function prototype */
void local_example(void);

int main(void)
{
    /* Print the global variable from main */
    printf("In main(): global_variable = %d\n", global_variable);

    /* Call the function that demonstrates local scope */
    local_example();

    /* Demonstrate shadowing: a local variable with the same name */
    {
        int global_variable = 3;
        printf("In main() after shadowing block: local global_variable = %d\n",
               global_variable);
    }

    /* Outside the block, the global is unshadowed again */
    printf("Back in main(): global_variable = %d\n", global_variable);

    return 0;
}

void local_example(void)
{
    /* Local variable – only visible within this function */
    int local_variable = 7;

    printf("In local_example(): local_variable = %d\n", local_variable);
    /* The global is still accessible here */
    printf("In local_example(): global_variable = %d\n", global_variable);
}

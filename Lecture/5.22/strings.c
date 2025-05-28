#include <stdio.h>

// Function prototypes
void strings(void);
void access_strings(void);
void modify_strings(void);

int main()
{
    char letter;

    printf("Press a lowercase letter key and then Enter: ");
    scanf("%c", &letter);
    int position = letter - 'a' + 1;
    printf("The letter you entered is the %dth leter in the alphabet.\n", position);

    strings();
    access_strings();
    modify_strings();

    return 0;
}

void strings(void)
{
    char greetings[] = "Hello, World!";
    printf("%s", greetings);
}

// Since strings are actually arrays in C, you can access a string by referring to its index number inside square brackets [].

void access_strings(void)
{
    char greetings[] = "Hello, World!";
    printf("Accessing a String Character");
    // Note that we have to use the %c format specifier to print a single character.
    printf("%c", greetings[0]);
}

void modify_strings()
{
    char greetings[] = "Hello World!";
    printf("Modifying Strings\n");
    printf("Original string: %s\n", greetings);
    greetings[0] = 'J';
    printf("Modified string: %s\n", greetings);
    printf("%s", greetings);
    // Outputs Jello World! instead of Hello World!
}
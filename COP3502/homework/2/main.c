#include <stdio.h>
#include <stdlib.h>

//----- Function prototypes (declarations) -----

/**
 * Dynamically allocate a new string that is a copy of the input string.
 *
 * @param src the source string to copy
 * @return a new dynamically allocated string that is a copy of `src`.
 */
char *str_copy(const char *src);

/**
 * Appends the second string (source string) to the end of the first string (destination string).
 *
 * @param s1 first string
 * @param s2 second string
 * @return a new dynamically allocated string that is the concataction of `s1` and `s2`.
 */
char *str_concat(const char *s1, const char *s2);

/**
 * Calculate the length of a string (excluding the null terminator).
 *
 * @param s the string to measure.
 * @return the length of the string `s`.
 */
int str_len(const char *s);

/**
 * Compare two strings lexicographically.
 *
 * @param s1 first string
 * @param s2 second string
 * @return 0 if equal, negative if less than, positive if greater than
 */
int str_cmp(const char *s1, const char *s2);

/**
 * Free dynamically allocated memory for a string.
 *
 * @param s the string to free
 */
void str_free(char *s);

int main(void)
{
    printf("=== Custom String Library Test ===\n\n");

    // Test str_copy
    const char *original = "Hello, world!";
    char *copy = str_copy(original);
    printf("Original: %s\nCopy: %s\n\n", original, copy);

    // Test str_concat
    const char *part1 = "Dynamic ";
    const char *part2 = "Memory!";
    char *combined = str_concat(part1, part2);
    printf("Concatenation: \"%s\" + \"%s\" = \"%s\"\n\n", part1, part2,
           combined);

    // Test len
    int len = str_len(original);
    printf("Length of \"%s\" = %d\n\n", original, len);

    // Test str_cmp
    const char *cmp1 = "apple";
    const char *cmp2 = "banana";
    int cmp_result = str_cmp(cmp1, cmp2);
    printf("Compare \"%s\" vs \"%s\" = %d\n\n", cmp1, cmp2, cmp_result);

    str_free(copy);
    str_free(combined);

    printf("All tests completed. If no memory leaks occurred, you're good!\n");
    return 0;
}

//----- Function definitions -----

char *str_copy(const char *src)
{
    int len = str_len(src);

    char *new_str = malloc((len + 1) * sizeof(char));

    for (int i = 0; i < len; i++)
    {
        new_str[i] = src[i];
    }

    new_str[len] = '\0';

    return new_str;
}

char *str_concat(const char *s1, const char *s2)
{
    size_t len1 = str_len(s1);
    size_t len2 = str_len(s2);
    char *res = malloc(len1 + len2 + 1);

    if (!res)
    {
        return NULL;
    }

    for (size_t i = 0; i < len1; ++i)
    {
        res[i] = s1[i];
    }

    for (size_t i = 0; i < len2; ++i)
    {
        res[len1 + i] = s2[i];
    }

    res[len1 + len2] = '\0';
    return res;
}

int str_len(const char *src)
{
    const char *ptr = src;

    while (*ptr != '\0')
    {
        ptr++;
    }

    return (int)(ptr - src);
}

int str_cmp(const char *s1, const char *s2)
{
    // Compare characters one by one until a difference is found or end of string is reached
    while (*s1 != '\0' && *s1 == *s2)
    {
        s1++;
        s2++;
    }

    // If we reached the end of one string, check if they are equal
    if (*s1 == *s2)
    {
        return 0;
    }

    // Return the difference between the first differing characters
    if (*s1 < *s2)
    {
        return -1;
    }
    else
    {
        return 1;
    };
}

void str_free(char *s)
{
    free(s);
}
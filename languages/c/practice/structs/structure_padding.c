// When an object of some structure type is declared then some contiguous block of memory will be allocated to structure members.
// On a 32-bit CPU, the word is 4 bytes (32 bits) and can access 4 bytes of memory at a time.
// In one CPU cycle, 4 bytes of memory can be accessed.
// If theres more bytes in a structure than the word size, then the CPU will access the memory in multiple cycles.
// Two cycles will be needed to access 6 bytes of memory in a structure with 6 bytes of memory.
// With padding variable can be accessed in one cycle and the CPU will not waste time accessing memory in multiple cycles.
// Padding is used to align the structure members in memory for efficient access.

#include <stdio.h>

#define BYTE_OR_BYTES(sz)  ((sz) == 1 ? "byte" : "bytes")

// Size of structure members and padding is calculated based on the data types and their alignment requirements.
// This structure in this alignment is 8 bytes in size.
// The first two members are chars (1 byte each), and the third member is an int (4 bytes).
// The compiler adds padding after the first two chars to align the int member on a 4-byte boundary.
// The total size of the structure is 8 bytes, which includes 2 bytes of padding
typedef struct abc
{
    char a; // 1 byte (8 bits)
    char b; // 1 byte (8 bits)
    int c;  // 4 bytes (32 bits)
} abc_t;

int main(void)
{
    abc_t s = {'A', 'B', 1234};
    printf("Size of structure abc: %zu bytes\n", sizeof(s));
    printf("Size of char a: %zu bytes\n", sizeof(s.a));
    printf("Size of char b: %zu bytes\n", sizeof(s.b));
    printf("Size of int c: %zu bytes\n", sizeof(s.c));
    printf("Address of char a: %p\n", (void *)&s.a);
    printf("Address of char b: %p\n", (void *)&s.b);
    printf("Address of int c: %p\n", (void *)&s.c);
    printf("Address of structure abc: %p\n", (void *)&s);

    return 0;
}
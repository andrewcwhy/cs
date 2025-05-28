#include <stdio.h>

void dbl(int val) {
    val = 2*val;
}

int main() {
    int x = 10;
    dbl(x);
    printf("x is %d\n", x);
}
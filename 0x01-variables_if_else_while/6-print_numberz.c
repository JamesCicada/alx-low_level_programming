#include <stdio.h>

int main() {
    int i;
    for(i = 0; i < 10; i = i + 1)
        {
            putchar(48 + i);
        }
    putchar('\n');
    return 0;
}

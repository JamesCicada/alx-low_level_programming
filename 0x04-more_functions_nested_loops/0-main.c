#include "main.h"
#include <stdio.h>

/**
 * main - check the code.
 *
 * Return: Always 0.
 */
int main(void)
{
    char c;

    c = 'r';
    printf("%c: %d\n", c, _isupper(c));
    c = 'C';
    printf("%c: %d\n", c, _isupper(c));
    return (0);
}

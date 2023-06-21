#include <stdio.h>
#include "function_pointers.h"

/**
 * print_name - Prints a given name using the provided function pointer.
 * @name: Pointer to a character array representing the name.
 * @f: Function pointer to a function that can print the name.
 *
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
    if (name != NULL && f != NULL)
        f(name);
}

/**
 * print_name_as_is - Prints a name as is.
 * @name: Name of the person.
 *
 * Return: void
 */
void print_name_as_is(char *name)
{
    printf("Hello, my name is %s\n", name);
}

/**
 * print_name_uppercase - Prints a name in uppercase.
 * @name: Name of the person.
 *
 * Return: void
 */
void print_name_uppercase(char *name)
{
    unsigned int i;

    printf("Hello, my uppercase name is ");
    i = 0;
    while (name[i])
    {
        if (name[i] >= 'a' && name[i] <= 'z')
        {
            putchar(name[i] + 'A' - 'a');
        }
        else
        {
            putchar(name[i]);
        }
        i++;
    }
}

/**
 * main - Entry point of the program.
 *
 * Return: Always 0.
 */
int main(void)
{
    print_name("Bob", print_name_as_is);
    print_name("Bob Dylan", print_name_uppercase);
    printf("\n");
    return 0;
}


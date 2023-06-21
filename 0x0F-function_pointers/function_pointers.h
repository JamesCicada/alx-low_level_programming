#ifndef _FUNCTION_POINTERS_H
#define _FUNCTION_POINTERS_H
#include <stddef.h>

void array_iterator(int *array, size_t size, void (*action)(int));
void print_name(char *name, void (*f)(char *));

#endif /* _FUNCTION_POINTERS_H */


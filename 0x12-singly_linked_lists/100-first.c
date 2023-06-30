#include <stdio.h>
/**
 * pre_main - Prints a message before the main function is executed.
 */
void __attribute__((constructor)) pre_main()
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}

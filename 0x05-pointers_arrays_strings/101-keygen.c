#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generates a random password that satisfies the requirements for
 *        101-crackme.
 *
 * Return: 0 on success.
 */

int main(void)
{
	int i;
	char password[9];
	
	srand(time(NULL));  // Seed the random number generator with the current time

	for (i = 0; i < 6; i++) {
		password[i] = 'a' + rand() % 26;  // Generate a random lowercase letter
	}

	for (i = 6; i < 8; i++) {
		password[i] = '0' + rand() % 10;  // Generate a random digit
	}

	password[8] = '\0';  // Null-terminate the string

	printf("%s", password);

	return 0;
}


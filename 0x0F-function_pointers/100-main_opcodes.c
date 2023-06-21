#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * main.c - A program that prints the opcodes of its own main function.
 *
 * @author Bard
 * @date 2023-06-21
 *
 * Usage: ./main number_of_bytes
 *
 * This program takes a number of bytes as input and prints the opcodes
 * of its own main function for that number of bytes.
 */

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("Error: Incorrect number of arguments\n");
		exit(1);
	}
	
	int nbytes = atoi(argv[1]);
	if (nbytes < 0) {
		printf("Error: Number of bytes must be non-negative\n");
		exit(2);
	}
	
	unsigned char *ptr = (unsigned char *)main;
	
	for (int index = 0; index < nbytes; index++) {
		printf("%02x", ptr[index]);
		if (index != nbytes - 1)
			printf(" ");
	}
	printf("\n");
	return 0;
}


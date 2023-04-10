#include "main.h"

/**
 * main - Entry point
 * @argc: Number of command line arguments
 * @argv: Array containing the command line arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;
	
	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	
	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);
	result = num1 * num2;
	printf("%d\n", result);
	return (0);
}


#include "main.h"

/**
 * main - Copies the contents of a file to another file
 * @argc: Number of arguments
 * @argv: Argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	int f1, f2, r, w, o1, o2;
	char *buffer;

	if (argc != 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	f1 = open(argv[1], O_RDONLY);
	r = read(f1, buffer, 1024);
	f2 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (f1 == -1 || r == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		w = write(f2, buffer, r);
		if (f2 == -1 || w == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		r = read(f1, buffer, 1024);
		f2 = open(argv[2], O_WRONLY | O_APPEND);
	} while (r > 0);

	free(buffer);

	o1 = close(f1);
	if (o1 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", o1);
		exit(100);
	}

	o2 = close(f2);
	if (o2 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", o2);
		exit(100);
	}

	return (0);
}


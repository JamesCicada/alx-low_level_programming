#include "main.h"

/**
 * main - Copies the contents of a file to another file.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 * Return: 0 on success.
 */

int main(int argc, char **argv)
{
	int source_fd, dest_fd, bytes_read, bytes_written, open_result1, open_result2;
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

	source_fd = open(argv[1], O_RDONLY);
	bytes_read = read(source_fd, buffer, 1024);
	dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do
	{
		if (source_fd == -1 || bytes_read == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		bytes_written = write(dest_fd, buffer, bytes_read);

		if (dest_fd == -1 || bytes_written == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		bytes_read = read(source_fd, buffer, 1024);
		open_result2 = open(argv[2], O_WRONLY | O_APPEND);
	} while (bytes_read > 0);

	free(buffer);
	open_result1 = close(source_fd);

	if (open_result1 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", open_result1);
		exit(100);
	}

	open_result2 = close(dest_fd);

	if (open_result2 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", open_result2);
		exit(100);
	}

	return (0);
}


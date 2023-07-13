#include "main.h"

/**
 * read_from_file - Read from file and store in buffer
 * @filename: Name of the file to read
 * @buffer: Buffer to store the read content
 *
 * Return: Number of bytes read, or -1 on failure
 */
ssize_t read_from_file(const char *filename, char *buffer)
{
	int fd, r;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);

	r = read(fd, buffer, 1024);
	if (r == -1)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (r);
}

/**
 * write_to_file - Write content from buffer to file
 * @filename: Name of the file to write to
 * @buffer: Buffer containing the content to write
 * @length: Length of the content to write
 *
 * Return: 1 on success, -1 on failure
 */
int write_to_file(const char *filename, char *buffer, ssize_t length)
{
	int fd, w;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd == -1)
		return (-1);

	w = write(fd, buffer, length);
	if (w == -1)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}

/**
 * main - Copies the contents of a file to another file
 * @argc: Number of arguments
 * @argv: Argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	char *buffer;
	ssize_t r, w;

	if (argc != 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't allocate memory\n");
		exit(99);
	}

	r = read_from_file(argv[1], buffer);
	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		free(buffer);
		exit(98);
	}

	w = write_to_file(argv[2], buffer, r);
	if (w == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		free(buffer);
		exit(99);
	}

	free(buffer);
	return (0);
}


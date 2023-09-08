#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to the standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read from the file.
 * Return: Returns the number of letters read or 0 if an error occurs.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t read_result, open_result, write_result;
	FILE *file_buffer;

	if (filename == NULL)
		return (0);

	file_buffer = malloc(sizeof(*file_buffer) * letters);
	if (file_buffer == NULL)
		return (0);

	open_result = open(filename, O_RDONLY);
	read_result = read(open_result, file_buffer, letters);
	write_result = write(STDOUT_FILENO, file_buffer, read_result);

	if (open_result == -1 || read_result == -1 || write_result == -1 || write_result != read_result)
	{
		free(file_buffer);
		return (0);
	}

	free(file_buffer);
	close(open_result);
	return (write_result);
}


#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: The name of the file to append to.
 * @text_content: The string to append.
 * Return: Returns 1 on success and -1 on failure.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int write_result, file_descriptor, i = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[i] != '\0')
		{
			i++;
		}
	}

	file_descriptor = open(filename, O_WRONLY | O_APPEND);
	write_result = write(file_descriptor, text_content, i);

	if (file_descriptor == -1 || write_result == -1)
		return (-1);

	close(file_descriptor);
	return (1);
}


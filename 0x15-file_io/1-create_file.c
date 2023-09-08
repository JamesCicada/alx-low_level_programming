#include "main.h"

/**
 * create_file - Creates a file with the given content.
 * @filename: The name of the file to create.
 * @text_content: NULL-terminated string to write to the file.
 * Return: Returns -1 if failed, 1 on success.
 */

int create_file(const char *filename, char *text_content)
{
	int fd, i = 0, wr;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[i] != '\0')
		{
			i++;
		}
	}

	wr = write(fd, text_content, i);

	if (wr == -1)
		return (-1);

	close(fd);
	return (1);
}


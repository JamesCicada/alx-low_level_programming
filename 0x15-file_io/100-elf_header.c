#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_error - Prints the error message and exits with status code 98
 * @error_message: The error message to print
 */
void print_error(char *error_message)
{
	dprintf(STDERR_FILENO, "%s\n", error_message);
	exit(98);
}

/**
 * print_magic - Prints the ELF magic bytes
 * @e_ident: Pointer to the ELF identification bytes
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", e_ident[i], i == EI_NIDENT - 1 ? '\n' : ' ');
}

/**
 * print_elf_header - Prints the information from the ELF header
 * @elf_header: Pointer to the ELF header structure
 */
void print_elf_header(Elf64_Ehdr *elf_header)
{
	printf("  Class:                             ");
	switch (elf_header->e_ident[EI_CLASS])
	{
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown>\n");
			break;
	}

	printf("  Data:                              ");
	switch (elf_header->e_ident[EI_DATA])
	{
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown>\n");
			break;
	}

	printf("  Version:                           %d (current)\n",
	       elf_header->e_ident[EI_VERSION]);

	printf("  OS/ABI:                            ");
	switch (elf_header->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		default:
			printf("<unknown: %x>\n", elf_header->e_ident[EI_OSABI]);
			break;
	}

	printf("  ABI Version:                       %d\n",
	       elf_header->e_ident[EI_ABIVERSION]);

	printf("  Type:                              ");
	switch (elf_header->e_type)
	{
		case ET_NONE:
			printf("NONE (Unknown type)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", elf_header->e_type);
			break;
	}

	printf("  Entry point address:               %#lx\n",
	       (unsigned long)elf_header->e_entry);
}

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr elf_header;

	if (argc != 2)
		print_error("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Error: Cannot open file");

	if (read(fd, &elf_header, sizeof(elf_header)) == -1)
		print_error("Error: Cannot read from file");

	if (lseek(fd, 0, SEEK_SET) == -1)
		print_error("Error: Cannot seek in file");

	printf("ELF Header:\n");
	print_magic(elf_header.e_ident);
	print_elf_header(&elf_header);

	close(fd);
	return (0);
}


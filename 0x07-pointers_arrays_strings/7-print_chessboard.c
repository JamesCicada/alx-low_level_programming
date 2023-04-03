#include "main.h"

/**
 * print_chessboard - prints the chessboard
 * @a: the 2D array containing the chessboard
 *
 * Return: void
 */
void print_chessboard(char (*a))
{
	int row, col;
	for (row = 0; row < 8; row++)
	{
		for (col = 0; col < 8; col++)
			_putchar(a[row][col]);
		_putchar('\n');
	}
}


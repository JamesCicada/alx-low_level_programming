#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all possible combinations of two digits, in ascending
 * order, separated by a comma followed by a space, without using char variables
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i, f;

	i = 48;
	f = 48;

	while (f < 58)
	{
		i = 48;
		while (i < 58)
		{
			if (f != i && f < i)
			{
				putchar(f);
				putchar(i);
				if (i == 57 && f == 56)
				{
					break;
				}
				putchar(',');
				putchar(' ');
			}
			i++;
		}
		f++;
	}
	putchar('\n');
	return (0);
}

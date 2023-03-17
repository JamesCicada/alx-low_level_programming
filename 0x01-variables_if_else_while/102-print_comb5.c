#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all possible combinations of two two-digit numbers.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i, f;

	for (i = 0; i < 100; i++)
	{
		for (f = 0; f < 100; f++)
		{
			if (i < f)
			{
				putchar((i / 10) + 48);
				putchar((i % 10) + 48);
				putchar(' ');
				putchar((f / 10) + 48);
				putchar((f % 10) + 48);
				if (i != 98 || f != 99)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}

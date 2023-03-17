#include <stdio.h>

int main() {
	int i;
    char ch;
	for (i = 48; i < 58; i++)
	{
		putchar(i);
	}
	for (ch = 'a'; ch <= 'f'; ch++)
	{
		putchar(ch);
	}
	putchar('\n');
    return 0;
    
}

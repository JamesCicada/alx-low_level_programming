#include <stdio.h>

int main() {
	int i;

	for (i = 0; i < 10 ; i++)
	    {
	        putchar(48 + i);
	        if (i != 9){
	            putchar(',');
	            putchar(' ');
	        }
	    }
	putchar('\n');
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i;
	char password[9];
	
	srand(time(NULL));

	for (i = 0; i < 6; i++) {
		password[i] = 'a' + rand() % 26;
	}

	for (i = 6; i < 8; i++) {
		password[i] = '0' + rand() % 10;
	}

	password[8] = '\0';

	printf("%s", password);

	return 0;
}


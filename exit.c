#include <stdio.h>

#include <stdlib.h>

int aff()
{   printf("cc\n");
	exit(1);
	printf("cc");
}
int main()
{    
	aff();
	printf("cc\n");
	printf("cc");
}

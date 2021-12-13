#include <stdio.h>
#include <stdlib.h>



int randomize()
{
	return(rand() % 10);
}


int main()
{
	int r;
	srand(time(NULL));
		do{
			r=randomize();
		printf("%d\n",r);
		getch();
	}		while(1);
	
}

#include <stdio.h>
#include <conio.h>

int testH()
{   int i;
	for(i=1;i<6;i++)
	{printf("jjj\n");
    if(i==3)return(1); 
}
return(0);
}
int main()
{   int i; 
	i=testH();
	printf("%d",i);
	getch();
}

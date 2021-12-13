#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

char t[6][7];
char cc1='N';
char cc2='R';
int comm=1;

void intialisation()
{
	 int k,l;
     for(k=0;k<6;k++)
        for(l=0;l<7;l++)
        t[k][l]=' ';
}

int main()
{ 
Color(0,15);
srand(time(NULL));
menu();
}

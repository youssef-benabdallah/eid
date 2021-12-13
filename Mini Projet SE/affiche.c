#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>


void tete()
{
	system("cls");
	printf("================================================================================");
    printf("                    Mini Projet Systeme d'exploitation LFI2\n");
    printf("================================================================================\n\n\n");
}

void affiche()
{
int i,j;
tete();
// en tete
printf("\n\n                               1   2   3   4   5   6   7\n                             \xDA\xC4");
for(i=0;i<6;i++)
    printf("\xC4\xC4\xC2\xC4");  
printf("\xC4\xC4\xC4\b\xBF\n");
// milieu
for(j=0;j<5;j++)
{
	printf("                            %d ",j+1);	
for(i=0;i<7;i++)
{
char c=t[j][i];

printf("\b\xB3 ");
if(c=='R') Color(12,15);
else  Color(0,15);
	printf("%c  ",c);
Color(0,15);
}
printf("\b\xB3\n                             \xC3\xC4\xC4\xC4\xC5");	
for(i=0;i<6;i++)
     printf("\xC4\xC4\xC4\xC5");  
printf("\b\xB4 \n");
}
// pied
printf("                            6 ");
for(i=0;i<7;i++)
{
    char c=t[5][i];
    Color(0,15);
	printf("\b\xB3");
	if(c=='R') Color(12,15);
	printf(" %c  ",c);
	Color(0,15);
}

printf("\b\xB3\n                             \xC0");
for(i=0;i<6;i++)
	printf("\xC4\xC4\xC4\xC1");
printf("\xC4\xC4\xC4\xC4\b\xD9\n\n\n");
}

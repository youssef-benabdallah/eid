#include <stdio.h>
#include <conio.h>
char t[7][6];
int nb=0;
void affiche()
{   
int i,j;
printf("\xDA\xC4");

for(i=0;i<6;i++)
    printf("\xC4\xC2\xC4");  
printf("\xC4\xC4\b\xBF\n");

for(j=0;j<5;j++)
{

for(i=0;i<7;i++)
	printf("\b\xB3 %c ",t[j][i]);
printf("\b\xB3\n");


	
printf("\xC3\xC4\xC4\xC5");
for(i=0;i<6;i++)
   printf("\xC4\xC4\xC5");
 printf("\b\xB4 \n");

}


for(i=0;i<7;i++)
	printf("\b\xB3   ");

printf("\b\xB3\n");


printf("\xC0");

for(i=0;i<6;i++)
   printf("\xC4\xC4\xC1");
   printf("\xC4\xC4\xC4\b\xD9");
printf("\n\n\n");

}



int main()
{    
	affiche();   
		getch();
}

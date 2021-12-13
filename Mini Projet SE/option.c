#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

int option()
{   char pos[]="";
	char cc;
	Y:
	system("cls");
	tete();
	printf("                         \xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4 Option \xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n                          \b\xB3                                 \b\xB3\n");
    printf("                          \b\xB3                                 \b\xB3\n                          \b\xB3 1) Changer la couleur.          \b\xB3\n");
    printf("                          \b\xB3                                 \b\xB3\n                          \b\xB3 2) Changer le controle.         \b\xB3\n");
    printf("                          \b\xB3                                 \b\xB3\n                          \b\xB3 3) Retourne au menu principale. \b\xB3\n");
	printf("                          \b\xB3                                 \b\xB3\n                         \xC3\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\b\xB4\n");
	printf("                          \b\xB3  ");
	if(cc2=='R') Color(12,15);
	printf("Joueur 1 (%c)",cc2);
	Color(0,15);
	printf("   \b\xB3  ");
	if(cc1=='R') Color(12,15);
	printf("Joueur 2 (%c)",cc1);
	Color(0,15);
	printf("  \b\xB3\n");
	printf("                         \xC3\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\b\xB4",cc1);
	printf("                                               \b\xB3          ");
	if(comm==0)printf("Numero de case");
	else       printf("Avec direction");
	printf("         \b\xB3\n");
	printf("                         \xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\b\xD9\n\n\n\n",cc1);
	printf(" Donner votre choix ");
	scanf("%s",pos);
	if (stricmp(pos,"1") == 0)
	    	{
            	cc=cc1;
	            cc1=cc2;
             	cc2=cc;
	    	}
	    	else if(stricmp(pos,"2") == 0) 
	    	{
	    		if(comm==0)comm=1;
	    		else comm=0;
	    	}
			else if(stricmp(pos,"3") == 0) return(0);
	    	else
			{
			printf("\n Choix incorrect!!\n");
			getch();
	        }
	        goto Y;
}

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <main.h>

int serveur()
{  
    char j1[20],j2[20],aux[20];
	char pos[]="";
    int n,l,c,a;
    tete();
    printf(">> Donner le nom de la Joueur 1  ");
    scanf("%s",j2);
    Y:
    printf("\n>> Donner le nom de la Joueur 2  ");
    scanf("%s",j1);
    if(stricmp(j1,j2) == 0) 
	{
    printf("\nChoisir un nom different!!\n");
    goto Y;
    }
    
	int r;
		do
		{
		    r = rand() %10;
	    }   while((r!=1)&&(r!=2));
	
	if (r==2) 
	{
	strcpy(aux,j2);
	strcpy(j2,j1);
	strcpy(j1,aux);
    }
    W:
    intialisation();
    for(c=2;c>=0;c--){
    	tete();
    	printf("\n>>> %s va jouer le premier\n\n",j2);
        printf(">>> Le jeu va commencer dans %d seconde(s)",c);
        attendre(1);
    }
    int nb=0;
	char c1=cc1;
    char c2=cc2;
    char cc;	
    affiche();
	Z:
	if(comm==0)affiche();
	strcpy(aux,j2);
	strcpy(j2,j1);
	strcpy(j1,aux);
	cc=c1;
	c1=c2;
	c2=cc;
	T:	
	if(comm==0)affiche();	
	r=joueur(pos,&l,&c,j1,c1,1);
    if ((test(pos)==0)&&(comm==0))
	{
	joueur(pos,&l,&c,j1,c1,2);
	getch();
	goto T;
    }	
	if((stricmp(pos,"q") == 0)||(stricmp(pos,"Q") == 0)||(r==0))
	{   tete();
	    joueur(pos,&l,&c,j1,c1,5);
		joueur(pos,&l,&c,j2,c1,6);
		printf("> Appuiyer sur une touche pour retourner au menu principale...");
		getch();
		return(0);
	}
	else if(comm==0)
	{
	c = atoi(pos);
	c--;
	l=0;
	while((t[l][c]==' ')&&(l<6))
	{
	l++;
	}
	l--;
	}
	if((l==-1)&&(comm==0)) 
	{  	  
	   joueur(pos,&l,&c,j1,c1,4);
	   getch();
	   goto T;
    }
	else 
	{
	    t[l][c]=c1;
	    nb+=1;
	    if(nb>6)
	    {
	    	a=(testH(l,c,c1)||testV(l,c,c1)||testDD(l,c,c1)||testDG(l,c,c1));
	    if (a||(nb==42))
	    {   affiche();
	        if(a)
			{   joueur(pos,&l,&c,j1,c1,0);
			}else	printf(">> Pas de gagnant\n\n");
	    	getch();	    	
	    	K:
	    		tete();
	    		printf("\n\n> Voulez vous jouer un autre fois O/N  ");
	    	joueur(pos,&l,&c,j1,c1,3);
	    	if ((stricmp(pos,"O") == 0)||(stricmp(pos,"o") == 0))
	    	{   if(c1==cc1)
	    	{
	    		strcpy(aux,j2);
             	strcpy(j2,j1);
            	strcpy(j1,aux);
	    	}
            	goto W;
	    	}
			else if((stricmp(pos,"N") == 0)||(stricmp(pos,"n") == 0)) return(0);
	    	else
			{
			joueur(pos,&l,&c,j1,c1,2);
			getch();
	    	goto K;
	        }
	    }   
	}
	goto Z;
	}
}

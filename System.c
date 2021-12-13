 #include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char t[6][7];
int nb=0;
int nbj=0;
void affiche()
{
int i,j;
system("cls");
// en tete
printf("================================================================================");
printf("                    Mini Projet Systeme d'exploitation LFI2\n");
printf("================================================================================");
printf("\n\n                               1  2  3  4  5  6  7\n                             \xDA\xC4");

for(i=0;i<6;i++)
     printf("\xC4\xC2\xC4");  
printf("\xC4\xC4\b\xBF\n");
// milieu
for(j=0;j<5;j++)
{
	printf("                            %d ",j+1);	
for(i=0;i<7;i++)
	printf("\b\xB3 %c ",t[j][i]);

printf("\b\xB3\n                             \xC3\xC4\xC4\xC5");	
for(i=0;i<6;i++)
     printf("\xC4\xC4\xC5");
printf("\b\xB4 \n");
}
// pied
printf("                            6 ");

for(i=0;i<7;i++)
	printf("\b\xB3 %c ",t[5][i]);

printf("\b\xB3\n                             \xC0");

for(i=0;i<6;i++)
	printf("\xC4\xC4\xC1");
printf("\xC4\xC4\xC4\b\xD9\n\n\n");

}
int test(char *choix)
{
	if(strlen(choix)==2)
	{
	    if((choix[0]>'0')&&(choix[0]<'7')&&(choix[1]>'0')&&(choix[1]<'8'))
		return(1);
	}else if((strlen(choix)==1)&& ((stricmp(choix,"q") == 0)||(stricmp(choix,"Q") == 0))) 
	    return(1);
	return(0);
	
}
int testH(int l,int c,char cl)
{
  int i;
  i=c-1;
  
  int nbc=1;
  while((i>=0)&&(t[l][i]==cl)&&(nbc<4))
  {
  i--;
  nbc++;
  }
  if(nbc==4) return(1);
  i=c+1;
  while((i<7)&&(t[l][i]==cl)&&(nbc<4))
  {
  i++;
  nbc++;
  }
  if(nbc==4) return(1);
  return(0);

}

int testV(int l,int c,char cl)
{
  int i;
  i=l-1;
  int nbc=1;
  while((i>=0)&&(t[i][c]==cl)&&(nbc<4))
  {
  i--;
  nbc++;
  }
  if(nbc==4) return(1);
  i=l+1;
  while((i<6)&&(t[i][c]==cl)&&(nbc<4))
  {
  i++;
  nbc++;
  }
  if(nbc==4) return(1);
  return(0);

}

int testDD(int l,int c,char cl)
{
  int il,ic;
  il=l-1;
  ic=c+1;
  
  int nbc=1;  
  while((il>=0)&&(ic<7)&&(t[il][ic]==cl)&&(nbc<4))
  {
  il--;
  ic++;
  nbc++;
  }
  if(nbc==4) return(1);
  il=l+1;
  ic=c-1;
  while((il<6)&&(ic>=0)&&(t[il][ic]==cl)&&(nbc<4))
  {
  il++;
  ic--;
  nbc++;
  }
  if(nbc==4) return(1);
  return(0);

}

int testDG(int l,int c,char cl)
{
	
  int il,ic;
  il=l-1;
  ic=c-1;
  
  int nbc=1;  
  while((il>=0)&&(ic>=0)&&(t[il][ic]==cl)&&(nbc<4))
  {
  il--;
  ic--;
  nbc++;
  }
  if(nbc==4) return(1);
  il=l+1;
  ic=c+1;
  while((il<6)&&(ic<7)&&(t[il][ic]==cl)&&(nbc<4))
  {
  il++;
  ic--;
  nbc++;
  }
  if(nbc==4) return(1);
  return(0);

}

char * joueur()
{  
   char *ca;
	scanf("%s",ca);
	
	return(ca);

}

int serveur()
{  
    char j1[20],j2[20],aux[20];
	char *pos;
    char c1='N';
	char c2='R';
	char cc;
    int n,l,c;
    
    printf("Donner le nom de la Joueur 1  ");
    scanf("%s",&j2);
    Y:
    printf("Donner le nom de la Joueur 2  ");
    scanf("%s",&j1);
    if(stricmp(j1,j2) == 0) 
	{
    printf("Vous pouvez choisir un autre nom!!\n");
    goto Y;
    }
    
	int r;
		do{
		r = rand() %10;
	}		while((r!=1)&&(r!=2));
	
	if (r==2) 
	{
	strcpy(aux,j2);
	strcpy(j2,j1);
	strcpy(j1,aux);
    }
    W:
    printf("%s va commencer\n",j1);
	printf("Appuiyer sur une touche pour commencer... \n");	
	getch();
		
	Z:
	affiche();
	strcpy(aux,j2);
	strcpy(j2,j1);
	strcpy(j1,aux);
	cc=c1;
	c1=c2;
	c2=cc;
	printf("%s va jouer (%c)\n\nDonner le numero de la case ou Taper 'Q' pour Quitter\n",j1,c1);
	
	pos=joueur();
	do
	{
	affiche();
	printf("Choix incorrect choisissez un autre\n");
	}while (test(pos)==0);
	
	if((stricmp(pos,"q") == 0)||(stricmp(pos,"Q") == 0))
	{
		printf("%s Vous avez quittez le jeu\n %s, Vous etes le vainqueur\n\n",j1,j2);
		printf("Appuiyer sur une une touche pour retourner au menu principale...");
		getch();
		return(0);
	}
	else
	{
	n = atoi(pos);
	l=n/10;
	c=n%10;
	l--;c--;
    }
	if((t[l][c]=='R')||(t[l][c]=='N')) 
	{
	   printf("Deja occuper ressayer un autre\n");
	   goto Z;
    }
	else 
	{
	    t[l][c]=c1;
	    nb+=2;
	    if(nb>5)
	    {
	    if (testH(l,c,c1)||testV(l,c,c1)||testDD(l,c,c1)||testDG(l,c,c1)) 
	    {    
	    	printf("%s vous avez gagner\n\n");
	    	K:
	    		printf("Voulez vous jouer un autre fois O/N  ",j1);
	    	scanf("%s",aux);
	    	if ((stricmp(aux,"O") == 0)||(stricmp(aux,"o") == 0))
	    	{
	    		strcpy(aux,j2);
             	strcpy(j2,j1);
            	strcpy(j1,aux);
            	goto W;
	    	}
			else if((stricmp(aux,"N") == 0)||(stricmp(aux,"n") == 0)) return(0);
	    	else
			{
			printf("Choix incorrect!!\n");
	    	goto K;
	        }
	    }
	    if(nb==42) 
		{
		    printf("NULL");
		    goto K;
	    }
	}
	goto Z;
	}
}
 
void menu()
{   char *choix;
    T:
	system("cls");
	printf("================================================================================");
	printf("                    Mini Projet Systeme d'exploitation LFI2\n");
    printf("================================================================================\n\n\n\n");
    printf("                    ============ Menu ============\n\n\n");
    printf("                        1)Commencer une partie.\n\n");
    printf("                        2)Options.\n\n");
    printf("                        3)Instructions.\n\n");
    printf("                        4)Quittez.\n\n");
    
    
	 printf("Donner votre choix\n");
	 scanf("%s",choix);
	 if(stricmp(choix,"1") == 0) serveur();
	 else if(stricmp(choix,"2") == 0) printf("option");
	 else if(stricmp(choix,"3") == 0) printf("instruction");
	 else if(stricmp(choix,"4") == 0) exit(0);
	 else {
	      printf("Choix incorrect\n");
	      getch();
	      }
	    goto T;
	     
}
int main()
{  int k,l;

for(k=0;k<6;k++)
        for(l=0;l<7;l++)
        t[k][l]=' ';
menu();
getch();
 
}

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

char t[6][7];
char cc1='N';
char cc2='R';
void Color(int couleurDuTexte,int couleurDeFond) 
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
void attendre(float temps)
{
    clock_t seconde=clock()+(temps*CLOCKS_PER_SEC); 

    while(clock()<seconde);
}

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
	printf("\b\xB3 %c  ",t[5][i]);

printf("\b\xB3\n                             \xC0");

for(i=0;i<6;i++)
	printf("\xC4\xC4\xC4\xC1");
printf("\xC4\xC4\xC4\xC4\b\xD9\n\n\n");

}
void intialisation()
{
	 int k,l;

for(k=0;k<6;k++)
        for(l=0;l<7;l++)
        t[k][l]=' ';
        t[4][4]='N';
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


char * joueur(char * ca) 
{   
    scanf("%s",ca);
}

int option()
{   char pos[]="";
	char cc;
	Y:
		system("cls");
	tete();
	 printf("                         \xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4 Option \xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n                          \b\xB3                                 \b\xB3\n");
    printf("                          \b\xB3                                 \b\xB3\n                          \b\xB3 1) Changer la couleur.          \b\xB3\n");
    printf("                          \b\xB3                                 \b\xB3\n                          \b\xB3 2) Retourne au menu principale. \b\xB3\n");
	printf("                          \b\xB3                                 \b\xB3\n                         \xC3\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\b\xB4\n");
    
	printf("                          \b\xB3  Joueur 1 (%c)   \b\xB3  Joueur 2 (%c)  \b\xB3\n",cc2,cc1);
	printf("                         \xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\b\xD9\n\n\n\n",cc1);
	
	
	
	printf(" Donner votre choix\n\n");
	joueur(pos);
	if (stricmp(pos,"1") == 0)
	    	{
            	cc=cc1;
	            cc1=cc2;
             	cc2=cc;
             	goto Y;
	    	}
			else if(stricmp(pos,"2") == 0) return(0);
	    	else
			{
			printf("\n Choix incorrect!!\n");
			getch();
	    	goto Y;
	        }
}

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
    printf("\nVous pouvez choisir un autre nom!!\n");
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
	Z:
	affiche();
	strcpy(aux,j2);
	strcpy(j2,j1);
	strcpy(j1,aux);
	cc=c1;
	c1=c2;
	c2=cc;
	T:
	affiche();
	printf(">> %s (%c)\n\n> Donner le numero de la case ou Taper 'Q' pour Quitter\n\n",j1,c1);
	
	joueur(pos);
    if (test(pos)==0)
	{
	printf("\n> Choix incorrect choisissez un autre\n");
	getch();
	goto T;
    }
	
	if((stricmp(pos,"q") == 0)||(stricmp(pos,"Q") == 0))
	{   tete();
		printf("\n\n>> %s, Vous avez quittez le jeu.\n\n>> %s, Vous etes le vainqueur.\n\n",j1,j2);
		printf("> Appuiyer sur une une touche pour retourner au menu principale...");
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
	   printf("\n> Deja occuper choisissez un autre\n");
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
			{   printf(">> %s vous avez gagner\n\n",j1);
			}else	printf(">> Pas de gagnant\n\n");
	         
	    	getch();
	    	
	    	K:
	    		tete();
	    		printf("\n\n> Voulez vous jouer un autre fois O/N  ");
	    	joueur(pos);
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
			printf("\n> Choix incorrect!!\n");
			getch();
	    	goto K;
	        }
	    }
	     
		
	}
	goto Z;
	}
}
 
void menu()
{   char choix[]="";
    T:
    tete();
    printf("                         \xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4 Menu \xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n                          \b\xB3                               \b\xB3\n");
    printf("                          \b\xB3                               \b\xB3\n                          \b\xB3    1) Commencer une partie.   \b\xB3\n");
    printf("                          \b\xB3                               \b\xB3\n                          \b\xB3    2) Options.                \b\xB3\n");
    printf("                          \b\xB3                               \b\xB3\n                          \b\xB3    3) Instructions.           \b\xB3\n");
    printf("                          \b\xB3                               \b\xB3\n                          \b\xB3    4) Quittez.                \b\xB3\n");
	printf("                          \b\xB3                               \b\xB3\n                         \xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n\n");
    
    
	 printf("> Donner votre choix :  ");
	 joueur(choix);
	 if(stricmp(choix,"1") == 0) serveur();
	 else if(stricmp(choix,"2") == 0) option();
	 else if(stricmp(choix,"3") == 0) printf("instruction");
	 else if(stricmp(choix,"4") == 0) exit(0);
	 else {
	      printf(" Choix incorrect\n");
	      getch();
	      }
	    goto T;
	     
}
int main()
{ 
Color(0,15);
srand(time(NULL));
menu();
}

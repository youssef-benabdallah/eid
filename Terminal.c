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


void tete()
{
	system("cls");
	printf("================================================================================");
    printf("                    Mini Projet Systeme d'exploitation LFI2\n");
    printf("================================================================================\n\n\n");
}

void instruction()
{  
    tete();
	printf("                      \xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4 Instructions \xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n                       \b\xB3                                       \b\xB3\n");
    printf("                       \b\xB3                                       \b\xB3\n                       \b\xB3 > Pour mettre un pion, utiliser les   \b\xB3\n");
    printf("                       \b\xB3                                       \b\xB3\n                       \b\xB3  touches de direction 'A' et 'D' ou   \b\xB3\n");
    printf("                       \b\xB3                                       \b\xB3\n                       \b\xB3  choisir le numero de la case.        \b\xB3\n");
    printf("                       \b\xB3                                       \b\xB3\n                       \b\xB3 > Le jeu est terminee lorsque l'un de \b\xB3\n");
    printf("                       \b\xB3                                       \b\xB3\n                       \b\xB3  deux joueurs avoir 4 pions de meme   \b\xB3\n");
    printf("                       \b\xB3                                       \b\xB3\n                       \b\xB3  couleur successives.                 \b\xB3\n");
   	printf("                       \b\xB3                                       \b\xB3          ");
	printf("                              \xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\b\xD9\n\n");
	printf("> Appuiyer sur une touche pour retourner au menu principale...");
	getch();	
}

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
void intialisation()
{
	 int k,l;
     for(k=0;k<6;k++)
        for(l=0;l<7;l++)
        t[k][l]=' ';
}

int test(char *choix)
{
	if(strlen(choix)==1)
	    if((choix[0]>'0')&&(choix[0]<'8')||((stricmp(choix,"q") == 0)||(stricmp(choix,"Q") == 0)))
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
  	//printf("%c",t[il][ic]);
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
  ic++;
  nbc++;
  }
  if(nbc==4) return(1);
  return(0);
}

void gotoxy(int x, int y)
  {
    COORD point;
    point.X = x; point.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),point);
  }
  
int joueur(char * ca,int *ll,int *cc,char *j1,char c1,int r) 
    {  
    if(r==6)
    {
    	printf("\n\n>> %s, Vous etes le vainqueur.\n\n",j1);
    	return(0);
    }else
    if(r==5)
    {
    	printf("\n\n>> %s, Vous avez quittez le jeu.",j1);
    	return(0);
    }else
    if(r==4)
    { printf("\n\n> Deja occuper choisissez un autre\n");
    return(0);
    }else
    if(r==0) {
    printf(">> %s (",j1);
    if(c1=='R')  Color(12,15);  
	printf("%c",c1);
	Color(0,15); 
	printf(") vous avez gagner\n\n");
    return(0);
     }else
    if(r==2)
    {
	printf("\n\n> Choix incorrect!!\n");
	return(0);
    }else
    if(r==3)
    {
    	scanf("%s",ca);
    	return(0);
    }
	 if(comm==1)
    {
	char c;
    int i=55;
   	int j=20;
   	int ii,jj,cl,l,a;
   	cl=(i-31)/4;
    l=(j-10)/2;
    while(((t[l][cl]=='R')||(t[l][cl]=='N'))&&(l<6))
    {
     if(cl==0)
	 {
     l--;
     cl=7;
	 }
     cl--;
    }
    i=4*cl+31;
    j=2*l+10;   	   	
    while(1)
    {        
    cl=(i-31)/4;
    l=(j-10)/2;    
    gotoxy(i,j);
    Color(13,15);
    printf("X");
    Color(0,15);
    gotoxy(0,13);
    printf(">> %s (      ",j1);
    gotoxy(strlen(j1)+5,13);
    if(c1=='R')  Color(12,15);  
	printf("%c",c1);
	Color(0,15);
	printf(")\n\n> Taper sur (F)\n\n  pour confirmer.");
	printf("\n\n> Taper 'Q' pour Quitter.\n\n");
    c=getch();
    ii=i;
    jj=j;
    if((c=='d')||(c=='D'))
    {
	cl++;	
	if(cl==7) 
	{
	cl=0;
	ii=27;
    }    
    D:
    a=5;
	jj=20;
	while((t[a][cl]!=' ')&&(a>-1))
	{
     a--;
	if(a==-1)
	{
		cl++;
		if(cl==7)
		{
			cl=0;
			ii=23;
		}
		ii+=4;
		goto D;
	}
	jj-=2;
	}	
	gotoxy(i,j);
	printf(" ");
	i=ii+4;
	j=jj;
    }else
    if((c=='a')||(c=='A'))
	{
	cl--;	
	if(cl==-1) 
	{
	cl=6;
	ii=59;
    }    
    A:
    a=5;
	jj=20;
	while((t[a][cl]!=' ')&&(a>-1))
	{
     a--;
	if(a==-1)
	{
		cl--;
		if(cl==-1)
		{
			cl=6;
			ii=63;
		}
		ii-=4;
		goto A;
	}
	jj-=2;
	}	
	gotoxy(i,j);
	printf(" ");
	i=ii-4;
	j=jj;
    }else
    if((c=='f')||(c=='F')) 
	{   gotoxy(i,j);
	   if(c1=='R')  Color(12,15);  
	   printf("%c",c1);
	   Color(0,15);
		*ll=l;
		*cc=cl;		
	    return 1;
    }else
    if((c=='q')||(c=='Q')) 
	{
	return 0;
    }
}
}
    else 
    {
      gotoxy(0,11);
      printf(">> %s (",j1);
      if(c1=='R') Color(12,15);
      printf("%c",c1);
      Color(0,15);
      printf(")\n\n\n> Donner le numero de\n\n  la case.\n\n> Taper 'Q' pour Quitter.\n\n\n\n");
      scanf("%s",ca);
    }
}

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
    for(c=5;c>=1;c--){
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
 
void menu()
{   
    char choix[]="";
    T:
    tete();
    printf("                         \xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4 Menu \xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n                          \b\xB3                               \b\xB3\n");
    printf("                          \b\xB3                               \b\xB3\n                          \b\xB3    1) Commencer une partie.   \b\xB3\n");
    printf("                          \b\xB3                               \b\xB3\n                          \b\xB3    2) Options.                \b\xB3\n");
    printf("                          \b\xB3                               \b\xB3\n                          \b\xB3    3) Instructions.           \b\xB3\n");
    printf("                          \b\xB3                               \b\xB3\n                          \b\xB3    4) Quittez.                \b\xB3\n");
	printf("                          \b\xB3                               \b\xB3\n                         \xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n\n");
    printf("> Donner votre choix :  ");
	 scanf("%s",choix);
	 if(stricmp(choix,"1") == 0) serveur();
	 else if(stricmp(choix,"2") == 0) option();
	 else if(stricmp(choix,"3") == 0) instruction();
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

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

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



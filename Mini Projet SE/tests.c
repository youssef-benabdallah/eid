#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

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
  ic--;
  nbc++;
  }
  if(nbc==4) return(1);
  return(0);
}

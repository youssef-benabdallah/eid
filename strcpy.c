#include <stdlib.h>
#include<stdio.h>
#include<string.h>

int main()
{char j1[20]="aaa";
  char j2[20]="bbb";
  char aux[20];
  printf("%s\n%s\n",j1,j2);
                strcpy(aux,j2);
             	strcpy(j2,j1);
            	strcpy(j1,aux);
  printf("%s\n%s\n",j1,j2);
}

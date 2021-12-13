#include <stdio.h>
#include <string.h>

void get_string(char * Buffer) 
{   
    scanf("%s",Buffer);
   
  
} 
  
int main(void) 
{ 
    char Buffer[100]; 
  
    get_string(Buffer); 
    while (1);
	{
	printf("%s va jouer (%c)\n\nChoix incorrect choisissez un autre\n");
	joueur(pos);
	affiche();
    }
    return 0; 
}


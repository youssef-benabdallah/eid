#include <stdio.h> // Les includes
#include <stdlib.h>
#include <windows.h>
 
void Color(int couleurDuTexte,int couleurDeFond);
 
int main(int argc, char *argv[]) // La fonction "main"
{
	int i;
	for(i=1;i<=20;i++)
	{
   Color(i,0);
   printf("La ton texte va avoir la couleur 12 comme texte et 3 pour fond\n");
   getch();
}
   Color(15, 0);
   //... aprés c'est parti
 
   return 0;
}
 
void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


//srand(time(0));
int main(int argc, char *argv[])
{
    char chaine[] = "Salut";
    int longueurChaine = 0;

    // On r�cup�re la longueur de la cha�ne dans longueurChaine
    longueurChaine = strlen(chaine);

    // On affiche la longueur de la cha�ne
    printf("La chaine %s fait %d caracteres de long", chaine, longueurChaine);

    return 0;
}

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

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


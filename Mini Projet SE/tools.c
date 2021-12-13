#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

void gotoxy(int x, int y)
  {
    COORD point;
    point.X = x; point.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),point);
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

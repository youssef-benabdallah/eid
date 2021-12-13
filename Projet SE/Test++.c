#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>
#include <time.h> 
#include <windows.h>
#include <ctype.h>

int main()
{
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
    COORD  Pos; 
  
    Pos.X = 10; 
    Pos.Y = 9; 
  
    SetConsoleCursorPosition(hConsole, Pos); 
   printf("\033[u;uH"); 

}

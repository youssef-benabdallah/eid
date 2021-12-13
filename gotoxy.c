#include <stdio.h>
#include <windows.h>
void gotoxy(int x, int y)
  {
    COORD point;
    point.X = x; point.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),point);
  }
  
  int main()
  {
  	gotoxy(7,7);
  	printf("AAAA\n");
  
  	printf("BBB");
  }

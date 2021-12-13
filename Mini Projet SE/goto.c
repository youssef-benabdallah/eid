#include<stdio.h>
//gotoxy function
void gotoxy(int x,int y)
{
printf("%c[%d;%df",0x1B,y,x);
}
main ()
{
gotoxy(25,50); //reposition cursor
printf("\033[2J\033[0;0f""iiiii");
}


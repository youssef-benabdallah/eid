#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

void menu()
{   
char email[7];
char i1,i2,i3,i4,i5,i6,i7;
FILE mail;
mail = fopen("mail.txt","a+");
for(i1='-';i1<='z';i1++)
{
	for(i2='-';i2<='z';i2++)
{
	for(i3='-';i3<='z';i3++)
{
	for(i4='-';i4<='z';i4++)
{
	for(i5='-';i5<='z';i5++)
{
	for(i6='-';i6<='z';i6++)
{
	for(i7='-';i7<='z';i7++)
{
	email[0]=i1;
	email[1]=i2;
	email[2]=i3;
	email[3]=i4;
	email[4]=i5;
	email[5]=i6;
	email[6]=i7;
	fprintf(mail,"o%si@live.com;\n",email);
	if(i7=='.') i7='/';
	if(i7=='9') i7='^';
	if(i7=='_') i7=96;
}
	if(i6=='.') i6='/';
	if(i6=='9') i6='^';
	if(i6=='_') i6=96;
}
	if(i5=='.') i5='/';
	if(i5=='9') i5='^';
	if(i5=='_') i5=96;
}
	if(i4=='.') i4='/';
	if(i4=='9') i4='^';
	if(i4=='_') i4=96;
}
	if(i3=='.') i3='/';
	if(i3=='9') i3='^';
	if(i3=='_') i3=96;
}
	if(i2=='.') i2='/';
	if(i2=='9') i2='^';
	if(i2=='_') i2=96;
}
	if(i1=='.') i1='/';
	if(i1=='9') i1='^';
	if(i1=='_') i1=96;
}
   
   
}

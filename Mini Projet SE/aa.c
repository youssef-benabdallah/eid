#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
char s[256];
strcpy(s, "one:two:three");
char* token = strtok(s, ":");
while (token) {
    printf("token: %s\n", token);
    token = strtok(NULL, ":");
}
char *turing2[] = { 
  "Perlis",
  "Wilkes",
  "Hamming",
  "Minsky",
  "Wilkinson",
  "McCarthy",
  "Dijkstra",
  "Bachman",
  "Knuth",
  "Newell et Simon"
};
printf("token: %s\n", turing2[1]);
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAILLE 256

int main()
{   
    printf("Veuillez entrez un mot : \n");
    char ligne[TAILLE];
    while (fgets(ligne, TAILLE, stdin) != NULL)
    {
        printf("Le mot lu est : %s", ligne);
        printf("La taille du mot est de : %d", strlen(ligne)-1);
        exit(0);
    }
}
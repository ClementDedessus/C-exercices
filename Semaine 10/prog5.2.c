#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define TAILLE 254
#define ID_COFFRE 5
#define NB_COFFRES 10

int main(int argc, char *argv[])
{
    int taillePhys = NB_COFFRES;
    int tailleLog = 0;
    char **coffres = (char **)malloc(taillePhys * sizeof(char *));
    if (coffres == NULL)
    {
        exit(1);
    }

    char ligne[TAILLE];
    while (fgets(ligne, TAILLE, stdin) != NULL)
    {
    }
}
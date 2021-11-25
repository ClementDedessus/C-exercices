#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAILLE_MAX_MOT 27

int main(int argc, char *argv[])
{
    char **table = malloc((argc - 1) * sizeof(char *));
    if (!table)
        exit(0);
    for (int i = 0; i < argc - 1; i++)
    {
        table[i] = (char *)malloc((strlen(argv[i + 1]) + 1) * sizeof(char));
        if (!table[i])
            exit(0);
        strcpy(table[i], argv[i + 1]);
    }
    //affiche les mots lu
    for (int i = 0; i < argc - 1; i++)
    {
        printf("%s ", table[i]);
    }
}
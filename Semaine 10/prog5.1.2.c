#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAILLE_MAX_MOT 27

int main(int argc, char *argv[])
{
    char **table = malloc((argc - 1) * sizeof(char *));
    for (int i = 1; i < argc; i++)
    {
        table[i] = (char *)malloc(TAILLE_MAX_MOT * sizeof(char));
        if (table[i] == NULL)
            exit(0);
    }

    for (int i = 1; i < argc; i++)
    {
        strcpy(table[i], argv[i]);
    }
    //affiche le mot lu
    printf("%s", table);
}
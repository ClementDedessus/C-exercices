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

    char *table2;
    table2 = (char *)malloc(TAILLE_MAX_MOT * sizeof(char));
    if (!table2)
        exit(1);

    printf("\n");
    printf("Veuillez entrer un nouveau mot :  ");

    while (fgets(table2, TAILLE_MAX_MOT, stdin) != NULL)
    {
        printf("La taille de votre mot vaut -> %d \n", strlen(table2) - 1);
        printf("Veuillez entrer un nouveau mot : ");
    }
}
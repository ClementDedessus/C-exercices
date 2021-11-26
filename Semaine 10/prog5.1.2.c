#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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

    bool present;
    int compteurAbsent = 0;

    while (fgets(table2, TAILLE_MAX_MOT, stdin) != NULL)
    {
        table2[strlen(table2) - 1] = '\0';
        printf("La taille de votre mot vaut -> %d \n", strlen(table2));

        present = false;
        for (int i = 0; i < argc - 1; i++)
        {
            if (!strcmp(table2, table[i]))
            {
                present = !present;
                break;
            }
        }

        if (present)
        {
            printf("-> Votre mot est present \n ");
            break;
        }
        else
        {
            printf("-> Votre mot est absent \n");
            compteurAbsent++;
        }

        printf("Veuillez entrer un nouveau mot : ");
    }

    printf("Nombre de mots lu qui n'ont pas ete trouve dans la table -> '%d' ", compteurAbsent);

    for (int i = 0; i < argc - 1; i++)
        free(table[i]);
    free(table);
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //POINT 1)
    //TODO
    int entierUtilisateur;
    printf("Veuillez entrer un nombre : \n");
    scanf("%d", &entierUtilisateur);

    if (entierUtilisateur <= 0)
    {
        exit(1);
    }

    //POINT 2)
    //TODO
    int resultat = 0;
    int compteur = 1;
    int repUtisateur = entierUtilisateur;
    while (resultat != 1)
    {
        if (repUtisateur % 2 == 0)
        {
            resultat = repUtisateur / 2;
        }
        else
        {
            resultat = (repUtisateur * 3) + 1;
        }
        repUtisateur = resultat;
        compteur++;
    }
    printf("\n");
    printf("Voici la longueur de la suite : %d \n", compteur);

    //POINT 3)
    //TODO
    int *tabSyracuse;
    tabSyracuse = (int *)malloc(compteur * sizeof(int));
    if (tabSyracuse == NULL)
        exit(1);

    //POINT 4)
    //TODO
    tabSyracuse[0] = entierUtilisateur;
    for (int i = 1; i < compteur; i++)
    {
        if (entierUtilisateur % 2 == 0)
        {
            resultat = entierUtilisateur / 2;
            tabSyracuse[i] = resultat;
        }
        else
        {
            resultat = (entierUtilisateur * 3) + 1;
            tabSyracuse[i] = resultat;
        }
        entierUtilisateur = resultat;
    }

    //POINT 5)
    //TODO

    //print du tab normal
    printf("\n");
    printf("Table a l'endroit : \n");
    for (int i = 0; i < compteur; i++)
    {
        printf("%3d", tabSyracuse[i]);
    }
    printf("\n");

    //print tab à l'envers
    printf("\n");
    printf("Table a l'envers : \n");
    for (int i = compteur - 1; i >= 0; i--)
    {
        printf("%3d", tabSyracuse[i]);
    }

    //POINT 6)
    //TODO
    free(tabSyracuse);
}
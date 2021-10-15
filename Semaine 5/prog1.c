//gcc -std=c11 -pedantic -Werror -Wall -Wvla -Wno-unused-variable -o testProg1 prog1.c

#include <stdlib.h>
#include <stdio.h>

#define TAILLE 5

int main()
{

    int note;
    int tabNote[TAILLE];
    double total;
    double moyenne;
    int nombreNote;

    printf("Veuillez entrer les notes de la classes \n");

    for (int i = 0; i < TAILLE; i++)
    {
        printf("Veuillez entrer la note numero %d  : \n", i);
        scanf("%d", &note);
        tabNote[i] = note;
        nombreNote++;
    }

    for (int i = 0; i < TAILLE; i++)
    {
        total += tabNote[i];
    }

    moyenne = total / nombreNote;
    printf("%f", moyenne);

    //les écarts à la moyenne (Xi−Moy(Xi)) pour chaque valeur Xi
    double difference;
    double totaleDiff;
    int moyennDifference;
    for (int i = 0; i < TAILLE; i++)
    {
        difference = tabNote[i] - moyenne;
        totaleDiff += difference;
    }
    moyennDifference = totaleDiff/nombreNote;
    printf("\n");
    printf("Voici la moyenne des ecarts a la moyenne :  %f \n" + moyennDifference);

    exit(0);
}
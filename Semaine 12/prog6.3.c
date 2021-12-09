#include <stdio.h>
#include <stdlib.h>

//PRE : n >= 2
//POST : *sz est égal à la taille physique du tableau renvoyé par cette fonction
//RES : un tableau trié contenant tous les nombres premiers strictement plus petits
//que n si aucune erreur n’est survenue et NULL si une erreur est survenue.
int *prime_numbers(int n, int *sz)
{
    int *table = malloc(n * sizeof(int));
    if (!table)
        exit(0);

    for (int i = 0; i < n; i++)
    {
        table[i] = i;
    }
    int nombreNombrePremier = 0;
    for (int i = 0; i < n; i++)
    {
        int compteur = 0;
        for (int div = 1; div < n; div++)
        {

            if (i % div == 0)
            {
                compteur++;
            }
        }
        if (compteur == 2)
        {
            table[nombreNombrePremier] = i;
            nombreNombrePremier++;
        }
    }
    table = (int *)realloc(table, nombreNombrePremier * sizeof(int));

    *sz = nombreNombrePremier;
    return table;
}

int main()
{
    int n = 500;
    int size;
    int *test = prime_numbers(n, &size);
    for (int i = 0; i < size; i++)
    {
        printf("%4d", test[i]);
    }
}
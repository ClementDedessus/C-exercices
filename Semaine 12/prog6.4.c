#include <stdio.h>
#include <stdlib.h>

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

//PRE : t : tableau de longueur sz
//POST : t représente un tableau trié contenant les sz premiers nombres premiers
void first_prime_numbers(int *t, int sz)
{
    int n = 2;
    int szr;
    int *res = prime_numbers(n, &szr);
    while (szr < sz)
    {
        n = n * 2;
        free(res);
        res = prime_numbers(n, &szr);
    }
    for (int i = 0; i < sz; i++)
    {
        t[i] = res[i];
    }
    free(res);
}

int main()
{
    int test[1000];
    first_prime_numbers(test, 1000);
    for (int i = 0; i < 1000; i++)
    {
        printf("%5d", test[i]);
    }
    exit(0);
}
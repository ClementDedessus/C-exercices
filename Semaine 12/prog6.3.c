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
    for (int i = 0; i < n; i++)
    {
        if (table[i] == 2 || table[i] == 3 || table[i] == 5 || table[i] == 7)
        {
        }
        if (table[i] % 2 == 0 || table[i] % 3 == 0 || table[i] % 5 == 0 || table[i] % 7 == 0)
        {
            table[i] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(table[i] == 0 ){
            table[i] = table[i+1];
        }
        //test
        printf("%d", table[i]);
    }
}

int main()
{
    
}
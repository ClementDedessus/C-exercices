#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//PRE : t : tableau de longueur sz
//RES : true si le t contient un élément x, false sinon
bool search(int *t, int sz, int x)
{
    t = malloc((sz) * sizeof(int));
    if (!t)
        exit(0);
    for (int i = 0; i < sz; i++)
    {
        t[i] = i;
    }
    for (int i = 0; i < sz; i++)
    {
        if (t[i] == x)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int taille = 10;
    int valeur = 15;
    int *t = malloc(taille * sizeof(int));
    bool test = search(t, taille, valeur);
    printf("0 = false , 1 = true \n");
    printf("%d", test);
}
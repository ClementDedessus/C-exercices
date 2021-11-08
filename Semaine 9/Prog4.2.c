//gcc -std=c11 -pedantic -Werror -Wall -Wvla -Wno-unused-variable -o testProg4.2.exe Prog4.2.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int H = 0;
    int L = 0;

    printf("Veuillez donner la hauteur :\n");
    scanf("%d", &H);
    printf("Veuillez donner la largeur :\n");
    scanf("%d", &L);

    char **puissance;
    puissance = (char **)malloc(H * sizeof(char *));
    if (puissance == NULL)
        exit(1);

    for (int i = 0; i < H; i++)
    {
        puissance[i] = (char *)malloc(L * sizeof(char));
        if (puissance[i] == NULL)
            exit(1);
    }

    //on remplit le tableau
    for(int i=0; i<H; i++){
        for(int j=0; j<L; j++){
            puissance[i][j] = '.';
        }
    }






    /*for (int i = 0; i < H; i++)
        free(puissance[i]);
    free(puissance);*/
}
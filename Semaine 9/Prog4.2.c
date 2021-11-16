//gcc -std=c11 -pedantic -Werror -Wall -Wvla -Wno-unused-variable -o testProg4.2.exe Prog4.2.c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < L; j++)
        {
            puissance[i][j] = '.';
        }
    }

    //print le tableau
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < L; j++)
        {
            printf("%4c", puissance[i][j]);
        }
        printf("\n");
    }

    //début du jeu
    int x = 0;
    int emplacementPiece;
    int hauteurPiece = H - 1;
    int tourDesJoeurs = 0;
    int deplacementPiece = 0;
    int i = 0;
    int debutImpressionPoint = L;

    while (tourDesJoeurs < 100) //condition  à modifier -> gagnant
    {
        if (tourDesJoeurs % 2 == 0)
        {
            printf("Dans quelle colonne voulez vous jouer (X) ? \n");
            scanf("%d", &emplacementPiece);
            //realoc
            if (emplacementPiece >= L)
            {
                printf("Augmentation de la taille du tableau \n");
                L = emplacementPiece+1;
                for (int i = 0; i < H; i++)
                {
                    puissance[i] = (char *)realloc(puissance[i], L * sizeof(char));
                    if (puissance[i] == NULL)
                        exit(1);
                }
                //on remplit le tableau
                for (int i = 0; i < H; i++)
                {
                    for (int j = debutImpressionPoint; j < L; j++)
                    {
                        puissance[i][j] = '.';
                    }
                }
            }
            //deplacement
            while (puissance[hauteurPiece - i][emplacementPiece - 1] != '.')
            {
                i++;
                deplacementPiece++;
            }
            puissance[hauteurPiece - deplacementPiece][emplacementPiece - 1] = 'X';
            deplacementPiece = 0;
            i = 0;
            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < L; j++)
                {
                    printf("%4c", puissance[i][j]);
                }
                printf("\n");
            }
            tourDesJoeurs++;
        }
        else
        {
            printf("Dans quelle colonne voulez vous jouer (O) ? \n");
            scanf("%d", &emplacementPiece);
            //realoc
            if (emplacementPiece >= L)
            {
                printf("Augmentation de la taille du tableau \n");
                L = emplacementPiece+1;
                for (int i = 0; i < H; i++)
                {
                    puissance[i] = (char *)realloc(puissance[i], L * sizeof(char));
                    if (puissance[i] == NULL)
                        exit(1);
                }
                //on remplit le tableau
                for (int i = 0; i < H; i++)
                {
                    for (int j = debutImpressionPoint; j < L; j++)
                    {
                        puissance[i][j] = '.';
                    }
                }
            }
            //deplacement
            while (puissance[hauteurPiece - i][emplacementPiece - 1] != '.')
            {
                i++;
                deplacementPiece++;
            }
            puissance[hauteurPiece - deplacementPiece][emplacementPiece - 1] = 'O';
            deplacementPiece = 0;
            i = 0;
            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < L; j++)
                {
                    printf("%4c", puissance[i][j]);
                }
                printf("\n");
            }
            tourDesJoeurs++;
        }
    }

    for (int i = 0; i < H; i++)
        free(puissance[i]);
    free(puissance);
}
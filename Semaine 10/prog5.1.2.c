#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAILLE 256

int main()
{
    printf("Veuillez entrez un mot : \n");
    char ligne[TAILLE];
    while (fgets(ligne, TAILLE, stdin) != NULL)
    {   
        //renvoie le mot
        printf("Le mot lu est : %s", ligne);

        //renvoie la taille du mot
        printf("La taille du mot est de : %d", strlen(ligne) - 1);

        //voir si le mot est bien dans la table
        /*if(){
            printf("present \n");
        }else{
            printf("absent \n");
        }*/
        exit(0);
    }
}
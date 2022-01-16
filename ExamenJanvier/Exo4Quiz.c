#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAILLE 256

int main () {
    char ligne[TAILLE];
    if (fgets(ligne, TAILLE, stdin) == NULL)
        exit(0);
    ligne[strlen(ligne)-1] = '\0';  // suppression du '\n'
    
    //TODO
    int i = 0;
    int compteur = 0;
    while(ligne[i] != '\0'){
        compteur++;
        i++;
    }
    for(int i=compteur-1; i>=0; i--){
        printf("%c",ligne[i]);
    }
    exit(0);
}

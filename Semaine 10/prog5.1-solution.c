#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>  // parfois inclus dans stdlib.h, selon le compilateur
#include <string.h>
#include <stdbool.h>

#define MAX_LONG 27  // longueur maximale d'un mot

int main (int argc, char* argv[]) {
    int nbMots = argc - 1;

    // copie des arguments de la ligne de commande
    char** tabMot = (char**) malloc(nbMots * sizeof(char*));
    if (!tabMot) { perror("erreur d'allocation mémoire"); exit(1); }
	
    for (int i=0; i<nbMots; i++) {
        tabMot[i] = (char*) malloc((strlen(argv[i+1])+1) * sizeof(char));
        if (!tabMot[i]) { perror("erreur d'allocation mémoire"); exit(1); }
		
        strcpy(tabMot[i],argv[i+1]);
        // Attention! l'instruction suivante est une copie superficielle ('shallow copy'
        // --> deux variables partagent le même bloc de mémoire):
        //     tabMot[i] = argv[i+1]
        // elle provoque également une fuite mémoire (perte de l'adresse du bloc alloué via malloc)
        // La fonction strcpy() réalise bien une copie profonde ('deep copy') dans le bloc 
        // de mémoire alloué dynamiquement
    }

    // affichage du tableau des arguments
    printf("Parametres:\n");
    for (int i=0; i<nbMots; i++){
        printf("  argument %d: %s\n", i+1, tabMot[i]);
    }

    // recherche de mots lus au clavier
    bool present;
    int nbrAbsent = 0;
    printf("\nIntroduire des mots d'au plus %i lettres a rechercher :\n",MAX_LONG);
    char ligne[MAX_LONG+2];
    while (fgets(ligne, MAX_LONG+2, stdin) != NULL) {
        int taille = strlen(ligne)-1;

        // Variante 1: traitement du cas où le mot entré est trop long
        if (ligne[taille] != '\n') {
        	printf("Erreur: le mot entré est trop long.\n");
        	// vidage du buffer stdin
        	while (fgets(ligne, MAX_LONG+2, stdin) && ligne[strlen(ligne)-1] != '\n') ;
        	continue;
        }

        // remplacement de '\n' par '\0' dans la ligne lue
        ligne[taille] = '\0';
        printf("  '%s'  longueur = %d\n",ligne, (int)strlen(ligne));

        // recherche du mot entré dans le tableau tabMot
        present = false;
        for (int i=0;i<nbMots;i++) {
            if (!strcmp(ligne, tabMot[i])){
                present = !present;
                break;
            }
            // Variante 2: pour que la recherche du mot soit insensible à la casse,
            // deux solutions sont possibles:
            // - comparaison caractère par caractère en les convertissant avec tolower() ou toupper()
            //   (pour trouver cette fonction:  apropos convert | grep lowercase)
            // - comparaison de deux chaînes sans tenir compte de la casse: strcasecmp()
            //   (pour trouver cette fonction:  apropos string | grep case)
        }
        if (present) {
            printf("  '%s' est present dans la table\n", ligne);
        } else {
            printf("  '%s' est absent de la table\n", ligne);
            nbrAbsent++;
        }
    }
    
    // affichage des résultats
    printf("\n%d mots ont ete lus et n'etaient pas dans la table\n",nbrAbsent);
    
    for (int i=0;i<nbMots;i++)
        free(tabMot[i]);
    free(tabMot);
	
    exit(EXIT_SUCCESS);  // <=> exit(0)
}

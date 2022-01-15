#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char **copierArgs(char **tab, int n, int *ncp);
void trier(char **tab, int n);
void afficher(char **tab, int n);

int main(int argc, char *argv[])
{
    // Copie profonde des arguments du programme

    // Affichage du tableau

    // Tri du tableau

    // Affichage du tableau triÃ©

    // LibÃ©ration de la mÃ©moire dynamique
}

/**
 * PRE: tab: tableau de n chaÃ®nes de caractÃ¨res
 * POST: *ncp: nombre de chaÃ®nes dans le tableau renvoyÃ©
 * RES: renvoie un tableau contenant les chaÃ®nes de tab sans doublon
 *      (taille logique = taille physique); NULL si une erreur s'est produite
 */
char **copierArgs(char **tab, int n, int *ncp)
{

    // TODO
}

/**
 * PRE: tab: tableau de n chaÃ®nes de caractÃ¨res
 * POST: les n chaÃ®nes de tab sont triÃ©es par ordre alphabÃ©tique
 *       (algorithme: tri par sÃ©lection)
 */
void trier(char **tab, int n)
{

    // TODO
    // Cette fonction ne devrait pas crÃ©er de nouvelles chaÃ®nes,
    // elle ne fait que manipuler des adresses.
}

/**
 * PRE: tab: tableau de n chaÃ®nes de caractÃ¨res
 * POST: affiche les chaÃ®nes de tab (Ã  raison d'une par ligne,
 *       prÃ©cÃ©dÃ©e par leur numÃ©ro)
 */
void afficher(char **tab, int n)
{

    // TODO
}

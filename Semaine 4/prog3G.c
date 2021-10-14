//gcc -std=c11 -pedantic -Werror -Wall -Wvla -Wno-unused-variable -o testProg3G prog3G.c

#include <stdlib.h>
#include <stdio.h>

// Le cas d'une ligne se terminant par <CTRL-D> (ex: "8<CTRL-D>")
// n'est pas traitÃ© par ce programme.

int main () {
	int car;// int et pas char car comparaison avec EOF=-1 renvoyÃ© par getchar()

	while ((car = getchar()) != EOF) {  // lecture du premier caractÃ¨re de la ligne
		if (car == '\n')  // traitement du passage Ã  la ligne
			continue;

		int nbre = car - '0';  // rÃ©cupÃ©ration de la valeur entiÃ¨re
		int fact = 1;
		int i=2; 
		while (i<=nbre) {
			fact *= i;
			i++;
		}
		printf("%d! = %d\n", nbre, fact);
	}

	exit(0);
}
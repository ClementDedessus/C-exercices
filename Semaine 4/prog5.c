//gcc -std=c11 -pedantic -Werror -Wall -Wvla -Wno-unused-variable -o testProg5 prog5.c



#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

// Le cas d'une ligne se terminant par <CTRL-D> (ex: "8<CTRL-D>")
// n'est pas traitÃ© par ce programme.

int main () {
	int car1,car2,c; // int et pas char car comparaison avec EOF=-1 renvoyÃ© par getchar()

	while ((car1 = getchar()) != EOF) {   // lecture du premier caractÃ¨re de la ligne
		// vÃ©rifier si la ligne est vide
		if (car1 == '\n') {
			printf("Error: empty line\n");
			continue;
		}

		// vÃ©rifier si le premier caractÃ¨re lu est un chiffre
		if (car1 < '0' || car1 > '9') {
			printf("Error: invalid character\n");
			// vider le buffer
			while (getchar() != '\n');  // lecture de tous les caractÃ¨res restants de la ligne
			continue; 
		}
		
		// rÃ©cupÃ©ration de la valeur entiÃ¨re
		int nbre = car1 - '0';  
		
		if ((car2 = getchar()) != '\n') {
			// vÃ©rifier si la ligne est trop longue
			if ((c = getchar()) != '\n') {
				printf("Error: too many characters\n");
				// vider le buffer
				while (getchar() != '\n');  // lecture de tous les caractÃ¨res restants de la ligne
				continue;
			}

			// vÃ©rifier si le second caractÃ¨re lu est un chiffre
			if (car2 < '0' || car2 > '9') {
				printf("Error: invalid character\n");
				continue; 
			}

			// rÃ©cupÃ©ration de la valeur entiÃ¨re
			nbre = nbre*10 + car2 - '0';  
		}
		

		// calculer la factorielle de nbre
		int i;
		int fact = 1;
		for (i=2; i<=nbre; i++) {
			if (fact>INT_MAX/i) {
				printf("Error: integer overflow\n");
				break;
			}
			fact *= i;
		}
		if (i>nbre)
			printf("%d! = %d\n", nbre, fact);
	}

	exit(0);
}

//gcc -std=c11 -pedantic -Werror -Wall -Wvla -Wno-unused-variable -o testProg6 prog6.c

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

int main () {
	int car1,car2,c;
	int cpt_nbre = 0;
	int a,b;

	while (cpt_nbre < 2) {
		// vÃ©rifier si la ligne est vide
		if ((car1 = getchar()) == '\n') {
			printf("Error: empty line\n");
			continue;
		}

		// vÃ©rifier si le caractÃ¨re lu est un signe -
		int signe = +1;
		if (car1 == '-') {
			signe = -1;
			if ((car1 = getchar()) == '\n') {
				printf("Error: invalid number\n");
				continue;
			}
		}

		// vÃ©rifier si le caractÃ¨re lu est un chiffre
		if (car1 < '0' || car1 > '9') {
			printf("Error: invalid character\n");
			// vider le buffer
			while (getchar() != '\n') ;
			continue; 
		}
		
		// rÃ©cupÃ©ration de la valeur entiÃ¨re
		int nbre = car1 - '0';
	
		if ((car2 = getchar()) != '\n') {
			// vÃ©rifier si la ligne est trop longue
			if ((c = getchar()) != '\n') {
				printf("Error: too many characters\n");
				// vider le buffer
				while (getchar() != '\n');
				continue;
			}

			// vÃ©rifier si le caractÃ¨re lu est un chiffre
			if (car2 < '0' || car2 > '9') {
				printf("Error: invalid character\n");
				continue; 
			}

			// rÃ©cupÃ©ration de la valeur entiÃ¨re
			nbre = nbre*10 + car2 - '0';
		}
		
		cpt_nbre++;
		if (cpt_nbre == 1)
			a = signe * nbre;
		else
			b = signe * nbre;
	}

	// calculer a^b
	double pow = 1;
	for (int i=1; i<=abs(b); i++)
		pow *= a;
	if (b<0)
		printf("%d^(%d) = %e\n", a, b, 1/pow);
	else
		printf("%d^(%d) = %.0f\n", a, b, pow);

	exit(0);
}

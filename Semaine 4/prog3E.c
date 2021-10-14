//gcc -std=c11 -pedantic -Werror -Wall -Wvla -Wno-unused-variable -o testProg3D prog3D.c

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main () {
	
	const int NBRE = 15;

	// initialisation
	int fact = 1;
	int i=2; 
	// condition
	while (i<=NBRE) {  
		// tester le dÃ©passement de capacitÃ©: i*fact > INT_MAX
		if (fact>INT_MAX/i) {    // pas une rÃ¨gle absolue car division entiÃ¨re!
			printf("Error: integer overflow\n");
			return -1;
		}

		fact *= i;
		// adaptation
		i++;
	}

	printf("%d! = %d\n", NBRE, fact);
	exit(0);
}

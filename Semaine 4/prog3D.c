//gcc -std=c11 -pedantic -Werror -Wall -Wvla -Wno-unused-variable -o testProg3D prog3D.c

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main () {
	
	const int NBRE = 13;

	int fact = 1;
	for (int i=2; i<=NBRE; i++) {
  		// tester le dÃ©passement de capacitÃ©: i*fact > INT_MAX
		if (fact>INT_MAX/i) {
			printf("Error: integer overflow\n");
			return -1;
		}

		fact *= i;
	}

	printf("%d! = %d\n", NBRE, fact);
	exit(0);
}
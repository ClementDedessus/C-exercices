//gcc -std=c11 -pedantic -Werror -Wall -Wvla -Wno-unused-variable -o testProg3F prog3F.c


#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main () {
	
	const int NBRE = 15;

	int fact = 1;
	int i=2; 
	while (i<=NBRE && fact<=INT_MAX/i) {  // tester le dÃ©passement de capacitÃ©: i*fact > INT_MAX
		fact *= i;
		i++;
	}

	if (i<=NBRE) {
		printf("Error: integer overflow\n");
		return -1;
	}

	printf("%d! = %d\n", NBRE, fact);
	exit(0);
}
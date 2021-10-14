//gcc -std=c11 -pedantic -Werror -Wall -Wvla -Wno-unused-variable -o testProg1 prog1.c

#include <stdlib.h>
#include <stdio.h>

int main() {
  for (char c = 'A'; c <= 'Z'; c++)
    printf("Caractere = %c     code = %d     code hexa = %x\n", c, c, c);
  for (char c = '1'; c <= '9'; c++)
    printf("Caractere = %c     code = %d     code hexa = %x\n", c, c, c);
  exit(0);
}

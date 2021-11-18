#include <stdlib.h>
#include <stdio.h>

#define TAILLE 256

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        printf("%s \n", argv[i]);
    }
}
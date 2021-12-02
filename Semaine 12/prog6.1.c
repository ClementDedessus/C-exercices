#include <stdlib.h>
#include <stdio.h>

//RES: le maximum entre x et y
int max(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    if (x == y)
    {
        printf("Les deux sont egaux, donc le ");
        return x;
    }
    return y;
}

int main()
{
    int x;
    x = max(10, 12);
    printf("max = %d \n", x);
    x = max(3, 10);
    printf("max = %d \n", x);
    x = max(9, 9);
    printf("max = %d \n", x);
    x = max(0, 9);
    printf("max = %d \n", x);
    x = max(0, 0);
    printf("max = %d \n", x);
    x = max(1, 20);
    printf("max = %d \n", x);
}
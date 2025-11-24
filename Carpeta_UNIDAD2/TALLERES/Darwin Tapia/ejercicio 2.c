#include <stdio.h>

void main ()
{
    int m=6, n=3, p=9, expr=0;
    expr= m*(n+p)/2 >= p-n;
    printf("Expresion es igual a %d\n", expr);
}

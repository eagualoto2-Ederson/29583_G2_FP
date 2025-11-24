#include <stdio.h>

void main ()
{
    int i=4, j=2, k=8, expr=0;
    expr=(3*j+8/k) != i*k-j;
    printf("Expresion es igual a %d\n", expr);
}

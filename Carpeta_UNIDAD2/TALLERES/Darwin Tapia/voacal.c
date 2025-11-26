#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("chcp 1252 > nul"); // NECESARIO para que lea á é í ó ú correctamente

    char car;

    printf("Ingrese un caracter: ");
    scanf("%c", &car);

    switch(car)
    {
        case 'á':
        case 'é':
        case 'í':
        case 'ó':
        case 'ú':
            printf("Es una vocal acentuada\n");
            break;

        default:
            printf("No es una vocal acentuada\n");
            break;
    }

    return 0;
}

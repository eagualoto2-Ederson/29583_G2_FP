#include <stdio.h>
#include <math.h>
int main() {
 int op;
 int fil, i, j;
 int n;
 double res;
 do {
 printf("\n=== MENU PRINCIPAL ===\n");
 printf("1) Figura con 1's (cuadrado)\n");
 printf("2) Serie numerica\n");
 printf("3) Salir\n");
 printf("Elige una opcion: ");
 scanf("%d", &op);
 switch (op) {
 case 1:
    // Opcion 1: dibujar un cuadrado hueco con diagonal principal
    do {
        printf("\nIngresa el numero de filas (mayor que 0): ");
        scanf("%d", &fil);
    } while (fil <= 0);

    for (i = 1; i <= fil; i++) {
        for (j = 1; j <= fil; j++) {
            // Bordes, diagonal principal o esquinas
            if (i == 1 || i == fil || j == 1 || j == fil || i == j) {
                printf("1 ");
            } else {
                printf("  ");  // Dos espacios para mantener alineación
            }
        }
        printf("\n");
    }
    break;
 case 2:
    // Opcion 2: serie 1^2 + 2^2 + 3^2 + ... + n^2
    do {
        printf("\nIngresa un valor para n (mayor que 0): ");
        scanf("%d", &n);
    } while (n <= 0);

    res = 0;
    printf("\nSerie: ");

    for (i = 1; i <= n; i++) {
        res = res + pow(i, 2);   // <-- Cambio importante: ahora es i^2
        printf("%d^2", i);       // <-- Mostrar i^2
        if (i < n) {
            printf(" + ");
        }
    }

    printf("\nResultado de la serie = %.0f\n", res);
    break;
 case 3:
 printf("\nSaliendo del programa...\n");
 break;
 default:
 printf("\nOpcion no valida. Intenta de nuevo.\n");
 }
 } while (op != 3);
 return 0;
}

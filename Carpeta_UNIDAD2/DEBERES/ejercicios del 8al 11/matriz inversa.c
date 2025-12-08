#include <stdio.h>

int main() {
    int N = 3;
    int matriz[3][3];
    int i, j;

    printf("Ingresa los valores de la matriz 3x3:\n");

    // Capturar los valores desde el teclado
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Recorrido inverso
    printf("\nRecorrido inverso de la matriz:\n");

    for (i = N - 1; i >= 0; i--) {
        for (j = N - 1; j >= 0; j--) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;

    printf("Introduce el tamaño de la matriz NxN: ");
    scanf("%d", &N);

    // Validar tamaño
    if (N <= 0) {
        printf("Tamaño no válido.\n");
        return 1;
    }

    // Crear matriz dinámica
    int matriz[N][N];

    int fila_seleccionada;
    int max_valor;

    printf("\nIntroduce los elementos de la matriz %dx%d:\n", N, N);

    // Ingreso de datos
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Selección de fila
    printf("\nIntroduce el número de fila para encontrar el máximo (0 a %d): ", N - 1);
    scanf("%d", &fila_seleccionada);

    if (fila_seleccionada < 0 || fila_seleccionada >= N) {
        printf("Número de fila no válido.\n");
        return 1;
    }

    // Calcular máximo
    max_valor = matriz[fila_seleccionada][0];

    for (int j = 1; j < N; j++) {
        if (matriz[fila_seleccionada][j] > max_valor) {
            max_valor = matriz[fila_seleccionada][j];
        }
    }

    printf("\nEl valor máximo de la fila %d es: %d\n", fila_seleccionada, max_valor);

    return 0;
}


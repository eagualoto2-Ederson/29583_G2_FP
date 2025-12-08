#include <stdio.h>

int main() {
    int N, M;
    int i, j;
    int res = 0;

    printf("Ingrese el numero de columnas (M): ");
    scanf("%d", &M);

    printf("Ingrese el numero de filas (N): ");
    scanf("%d", &N);

    int A[N][M];   // Matriz correctamente declarada

    printf("Ingrese los elementos de la matriz por columnas:\n");

    // Lectura por columnas
    for (j = 0; j < M; j++) {
        for (i = 0; i < N; i++) {
            scanf("%d", &A[i][j]);
            res += A[i][j];
        }
    }

    // Impresión de la matriz
    printf("\nLa matriz ingresada es:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("\nLa suma de los componentes de la matriz es: %d\n", res);

    return 0;
}




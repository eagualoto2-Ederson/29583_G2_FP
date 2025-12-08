#include <stdio.h>

int main() {
    int ROWS = 3;
    int COLS = 3;

    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int i, j, k, aux;

    printf("Matriz original:\n");
    for (k = 0; k < ROWS; k++) {
        for (int l = 0; l < COLS; l++) {
            printf("%d ", mat[k][l]);
        }
        printf("\n");
    }

    printf("Ingrese la fila i a intercambiar (0-%d): ", ROWS - 1);
    scanf("%d", &i);
    printf("Ingrese la fila j a intercambiar (0-%d): ", ROWS - 1);
    scanf("%d", &j);

    if (i >= 0 && i < ROWS && j >= 0 && j < ROWS) {
        for (k = 0; k < COLS; k++) {
            aux = mat[i][k];
            mat[i][k] = mat[j][k];
            mat[j][k] = aux;
        }

        printf("Matriz despues del intercambio:\n");
        for (k = 0; k < ROWS; k++) {
            for (int l = 0; l < COLS; l++) {
                printf("%d ", mat[k][l]);
            }
            printf("\n");
        }
    } else {
        printf("Indices de fila invalidos.\n");
    }

    return 0;
}


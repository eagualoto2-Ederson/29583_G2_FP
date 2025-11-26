#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Definicion
void menuPrincipal();
void menuExpresiones();
void ejercicio1();
void ejercicio2();
void ejercicio3();
void ejercicio4();
void ejercicio5();
void ejercicio6();
void ecuacionSegundoGrado();

int main() {
    menuPrincipal();
    return 0;
}

void menuPrincipal() {
    int op;

    do {
        system("cls");  //limpiar la pantalla
        printf("===== MENU PRINCIPAL =====\n");
        printf("1. Expresiones\n");
        printf("2. Ecuacion de Segundo Grado\n");
        printf("3. Salir\n");
        printf("==========================\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                menuExpresiones();
                break;

            case 2:
                ecuacionSegundoGrado();
                break;

            case 3:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion invalida\n");
                system("pause");
        }
    } while (op != 3);
}

void menuExpresiones() {
    int op;

    do {
        system("cls");
        printf("===== SUBMENU DE EXPRESIONES =====\n");
        printf("1. Ejercicio 1\n");
        printf("2. Ejercicio 2\n");
        printf("3. Ejercicio 3\n");
        printf("4. Ejercicio 4\n");
        printf("5. Ejercicio 5\n");
        printf("6. Ejercicio 6\n");
        printf("7. Regresar al Menu Principal\n");
        printf("===================================\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &op);

        switch (op) {
            case 1: ejercicio1(); break;
            case 2: ejercicio2(); break;
            case 3: ejercicio3(); break;
            case 4: ejercicio4(); break;
            case 5: ejercicio5(); break;
            case 6: ejercicio6(); break;
            case 7: break;
            default:
                printf("Opcion invalida\n");
                system("pause");
        }

    } while (op != 7);
}

/* ===================== EJERCICIOS ===================== */

void ejercicio1() {
    int i=4, j=2, k=8, expr=0;
    expr = (3*j + 8/k) != i*k - j;
    printf("Expresion es igual a %d\n", expr);
    system("pause");
}

void ejercicio2() {
    int m=6, n=3, p=9, expr=0;
    expr = m*(n+p)/2 >= p-n;
    printf("Expresion es igual a %d\n", expr);
    system("pause");
}

void ejercicio3() {
    int a=5, b=2, c=10, expr=0;
    expr = (a + b*c);
    printf("La expresion es igual a %d\n", expr);
    system("pause");
}

void ejercicio4() {
    int x=14, y=13, expr=0;
    expr = x/(y-1) + 3/y == x - y;
    printf("La respuesta es %d\n", expr);
    system("pause");
}

void ejercicio5() {
    int u=12, v=4, expr=0;
    expr = (u*v - 4) <= v + u/2;
    printf("El resultado es %d\n", expr);
    system("pause");
}

void ejercicio6() {
    int q=7, r=5, expr=0;
    expr = (q + r*2) <= q*r - 10;
    printf("El resultado es %d\n", expr);
    system("pause");
}

//Ecuacion de segundo grado ax^2 + bx + c = 0

void ecuacionSegundoGrado() {
    float a, b, c, d, x1, x2;

    system("cls");
    printf("=== ECUACION DE SEGUNDO GRADO ===\n");
    printf("Ingrese a: ");
    scanf("%f", &a);
    printf("Ingrese b: ");
    scanf("%f", &b);
    printf("Ingrese c: ");
    scanf("%f", &c);

    d = b*b - 4*a*c;

    if (d < 0) {
        printf("La ecuacion no tiene soluciones reales\n");
    } else {
        x1 = (-b + sqrt(d)) / (2*a);
        x2 = (-b - sqrt(d)) / (2*a);
        printf("Solucion 1: %.2f\n", x1);
        printf("Solucion 2: %.2f\n", x2);
    }

    system("pause");
}

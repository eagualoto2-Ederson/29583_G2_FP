#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
#define STR 50

/* ===== USUARIO ===== */
char usuario[STR];
char clave[STR];
int usuarioRegistrado = 0;

/* ===== INVENTARIO ===== */
struct Repuesto {
    char nombre[STR];
    char marca[STR];
    char modelo[STR];
    char anio[STR];
    char categoria[STR];
    char ubicacion[STR];
};

struct Repuesto inventario[MAX];
int total = 0;

/* ===== REGISTRAR REPUESTO ===== */
void registrarRepuesto() {
    system("cls");

    if (total >= MAX) {
        printf("Inventario lleno.\n");
        system("pause");
        return;
    }

    printf("\n--- Registrar repuesto ---\n");

    printf("Nombre: ");
    scanf("%s", inventario[total].nombre);

    printf("Marca: ");
    scanf("%s", inventario[total].marca);

    printf("Modelo: ");
    scanf("%s", inventario[total].modelo);

    printf("Anio: ");
    scanf("%s", inventario[total].anio);

    printf("Categoria: ");
    scanf("%s", inventario[total].categoria);

    printf("Ubicacion: ");
    scanf("%s", inventario[total].ubicacion);

    total++;
    printf("\nRepuesto registrado.\n");
    system("pause");
}

/* ===== MOSTRAR INVENTARIO ===== */
void mostrarInventario() {
    int i;
    system("cls");

    printf("\n--- Inventario ---\n");

    if (total == 0) {
        printf("No hay repuestos.\n");
        system("pause");
        return;
    }

    for (i = 0; i < total; i++) {
        printf("\nRepuesto %d\n", i + 1);
        printf("Nombre: %s\n", inventario[i].nombre);
        printf("Marca: %s\n", inventario[i].marca);
        printf("Modelo: %s\n", inventario[i].modelo);
        printf("Anio: %s\n", inventario[i].anio);
        printf("Categoria: %s\n", inventario[i].categoria);
        printf("Ubicacion: %s\n", inventario[i].ubicacion);
    }

    system("pause");
}

/* ===== BUSCAR REPUESTO ===== */
void buscarRepuesto() {
    char nombre[STR];
    int i, encontrado = 0;

    system("cls");
    printf("\nNombre a buscar: ");
    scanf("%s", nombre);

    for (i = 0; i < total; i++) {
        if (strcmp(inventario[i].nombre, nombre) == 0) {
            printf("\nEncontrado:\n");
            printf("Marca: %s\n", inventario[i].marca);
            printf("Modelo: %s\n", inventario[i].modelo);
            printf("Anio: %s\n", inventario[i].anio);
            printf("Categoria: %s\n", inventario[i].categoria);
            printf("Ubicacion: %s\n", inventario[i].ubicacion);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("\nRepuesto no encontrado.\n");
    }

    system("pause");
}

/* ===== ELIMINAR REPUESTO ===== */
void eliminarRepuesto() {
    int num, i;
    system("cls");

    if (total == 0) {
        printf("No hay repuestos.\n");
        system("pause");
        return;
    }

    for (i = 0; i < total; i++) {
        printf("%d. %s\n", i + 1, inventario[i].nombre);
    }

    printf("\nNumero del repuesto a eliminar: ");
    scanf("%d", &num);

    num--;

    if (num < 0 || num >= total) {
        printf("Numero invalido.\n");
        system("pause");
        return;
    }

    for (i = num; i < total - 1; i++) {
        inventario[i] = inventario[i + 1];
    }

    total--;
    printf("\nRepuesto eliminado.\n");
    system("pause");
}

/* ===== MENU INVENTARIO ===== */
void menuInventario() {
    int opcion;

    do {
        system("cls");
        printf("===== MENU DE ACCESO =====\n");
        printf("1. Registrar repuesto\n");
        printf("2. Mostrar inventario\n");
        printf("3. Buscar repuesto\n");
        printf("4. Eliminar repuesto\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: registrarRepuesto(); break;
            case 2: mostrarInventario(); break;
            case 3: buscarRepuesto(); break;
            case 4: eliminarRepuesto(); break;
            case 5:
                printf("Cerrando sesion...\n");
                system("pause");
                break;
            default:
                printf("Opcion invalida.\n");
                system("pause");
        }

    } while (opcion != 5);
}

/* ===== REGISTRO ===== */
void registro() {
    system("cls");

    printf("=== REGISTRO ===\n");
    printf("Usuario: ");
    scanf("%s", usuario);

    printf("Contrasena: ");
    scanf("%s", clave);

    usuarioRegistrado = 1;

    printf("\nRegistro exitoso.\n");
    system("pause");
}

/* ===== LOGIN ===== */
int login() {
    char u[STR], c[STR];

    system("cls");

    if (!usuarioRegistrado) {
        printf("No hay usuarios registrados.\n");
        system("pause");
        return 0;
    }

    printf("=== INICIO DE SESION ===\n");
    printf("Usuario: ");
    scanf("%s", u);

    printf("Contrasena: ");
    scanf("%s", c);

    if (strcmp(u, usuario) == 0 && strcmp(c, clave) == 0) {
        printf("\nAcceso concedido.\n");
        system("pause");
        return 1;
    }

    printf("\nDatos incorrectos.\n");
    system("pause");
    return 0;
}

/* ===== MAIN ===== */
int main() {
    int opcion;

    do {
        system("cls");
        printf("===== SISTEMA =====\n");
        printf("1. Iniciar sesion\n");
        printf("2. Registrarse\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (login())
                    menuInventario();
                break;
            case 2:
                registro();
                break;
            case 3:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opcion invalida.\n");
                system("pause");
        }

    } while (opcion != 3);
}

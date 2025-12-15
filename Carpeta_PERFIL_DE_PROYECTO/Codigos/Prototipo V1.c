#include <stdio.h>
#include <string.h>
#include <windns.h>

#define MAX 100
#define STR 50

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

void registrarRepuesto() {
    if (total >= MAX) {
        printf("Inventario lleno.\n");
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
    printf("Repuesto registrado.\n");
}

void mostrarInventario() {
    int i;

    printf("\n--- Inventario ---\n");

    if (total == 0) {
        printf("No hay repuestos.\n");
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
}

void buscarRepuesto() {
    char nombre[STR];
    int i, encontrado = 0;

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
        printf("Repuesto no encontrado.\n");
    }
}

void eliminarRepuesto() {
    int num, i;

    mostrarInventario();

    if (total == 0) return;

    printf("\nNumero del repuesto a eliminar: ");
    scanf("%d", &num);

    num--;

    if (num < 0 || num >= total) {
        printf("Numero invalido.\n");
        return;
    }

    for (i = num; i < total - 1; i++) {
        inventario[i] = inventario[i + 1];
    }

    total--;
    printf("Repuesto eliminado.\n");
}

int main() {
    int opcion;

    do {
        printf("\n===== MENU INVENTARIO =====\n");
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
            case 5: printf("Saliendo...\n"); break;
            default: printf("Opcion invalida.\n");
        }

    } while (opcion != 5);
}

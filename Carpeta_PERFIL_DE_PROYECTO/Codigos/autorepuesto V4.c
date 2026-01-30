#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
#define STR 50

void limpiarBuffer();
void guardarUsuario();
void cargarUsuario();
void guardarInventario();
void cargarInventario();
void registro();
int login();
void menuInventario();
void registrarRepuesto();
void mostrarInventario();
void buscarRepuesto();
void eliminarRepuesto();


void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// ===== USUARIO ===== //
char usuario[STR];
char clave[STR];
int usuarioRegistrado = 0;

// ===== INVENTARIO ===== //
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

/* ===== ARCHIVOS ===== */
void guardarUsuario() {
    FILE *f = fopen("usuario.txt", "w");
    if (f != NULL) {
        fprintf(f, "%s %s", usuario, clave);
        fclose(f);
    }
}

void cargarUsuario() {
    FILE *f = fopen("usuario.txt", "r");
    if (f != NULL) {
        fscanf(f, "%s %s", usuario, clave);
        usuarioRegistrado = 1;
        fclose(f);
    }
}

void guardarInventario() {
    FILE *f = fopen("inventario.txt", "w");
    int i;
    if (f != NULL) {
        fprintf(f, "%d\n", total);
        for (i = 0; i < total; i++) {
            fprintf(f, "%s %s %s %s %s %s\n",
                inventario[i].nombre,
                inventario[i].marca,
                inventario[i].modelo,
                inventario[i].anio,
                inventario[i].categoria,
                inventario[i].ubicacion);
        }
        fclose(f);
    }
}

void cargarInventario() {
    FILE *f = fopen("inventario.txt", "r");
    int i;
    if (f != NULL) {
        fscanf(f, "%d", &total);
        limpiarBuffer();
        for (i = 0; i < total; i++) {
            fscanf(f, "%s %s %s %s %s %s",
                inventario[i].nombre,
                inventario[i].marca,
                inventario[i].modelo,
                inventario[i].anio,
                inventario[i].categoria,
                inventario[i].ubicacion);
            limpiarBuffer();
        }
        fclose(f);
    }
}

// ===== REGISTRO ===== //
void registro() {
    system("cls");
    printf("=== REGISTRO ===\n");

    printf("Usuario: ");
    scanf("%s", usuario);
    limpiarBuffer();

    printf("Contrasena: ");
    scanf("%s", clave);
    limpiarBuffer();

    usuarioRegistrado = 1;
    guardarUsuario();

    printf("\nRegistro exitoso.\n");
    system("pause");
}

// ===== LOGIN ===== //
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
    limpiarBuffer();

    printf("Contrasena: ");
    scanf("%s", c);
    limpiarBuffer();

    if (strcmp(u, usuario) == 0 && strcmp(c, clave) == 0) {
        printf("\nAcceso concedido.\n");
        system("pause");
        return 1;
    }

    printf("\nDatos incorrectos.\n");
    system("pause");
    return 0;
}

// ===== MENU ===== //
void menuInventario() {
    int opcion;
    do {
        system("cls");
        printf("===== MENU INVENTARIO =====\n");
        printf("1. Registrar repuesto\n");
        printf("2. Mostrar inventario\n");
        printf("3. Buscar repuesto\n");
        printf("4. Eliminar repuesto\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        limpiarBuffer();

        switch (opcion) {
            case 1: registrarRepuesto(); break;
            case 2: mostrarInventario(); break;
            case 3: buscarRepuesto(); break;
            case 4: eliminarRepuesto(); break;
        }

    } while (opcion != 5);
}

// ===== REGISTRAR REPUESTO ===== //
void registrarRepuesto() {
    system("cls");

    if (total >= MAX) {
        printf("Inventario lleno.\n");
        system("pause");
        return;
    }

    printf("--- Registrar repuesto ---\n");

    printf("Nombre: ");
    scanf("%s", inventario[total].nombre);
    limpiarBuffer();

    printf("Marca: ");
    scanf("%s", inventario[total].marca);
    limpiarBuffer();

    printf("Modelo: ");
    scanf("%s", inventario[total].modelo);
    limpiarBuffer();

    printf("Anio: ");
    scanf("%s", inventario[total].anio);
    limpiarBuffer();

    printf("Categoria: ");
    scanf("%s", inventario[total].categoria);
    limpiarBuffer();

    printf("Ubicacion: ");
    scanf("%s", inventario[total].ubicacion);
    limpiarBuffer();

    total++;
    guardarInventario();

    printf("\nRepuesto registrado.\n");
    system("pause");
}

// ===== MOSTRAR INVENTARIO ===== //
void mostrarInventario() {
    int i;
    system("cls");

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

// ===== BUSCAR REPUESTO ===== //
void buscarRepuesto() {
    char nombre[STR];
    int i, encontrado = 0;

    system("cls");
    printf("Nombre a buscar: ");
    scanf("%s", nombre);
    limpiarBuffer();

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

    if (!encontrado)
        printf("\nRepuesto no encontrado.\n");

    system("pause");
}

// ===== ELIMINAR REPUESTO ===== //
void eliminarRepuesto() {
    int num, i;
    system("cls");

    if (total == 0) {
        printf("No hay repuestos.\n");
        system("pause");
        return;
    }

    for (i = 0; i < total; i++)
        printf("%d. %s\n", i + 1, inventario[i].nombre);

    printf("Numero a eliminar: ");
    scanf("%d", &num);
    limpiarBuffer();

    num--;

    if (num < 0 || num >= total) {
        printf("Numero invalido.\n");
        system("pause");
        return;
    }

    for (i = num; i < total - 1; i++)
        inventario[i] = inventario[i + 1];

    total--;
    guardarInventario();

    printf("\nRepuesto eliminado.\n");
    system("pause");
}

// ===== INICIO DE SESION ===== //
int main() {
    int opcion;

    cargarUsuario();
    cargarInventario();

    do {
        system("cls");
        printf("===== SISTEMA =====\n");
        printf("1. Iniciar sesion\n");
        printf("2. Registrarse\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        limpiarBuffer();

        switch (opcion) {
            case 1:
                if (login())
                    menuInventario();
                break;
            case 2:
                registro();
                break;
        }

    } while (opcion != 3);
}

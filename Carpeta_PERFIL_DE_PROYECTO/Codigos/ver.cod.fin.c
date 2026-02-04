#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
#define STR 50

/* ===== PROTOTIPOS ===== */
void limpiarBuffer();
void quitarSalto(char texto[]);
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
int confirmarEliminacion();

/* ===== LIMPIEZA ===== */
void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void quitarSalto(char texto[]) {
    texto[strcspn(texto, "\n")] = '\0';
}

/* ===== USUARIO ===== */
char usuario[STR];
char clave[STR];
int usuarioRegistrado = 0;

/* ===== INVENTARIO ===== */
struct Repuesto {
    int codigo;
    char nombre[STR];
    char marca[STR];
    char modelo[STR];
    char anio[STR];
    char categoria[STR];
    char ubicacion[STR];
};

struct Repuesto inventario[MAX];
int total = 0;
int siguienteCodigo = 1001;

/* ===== ARCHIVOS ===== */
void guardarUsuario() {
    FILE *f = fopen("usuario.txt", "w");
    if (f) {
        fprintf(f, "%s\n%s\n", usuario, clave);
        fclose(f);
    }
}

void cargarUsuario() {
    FILE *f = fopen("usuario.txt", "r");
    if (f) {
        fgets(usuario, STR, f);
        fgets(clave, STR, f);
        quitarSalto(usuario);
        quitarSalto(clave);
        usuarioRegistrado = 1;
        fclose(f);
    }
}

void guardarInventario() {
    FILE *f = fopen("inventario.txt", "w");
    int i;
    if (f) {
        fprintf(f, "%d\n%d\n", total, siguienteCodigo);
        for (i = 0; i < total; i++) {
            fprintf(f, "%d\n%s\n%s\n%s\n%s\n%s\n%s\n",
                inventario[i].codigo,
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
    if (f) {
        fscanf(f, "%d\n%d\n", &total, &siguienteCodigo);
        for (i = 0; i < total; i++) {
            fscanf(f, "%d\n", &inventario[i].codigo);
            fgets(inventario[i].nombre, STR, f);
            fgets(inventario[i].marca, STR, f);
            fgets(inventario[i].modelo, STR, f);
            fgets(inventario[i].anio, STR, f);
            fgets(inventario[i].categoria, STR, f);
            fgets(inventario[i].ubicacion, STR, f);

            quitarSalto(inventario[i].nombre);
            quitarSalto(inventario[i].marca);
            quitarSalto(inventario[i].modelo);
            quitarSalto(inventario[i].anio);
            quitarSalto(inventario[i].categoria);
            quitarSalto(inventario[i].ubicacion);
        }
        fclose(f);
    }
}

/* ===== REGISTRO ===== */
void registro() {
    system("cls");
    printf("=== REGISTRO ===\n");

    printf("Usuario: ");
    fgets(usuario, STR, stdin);
    quitarSalto(usuario);

    printf("Contrasena: ");
    fgets(clave, STR, stdin);
    quitarSalto(clave);

    usuarioRegistrado = 1;
    guardarUsuario();

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
    fgets(u, STR, stdin);
    quitarSalto(u);

    printf("Contrasena: ");
    fgets(c, STR, stdin);
    quitarSalto(c);

    if (strcmp(u, usuario) == 0 && strcmp(c, clave) == 0) {
        printf("\nAcceso concedido.\n");
        system("pause");
        return 1;
    }

    printf("\nDatos incorrectos.\n");
    system("pause");
    return 0;
}

/* ===== MENU INVENTARIO ===== */
void menuInventario() {
    int opcion;
    do {
        system("cls");
        printf("===== MENU INVENTARIO =====\n");
        printf("1. Registrar repuesto\n");
        printf("2. Mostrar inventario\n");
        printf("3. Buscar repuesto por nombre\n");
        printf("4. Eliminar repuesto por codigo\n");
        printf("5. Salir\n");
        printf("Opcion: ");
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

/* ===== REGISTRAR ===== */
void registrarRepuesto() {
    system("cls");

    if (total >= MAX) {
        printf("Inventario lleno.\n");
        system("pause");
        return;
    }

    inventario[total].codigo = siguienteCodigo++;

    printf("--- REGISTRAR REPUESTO ---\n");
    printf("Codigo asignado: %d\n\n", inventario[total].codigo);

    printf("Nombre: ");     fgets(inventario[total].nombre, STR, stdin);
    printf("Marca: ");      fgets(inventario[total].marca, STR, stdin);
    printf("Modelo: ");     fgets(inventario[total].modelo, STR, stdin);
    printf("Anio: ");       fgets(inventario[total].anio, STR, stdin);
    printf("Categoria: ");  fgets(inventario[total].categoria, STR, stdin);
    printf("Ubicacion: ");  fgets(inventario[total].ubicacion, STR, stdin);

    quitarSalto(inventario[total].nombre);
    quitarSalto(inventario[total].marca);
    quitarSalto(inventario[total].modelo);
    quitarSalto(inventario[total].anio);
    quitarSalto(inventario[total].categoria);
    quitarSalto(inventario[total].ubicacion);

    total++;
    guardarInventario();

    printf("\nRepuesto registrado correctamente.\n");
    system("pause");
}

/* ===== MOSTRAR ===== */
void mostrarInventario() {
    int i;
    system("cls");

    if (total == 0) {
        printf("No hay repuestos.\n");
        system("pause");
        return;
    }

    for (i = 0; i < total; i++) {
        printf("\nCodigo: %d\n", inventario[i].codigo);
        printf("Nombre: %s\n", inventario[i].nombre);
        printf("Marca: %s\n", inventario[i].marca);
        printf("Modelo: %s\n", inventario[i].modelo);
        printf("Anio: %s\n", inventario[i].anio);
        printf("Categoria: %s\n", inventario[i].categoria);
        printf("Ubicacion: %s\n", inventario[i].ubicacion);
    }

    system("pause");
}

/* ===== BUSCAR ===== */
void buscarRepuesto() {
    char texto[STR];
    int i, encontrado = 0;

    system("cls");
    printf("Ingrese nombre o descripcion: ");
    fgets(texto, STR, stdin);
    quitarSalto(texto);

    printf("\n--- RESULTADOS ---\n");

    for (i = 0; i < total; i++) {
        if (strstr(inventario[i].nombre, texto) != NULL) {
            printf("\nCodigo: %d\n", inventario[i].codigo);
            printf("Nombre: %s\n", inventario[i].nombre);
            printf("Marca: %s\n", inventario[i].marca);
            printf("Modelo: %s\n", inventario[i].modelo);
            printf("Anio: %s\n", inventario[i].anio);
            printf("Categoria: %s\n", inventario[i].categoria);
            printf("Ubicacion: %s\n", inventario[i].ubicacion);
            encontrado = 1;
        }
    }

    if (!encontrado)
        printf("\nNo se encontraron coincidencias.\n");

    system("pause");
}

/* ===== CONFIRMAR ===== */
int confirmarEliminacion() {
    int op;
    printf("\nConfirmar eliminacion\n");
    printf("1. Si\n2. No\nOpcion: ");
    scanf("%d", &op);
    limpiarBuffer();
    return (op == 1);
}

/* ===== ELIMINAR (MUESTRA DATOS COMPLETOS) ===== */
void eliminarRepuesto() {
    int codigo, i, j;

    system("cls");
    printf("Codigo del repuesto a eliminar: ");
    scanf("%d", &codigo);
    limpiarBuffer();

    for (i = 0; i < total; i++) {
        if (inventario[i].codigo == codigo) {

            printf("\n--- REPUESTO ENCONTRADO ---\n");
            printf("Codigo: %d\n", inventario[i].codigo);
            printf("Nombre: %s\n", inventario[i].nombre);
            printf("Marca: %s\n", inventario[i].marca);
            printf("Modelo: %s\n", inventario[i].modelo);
            printf("Anio: %s\n", inventario[i].anio);
            printf("Categoria: %s\n", inventario[i].categoria);
            printf("Ubicacion: %s\n", inventario[i].ubicacion);

            if (!confirmarEliminacion()) {
                printf("\nEliminacion cancelada.\n");
                system("pause");
                return;
            }

            for (j = i; j < total - 1; j++)
                inventario[j] = inventario[j + 1];

            total--;
            guardarInventario();

            printf("\nRepuesto eliminado correctamente.\n");
            system("pause");
            return;
        }
    }

    printf("\nCodigo no encontrado.\n");
    system("pause");
}

/* ===== MAIN ===== */
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
        printf("Opcion: ");
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

    return 0;
}

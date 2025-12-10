#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Repuesto {
    string nombre;
    string marca;
    string modelo;
    string anios;
    string categoria;
    string ubicacion;
};

// --------------------------------------------------
// Guardar inventario en archivo
// --------------------------------------------------
void guardarInventario(vector<Repuesto>& inventario) {
    ofstream archivo("inventario.txt");

    for (auto& rep : inventario) {
        archivo << rep.nombre << ";"
                << rep.marca << ";"
                << rep.modelo << ";"
                << rep.anios << ";"
                << rep.categoria << ";"
                << rep.ubicacion << "\n";
    }

    archivo.close();
    cout << "\nInventario guardado correctamente.\n\n";
}

// --------------------------------------------------
// Cargar inventario desde archivo
// --------------------------------------------------
vector<Repuesto> cargarInventario() {
    vector<Repuesto> inventario;
    ifstream archivo("inventario.txt");

    if (!archivo.is_open()) return inventario;

    string linea;
    while (getline(archivo, linea)) {
        Repuesto r;
        int pos = 0;
        int campo = 0;
        string temp;

        for (char c : linea) {
            if (c == ';') {
                if (campo == 0) r.nombre = temp;
                if (campo == 1) r.marca = temp;
                if (campo == 2) r.modelo = temp;
                if (campo == 3) r.anios = temp;
                if (campo == 4) r.categoria = temp;
                temp = "";
                campo++;
            } else {
                temp += c;
            }
        }
        r.ubicacion = temp;
        inventario.push_back(r);
    }

    archivo.close();
    return inventario;
}

// --------------------------------------------------
// Registrar repuesto
// --------------------------------------------------
void registrarRepuesto(vector<Repuesto>& inv) {
    Repuesto r;
    cout << "\n--- Registrar nuevo repuesto ---\n";

    cout << "Nombre del repuesto: ";
    getline(cin, r.nombre);

    cout << "Marca del vehiculo: ";
    getline(cin, r.marca);

    cout << "Modelo del vehiculo: ";
    getline(cin, r.modelo);

    cout << "Anio del vehiculo: ";
    getline(cin, r.anios);

    cout << "Categoria: ";
    getline(cin, r.categoria);

    cout << "Ubicacion: ";
    getline(cin, r.ubicacion);

    inv.push_back(r);
    guardarInventario(inv);

    cout << "Repuesto registrado con exito.\n\n";
}

// --------------------------------------------------
// Mostrar inventario
// --------------------------------------------------
void mostrarInventario(vector<Repuesto>& inv) {
    cout << "\n--- Inventario Completo ---\n";

    if (inv.empty()) {
        cout << "No hay repuestos registrados.\n\n";
        return;
    }

    for (int i = 0; i < inv.size(); i++) {
        cout << "\nRepuesto #" << (i + 1) << "\n";
        cout << "Nombre: " << inv[i].nombre << "\n";
        cout << "Marca: " << inv[i].marca << "\n";
        cout << "Modelo: " << inv[i].modelo << "\n";
        cout << "Anio: " << inv[i].anios << "\n";
        cout << "Categoria: " << inv[i].categoria << "\n";
        cout << "Ubicacion: " << inv[i].ubicacion << "\n";
    }
    cout << "\n";
}

// --------------------------------------------------
// Buscar repuesto
// --------------------------------------------------
void buscarRepuesto(vector<Repuesto>& inv) {
    cout << "\n--- Buscar Repuesto ---\n";
    cout << "Ingrese nombre o categoria: ";

    string criterio;
    getline(cin, criterio);

    bool encontrado = false;

    for (auto& r : inv) {
        if (r.nombre.find(criterio) != string::npos ||
            r.categoria.find(criterio) != string::npos) {

            cout << "- " << r.nombre << " (" << r.categoria
                 << ") -> Ubicacion: " << r.ubicacion << "\n";
            encontrado = true;
        }
    }

    if (!encontrado)
        cout << "No se encontraron repuestos.\n";
}

// --------------------------------------------------
// Editar repuesto
// --------------------------------------------------
void editarRepuesto(vector<Repuesto>& inv) {
    mostrarInventario(inv);
    if (inv.empty()) return;

    cout << "Numero del repuesto a editar: ";
    int idx;
    cin >> idx;
    cin.ignore();
    idx--;

    if (idx < 0 || idx >= inv.size()) {
        cout << "Indice invalido.\n";
        return;
    }

    Repuesto &r = inv[idx];

    string temp;

    cout << "Nombre (" << r.nombre << "): ";
    getline(cin, temp);
    if (!temp.empty()) r.nombre = temp;

    cout << "Marca (" << r.marca << "): ";
    getline(cin, temp);
    if (!temp.empty()) r.marca = temp;

    cout << "Modelo (" << r.modelo << "): ";
    getline(cin, temp);
    if (!temp.empty()) r.modelo = temp;

    cout << "Anio (" << r.anios << "): ";
    getline(cin, temp);
    if (!temp.empty()) r.anios = temp;

    cout << "Categoria (" << r.categoria << "): ";
    getline(cin, temp);
    if (!temp.empty()) r.categoria = temp;

    cout << "Ubicacion (" << r.ubicacion << "): ";
    getline(cin, temp);
    if (!temp.empty()) r.ubicacion = temp;

    guardarInventario(inv);
    cout << "Repuesto actualizado.\n\n";
}

// --------------------------------------------------
// Eliminar repuesto
// --------------------------------------------------
void eliminarRepuesto(vector<Repuesto>& inv) {
    mostrarInventario(inv);
    if (inv.empty()) return;

    cout << "Numero de repuesto a eliminar: ";
    int idx;
    cin >> idx;
    cin.ignore();
    idx--;

    if (idx < 0 || idx >= inv.size()) {
        cout << "Indice invalido.\n";
        return;
    }

    cout << "Repuesto " << inv[idx].nombre << " eliminado.\n";
    inv.erase(inv.begin() + idx);
    guardarInventario(inv);
}

// --------------------------------------------------
// Borrar todo el inventario
// --------------------------------------------------
void limpiarInventario(vector<Repuesto>& inv) {
    cout << "\nSeguro que desea borrar TODO el inventario? (S/N): ";
    char op;
    cin >> op;
    cin.ignore();

    if (op == 'S' || op == 's') {
        inv.clear();
        guardarInventario(inv);
        cout << "Inventario vaciado.\n";
    } else {
        cout << "Operacion cancelada.\n";
    }
}

// --------------------------------------------------
// Menu principal
// --------------------------------------------------
int main() {
    vector<Repuesto> inventario = cargarInventario();

    while (true) {
        cout << "=========== Sistema de Inventario ===========\n";
        cout << "1. Registrar repuesto\n";
        cout << "2. Mostrar inventario\n";
        cout << "3. Buscar repuesto\n";
        cout << "4. Editar repuesto\n";
        cout << "5. Eliminar repuesto\n";
        cout << "6. Borrar todo el inventario\n";
        cout << "7. Salir\n";
        cout << "=============================================\n";
        cout << "Seleccione una opcion: ";

        string opcion;
        getline(cin, opcion);

        if (opcion == "1") registrarRepuesto(inventario);
        else if (opcion == "2") mostrarInventario(inventario);
        else if (opcion == "3") buscarRepuesto(inventario);
        else if (opcion == "4") editarRepuesto(inventario);
        else if (opcion == "5") eliminarRepuesto(inventario);
        else if (opcion == "6") limpiarInventario(inventario);
        else if (opcion == "7") {
            cout << "Saliendo del sistema...\n";
            break;
        } else {
            cout << "Opcion invalida.\n";
        }
    }

    return 0;
}

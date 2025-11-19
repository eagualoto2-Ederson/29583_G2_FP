#include <iostream>
using namespace std;

int main() {
    double x;
    double suma = 0;
    int cont = 0;

    cout << "Ingrese 3 numeros reales (solo se promedian los positivos):\n";

    int i = 1;
    while (i <= 3) {  // salida en cabeza
        cout << "Numero " << i << ": ";
        cin >> x;

        if (x > 0) {
            suma += x;
            cont++;
        }

        i++;
    }

    if (cont > 0)
        cout << "La media de los numeros positivos es: " << (suma / cont) << endl;
    else
        cout << "No se ingresaron numeros positivos.\n";

    return 0;
}

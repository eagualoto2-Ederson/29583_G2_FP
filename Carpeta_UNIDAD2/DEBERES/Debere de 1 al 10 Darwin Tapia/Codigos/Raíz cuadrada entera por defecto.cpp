#include <iostream>
using namespace std;

int main() {
    int N, R = 0;

    cout << "Ingrese un numero positivo N: ";
    cin >> N;

    while ((R + 1) * (R + 1) <= N) {
        R++;
    }

    cout << "La raiz cuadrada entera por defecto es: " << R << endl;

    return 0;
}

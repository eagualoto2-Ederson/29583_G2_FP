#include <iostream>
using namespace std;

int main() {
    double X;

    cout << "Ingrese un numero real: ";
    cin >> X;

    if (X > 0 && X <= 10) {
        cout << "El numero pertenece al intervalo (0, 10]." << endl;
    } else {
        cout << "El numero NO pertenece al intervalo." << endl;
    }

    return 0;
}

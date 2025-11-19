#include <iostream>
using namespace std;

int main() {
    int A, B;

    cout << "Ingrese el primer numero entero: ";
    cin >> A;

    cout << "Ingrese el segundo numero entero: ";
    cin >> B;

    if (B == 0) {
        cout << "No se puede dividir entre cero." << endl;
    } else {
        if (A % B == 0) {
            cout << A << " ES divisible por " << B << endl;
        } else {
            cout << A << " NO es divisible por " << B << endl;
        }
    }

    return 0;
}

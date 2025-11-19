#include <iostream>
using namespace std;

bool esPrimo(int n) {
    int d = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) d++;
    }
    return d == 2;
}

int main() {
    int a, b;

    cout << "Ingrese el limite inferior: ";
    cin >> a;

    cout << "Ingrese el limite superior: ";
    cin >> b;

    cout << "Numeros primos entre " << a << " y " << b << ":\n";

    for (int i = a; i <= b; i++) {
        if (esPrimo(i))
            cout << i << " ";
    }

    cout << endl;

    return 0;
}

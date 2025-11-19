#include <iostream>
using namespace std;

int main() {
    int n, divisores = 0;

    cout << "Ingrese un numero entero mayor que 1: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        if (n % i == 0)
            divisores++;
    }

    if (divisores == 2)
        cout << n << " es primo.\n";
    else
        cout << n << " NO es primo.\n";

    return 0;
}

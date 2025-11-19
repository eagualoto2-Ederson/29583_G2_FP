#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double X, RES;

    cout << "Ingrese un numero real X: ";
    cin >> X;

    RES = pow(fabs(X), 3);

    cout << "|X| al cubo es: " << RES << endl;

    return 0;
}

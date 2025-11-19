#include <iostream>
#include <cmath>  // Para usar fabs()

using namespace std;

int main() {
    // Declaración de variables
    double X;    // Número ingresado por el usuario
    double RES;  // Resultado del cálculo

    // Solicitar número al usuario
    cout << "Ingrese un numero real X: ";
    cin >> X;

    // Obtener el valor absoluto de X
    double Xabs = fabs(X);

    // Elevar al cubo
    RES = pow(Xabs, 3);  // Alternativa a Xabs*Xabs*Xabs

    // Mostrar resultado
    cout << "El valor absoluto de X al cubo es: " << RES << endl;

    return 0;
}

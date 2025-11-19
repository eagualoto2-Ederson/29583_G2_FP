#include <iostream>
using namespace std;
int main() {
    int X;
    int dias, horas, minutos, segundos;
    cout << "Ingrese el numero total de segundos: ";
    cin >> X;
    dias = X / 86400;           // 1 dia = 86400 segundos
    X = X % 86400;
    horas = X / 3600;           // 1 hora = 3600 segundos
    X = X % 3600;
    minutos = X / 60;           // 1 minuto = 60 segundos
    segundos = X % 60;
    cout << "Equivale a: " << endl;
    cout << dias << " dias, "
         << horas << " horas, "
         << minutos << " minutos y "
         << segundos << " segundos." << endl;
    return 0;
}

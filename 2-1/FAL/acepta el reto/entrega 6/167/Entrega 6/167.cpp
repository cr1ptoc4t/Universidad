#include <iostream>
using namespace std;

int fractales(int longitud, int numeroCuadrados);

bool casoDePrueba() {
    int longitud;
    cin >> longitud;

    if (!cin)
        return false;
    else {
        if (longitud == 0)cout << "0" << endl;
        else{
            int num = fractales(longitud, 1);
            cout << num << endl;
        }

        return true;
    }

} // casoDePrueba

int main() {

    while (casoDePrueba())
        ;

    return 0;

} // main


int fractales(int longitud, int numeroCuadrados) {
    int sumaLongitud;
    if (longitud == 1) sumaLongitud = 4 * numeroCuadrados;
    else sumaLongitud = fractales(longitud / 2, 4 * numeroCuadrados) + numeroCuadrados * 4 * longitud;
    return sumaLongitud;
}
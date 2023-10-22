// Esquema de la entrada: caso de prueba que marca el final
#include <iostream>
using namespace std;

int calcula(int ancho, int alto, int num);


bool casoDePrueba() {

    // LEER CASO DE PRUEBA
    int ancho, alto;
    cin >> ancho>> alto;

        if (ancho==0||alto==0)
            return false;
        else {
            int num = calcula(ancho, alto,0);
            cout << num << "\n";
            return true;
        }

} // casoDePrueba

int main() {

    while (casoDePrueba())
        ;

    return 0;

} // main

int calcula(int ancho, int alto, int num)
{
    if (ancho < 10 || alto < 10)
        return num;

    if (ancho > alto)
        num = calcula(ancho-alto, alto, num + 1);
    else if (alto == ancho)
        num++;
    else
        num = calcula(ancho, alto-ancho, num + 1);

}

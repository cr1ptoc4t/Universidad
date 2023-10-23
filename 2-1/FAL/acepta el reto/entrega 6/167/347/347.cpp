// Esquema de la entrada: caso de prueba que marca el final
#include <iostream>
using namespace std;

int calcula( int ancho, int alto);


bool casoDePrueba() {

    // LEER CASO DE PRUEBA
    int ancho, alto;
    cin >> ancho>> alto;
    if (ancho == 0 && alto == 0)
        return false;
    

    int num = calcula(ancho, alto);
    cout << num << "\n";        
    
    return true;

} // casoDePrueba

int main() {

    while (casoDePrueba())
        ;

    return 0;

} // main

int calcula( int ancho,  int alto)
{
    int suma = 0;
    while (!(alto < 10 || ancho < 10)) {
        if (alto > ancho)
            alto = alto - ancho;
        else
            ancho = ancho - alto;
        suma++;
    }
    return suma;
}

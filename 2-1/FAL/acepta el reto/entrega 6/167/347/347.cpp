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
    int res;
    if (alto < 10 || ancho < 10)
        return 0;
    if (ancho > alto) {
        res = ancho / alto;
        ancho = ancho - res * alto;
        return res + calcula(ancho, alto);
    }
    else {
        res = alto / ancho;
        alto = alto - res * ancho;
        return res + calcula(ancho, alto);
    }
}


/*
* 
*       if (2 * alto > ancho) {
            while (alto > ancho) {
                alto -= ancho;
                num++;
            }
       }
*/
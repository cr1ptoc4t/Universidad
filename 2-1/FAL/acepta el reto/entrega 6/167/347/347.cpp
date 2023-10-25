// Esquema de la entrada: caso de prueba que marca el final
#include <iostream>
using namespace std;

int calcula( int ancho, int alto, int num);


bool casoDePrueba() {

    // LEER CASO DE PRUEBA
    int ancho, alto;
    cin >> ancho>> alto;
    if (ancho == 0 && alto == 0)
        return false;
    

    int num = calcula(ancho, alto,0);
    cout << num << "\n";        
    
    return true;

} // casoDePrueba

int main() {

    while (casoDePrueba())
        ;

    return 0;

} // main

int calcula( int ancho,  int alto, int num)
{
    while(ancho!=alto&& !(ancho < 10 || alto < 10)){

        while (alto > ancho) {
            alto -= ancho;
            num++;
        }

        while (ancho > alto && !(ancho < 10 || alto < 10)) {
            ancho -= alto;
            num++;
        }

    }
    if (ancho == alto)
        num++;

    return num;
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
#include <iostream>
using namespace std;

bool recursivo(int longitud, int& num, int iteracion);

bool casoDePrueba() {

    if (!cin)
        return false;
    else {
        //datos
        //alg recursivo
        int longitud, num=0;
        cin >> longitud;

        if (longitud <= 2) {
            num = longitud * 4;
        }else
            recursivo(longitud*2, num, 1);
      
        cout << num << endl;


        return true;
    }

} // casoDePrueba

int main() {

    while (casoDePrueba())
        ;

    return 0;

} // main

bool recursivo(int longitud, int& num, int iteracion) {

    longitud /= 2;
    num += longitud * 4 * iteracion;
     if (longitud <= 1)
        return false;
    else{
        recursivo(longitud, num, iteracion*4);
    }
}
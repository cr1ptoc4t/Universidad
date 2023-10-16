#include <iostream>
using namespace std;


int fractal(int n);

bool casoDePrueba() {

    if (!cin)
        return false;
    else {
        //datos
        //alg recursivo
        int longitud, num=0;
        cin >> longitud;

        //recursivo(longitud, num, 1);
        num=fractal(longitud);
        cout << num << endl;


        return true;
    }

} // casoDePrueba

int main() {

    while (casoDePrueba())
        ;

    return 0;

} // main

int fractal(int n) {

    if (n == 0)
        return 0;
    int ret = 0;
    ret = 4 * n + 4 * fractal(n/2);

    return ret;
}
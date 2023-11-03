// Esquema de la entrada: caso de prueba que marca el final
#include <iostream>
using namespace std;

bool casoDePrueba() {
    int ini, fin, n;
    cin >> ini >> fin >> n;

        if (ini==0&& fin==0&&n==0)
            return false;
        else {
            bool adivina = adivinar(ini, fin ,n);

            return true;
        }

} // casoDePrueba

int main() {

    while (casoDePrueba())
        ;

    return 0;

} // main


bool adivinar(int ini, int fin, int n) {
    int k;
    cin >> k;
    

    return false;
}
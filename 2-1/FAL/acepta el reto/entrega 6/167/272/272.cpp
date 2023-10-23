// Esquema de la entrada: número de casos
#include <iostream>
#include <string>
using namespace std;

void casoDePrueba();
void convertir(int num);

int main() {

    unsigned int numCasos;

    cin >> numCasos;
    for (unsigned int i = 0; i < numCasos; ++i) {
        casoDePrueba();
    }

    return 0;

} // main

void casoDePrueba() {
    int num;
    cin >> num;

    convertir(num);

    cout << "\n";


} // casoDePrueba

void convertir(int num) {

    if (num< 6) {
        cout << num;
        return ;
    }

    
    convertir(num/6);
    cout << num % 6;
}
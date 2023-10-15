// Esquema de la entrada: caso de prueba que marca el final
#include <iostream>
using namespace std;

bool casoDePrueba();

int main() {

    while (casoDePrueba()) {

    }

    return 0;

} // main

bool casoDePrueba() {

    // LEER CASO DE PRUEBA
    int n;
    int vCubierta[100][100]; //tiene que ser 1000000
    cin >> n;
        if (n==0)
            return false;
        else {
            // CÓDIGO PRINCIPAL AQUÍ
            // Procesa un único caso.
            // Evita el uso de endl.
            int cubierta;
            for (int i = 0; i < n; i++) {
                cin >> cubierta;
                int j = 0;
                while (vCubierta[j][0] < cubierta && j<n) {
                    j++;
                }
                if (vCubierta[j][0] < 0){
                    vCubierta[j][0] = cubierta;
                    vCubierta[j][1] = 1;
                } else  vCubierta[j][1]++;
            }

            int n2;
            string accion;
            cin >> n2;
            for (int i = 0; i < n2; i++) {
                cin >> accion;
                if (accion == "EMBARQUE") {
                    // NUM CUBIERTA;
                }
                else if (accion == "CONSULTA") {
                    //posicion en la cola
                }
            }


            cout << "*" << '\n';
            return true;
        }

} // casoDePrueba

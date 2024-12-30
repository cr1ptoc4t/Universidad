/***********************************************************************
 * Prepara el resto de tus asignaturas y aprueba todos los exámenes
 * finales con PROXUS!
 *
 * Todos los SPEEDRUNS disponibles:
 * https://www.proxusacademy.com
 *
 * Creado por PROXUS Academy
 ***********************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

void resolverCaso(vector<int>& beneficios, int n, int limite) {
    int long_max = 0;
    int ini = 0;
    int cont_max = 0;
    for (int fin = 0; fin < n; fin++) {
        if (beneficios[ini]>=limite) {
            ini = fin + 1;
        }
        else {
            cont_max = max(fin-ini+1, cont_max);
        }
    }
    cout << cont_max<< endl;

}

bool resuelveCaso() {
    // Leer los datos de entrada
    int n, limite;
    cin >> n;

    if (n == 0)
        return false;

    cin >> limite;
    vector<int> beneficios(n);
    for (int i = 0; i < n; ++i) {
        cin >> beneficios[i];
    }

    resolverCaso(beneficios, n, limite);
    return true;
}

int main() {
    // Ajustes para entrada por fichero
#ifndef PROXUS
    ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // Restablecimiento de la entrada
#ifndef PROXUS
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
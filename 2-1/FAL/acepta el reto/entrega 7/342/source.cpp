// Esquema de la entrada: caso de prueba que marca el final
#include <iostream>
using namespace std;

bool adivinar(int ini, int fin, int n);

bool casoDePrueba() {
    int ini, fin, n;
    cin >> ini >> fin >> n;

        if (ini==0&& fin==0&&n==0)
            return false;
        else {
            if (adivinar(ini, fin, n))
                cout << "LO SABE" << endl;
            else
                cout << "NO LO SABE" << endl;

            return true;
        }

} // casoDePrueba

int main() {

    while (casoDePrueba())
        ;

    return 0;

} // main


bool adivinar(int ini, int fin, int n) {
    int k, num;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int val;
        cin >> val;
        if (val < ini || val > fin) continue;
        if (val <= n) ini = val;
        else if (n < val) fin = val - 1;
    }
    
    return ini==fin;
}
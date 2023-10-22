// Esquema de la entrada: caso de prueba que marca el final
#include <iostream>
using namespace std;

bool casoDePrueba();
int cuentacopas(int n, int suma, int iteracion);

int main() {

    while (casoDePrueba())
        ;

    return 0;

} // main


bool casoDePrueba() {
    int n;
    cin >> n;

        if (n==0)
            return false;
        else {

            int suma = cuentacopas(n, 0,0);

            cout << suma << "\n";

            return true;
        }

} // casoDePrueba


int cuentacopas(int n, int suma,int iteracion) {
    if (n <= 2)
        return suma + 1;
    
    if(iteracion%2==1 && n % 2 == 0)
        cuentacopas(n-2, suma+1, iteracion+1);
    else
        cuentacopas(n-1, suma+1, iteracion+1);
   
}
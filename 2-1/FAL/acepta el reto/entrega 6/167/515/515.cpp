// Esquema de la entrada: caso de prueba que marca el final
#include <iostream>
using namespace std;

bool casoDePrueba();


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

            if (n == 1) cout << 1 <<endl;
            else if (n % 2 == 1) cout << n - 1<<endl;
            else cout << n<<endl;

            return true;
        }

} // casoDePrueba


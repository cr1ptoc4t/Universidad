// Esquema de la entrada: fin de la entrada
#include <iostream>
#include <cmath>
using namespace std;

long long int digitos(int n);
int recursivo(int num);

bool casoDePrueba() {
    int n;
    cin >> n;
    if (n<0)
        return false;
    else {
        int ndigitos = digitos(n);

        if (ndigitos == 1) cout << n << " = " << n<<endl;
        else {
            int suma = recursivo(n);
            cout << " = " << suma << '\n';
        }

        return true;
    }

} // casoDePrueba

int main() {

    while (casoDePrueba())
        ;

    return 0;

} // main


long long int digitos(int n)
{
    int dig = 0;
    while (n > 0) {

        n /= 10;
        dig++;
    }
    return dig;
}

int recursivo(int num) {
    int suma;

    if (num / 10 == 0){
        suma = num % 10;
        cout << num;
    }
    else {
        suma = recursivo(num/10)+num%10;
        cout << " + " << num % 10;
    }

    return suma;
}

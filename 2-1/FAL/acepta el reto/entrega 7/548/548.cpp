#include <iostream>
using namespace std;

void resuelveAbuelo();
bool posible(int vect[], int n, int aguanteMax, int maxParadas);

bool casoDePrueba() {



    if (!cin)
        return false;
    
    resuelveAbuelo();


    return true;

} // casoDePrueba

int main() {

    while (casoDePrueba())
        ;

    return 0;

} // main

#define MAX_N 20000
int v [MAX_N];
int n;

void resuelveAbuelo() {
    int maxParadas, suma = 0; //creo
    cin >> n >> maxParadas;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        suma+=v[i]; //????
    }

    int a = 0;
    int b = suma;
    while (a<b) {
        int m = (a + b) / 2;
        if (posible(v, suma, n ,maxParadas)) //??????
            b = m;
        else
            a = m + 1;

    }

    cout <<n<<endl; //????????????

}

bool posible(int vect[], int n, int aguanteMax, int maxParadas) {

    int i = 0;
    int aguante = aguanteMax;
    int paradas = maxParadas;
    while (i<n && paradas >=0 && vect[i]<=aguanteMax) {
        if (vect[i] > aguante) {
            --paradas;
            aguante = aguanteMax;
        }
        aguante -= vect[i];
        i++;
    }

    return i == n && paradas >= 0;
}
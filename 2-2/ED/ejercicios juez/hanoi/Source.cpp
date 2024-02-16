#include <iostream>
#include <string>
#include "Pila.h"

using namespace std;
void meterEnPila(Pila<int>& p1, Pila<int>& p2);

Pila<int> hanoificar(Pila<int>& p) {
    
    Pila<int> aux;
    Pila<int> restoaux;

    while (!p.esVacia()) {
        int elemento = p.cima();
        p.desapila();
        if (aux.esVacia() || elemento > aux.cima()) {
            aux.apila(elemento);
        }
        else {
            restoaux.apila(elemento);
        }
    }


    meterEnPila(aux, p);

    Pila <int> resto;
    meterEnPila(restoaux, resto);
    
    return resto;
}

void meterEnPila(Pila<int>& p1, Pila<int>& p2) {
    try{
        while (!p1.esVacia()) {
            int elemento = p1.cima();
            p1.desapila();
            p2.apila(elemento);
        }
    }
    catch (EPilaVacia e) {
        
    }
}



// NO MODIFICAR A PARTIR DE AQUI


void imprime(const Pila<int>& p) {
    Pila<int> p_aux = p;
    while (!p_aux.esVacia()) {
        cout << p_aux.cima() << ' ';
        p_aux.desapila();
    }
}

bool ejecuta_caso() {
    int n;
    cin >> n;
    if (n == -1) return false;
    else {
        Pila<int> p;
        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            p.apila(v);
        }
        Pila<int> resto = hanoificar(p);
        imprime(p);
        cout << "#";
        imprime(resto);
        cout << endl;
    }
    return true;
}


int main() {
    while (ejecuta_caso());
    return 0;
}
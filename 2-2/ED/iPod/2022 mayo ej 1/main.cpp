using namespace std;
#include <iostream>
#include <cmath>
#include "Arbin.h"
int rec(Arbin<int> a, int mod, int& suma);

int main() {
	//Arbin<int> a(Arbin<int>(Arbin<int> (4,6, Arbin<int>(1,4,5)), 3, Arbin<int>(1)), 5,  Arbin<int> (0,7,4));
	/*
	Arbin <int> b(1);
	b.hijoIz() = 1;

	Arbin<int> a(
		Arbin<int>(
			Arbin<int>(
				Arbin<int>(Arbin<int>(4), 6, Arbin<int>(Arbin<int>(1), 4, Arbin<int>(5))),
				3,
				b
			),
			5,
			Arbin<int>(
				Arbin<int>(0),
				7,
				Arbin<int>(4)
			)
		)
	);

	*/
	Arbin<int> a(1);

	int suma = 0;

	cout << rec(a, a.raiz(), suma) << endl;

	return 0;
}


int rec(Arbin<int> a, int mod, int& suma) {
	if (a.esVacio()) {
		suma = 0;
		return 0;
	}

	int suma_der;
	int suma_izq;

	int nodo_interm_izq = rec(a.hijoIz(), a.raiz(), suma_izq);
	int nodo_interm_der = rec(a.hijoDer(), a.raiz(), suma_der);

	suma += suma_der + suma_izq + a.raiz();
	

	return (nodo_interm_der + nodo_interm_izq) + abs(suma_der - suma_izq) % mod == a.raiz();
}

bool arbol_par(Arbin<int> a) {
	if (a.esVacio()) {
		return 1;
	}
	
	if (a.raiz() % 2 == 0) {
		return hijos_pares_suma(a.hijoIz())<a.raiz();
	}
	else {

	}

}

int hijos_pares_suma(Arbin<int> a) {
	if (a.esVacio()) {

	}

}
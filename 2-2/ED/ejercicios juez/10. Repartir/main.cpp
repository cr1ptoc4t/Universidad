#include "lista.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void imprime(Lista<int> l) {
	while (!l.esVacia()) {
		cout << l.primero();
		cout << " ";
		l.quita_ppio();
	}
}

void imprime_inv(Lista<int> l) {
	while (!l.esVacia()) {
		cout << l.ultimo();
		cout << " ";
		l.quita_final();
	}
}

int main() {
	string linea;
	while (!cin.eof()) {
		getline(cin, linea);
		stringstream slinea(linea);
		int valor;
		Lista<int> lista;
		while (slinea >> valor) {
			lista.pon_final(valor);
		}
		cout << "repartir ";
		imprime(lista);
		cout << " => ";
		lista.repartir();
		imprime(lista);
		cout << "#";
		imprime_inv(lista);
		cout << endl;
	}
}

/**
  Nº DE GRUPO:
  NOMBRE Y APELLIDOS DE LOS ALUMNOS QUE HAN REALIZADO EL CONTROL:
*/


#include "Arbin.h"
#include <iostream>
#include <string>

using namespace std;

unsigned int num_singulares_aux(Arbin<int> a, int cont, int val);
int cuentaAbajo(Arbin<int> a, int& cont);

unsigned int numero_singulares(Arbin<int> a) {
	if (a.esVacio())
		return 0;
	else
		return num_singulares_aux(a, 0, 0);
}

unsigned int num_singulares_aux(Arbin<int> a, int cont, int arriba) {
	int arriba_aux = arriba;

	if (a.hijoDer() == NULL && a.hijoIz() == NULL)//esHoja(a)
		arriba = 0;
	else {

	}

	int aux =0;
	int abajo = cuentaAbajo(a, aux);

	if (abajo == arriba_aux)
		cont++;
	else
		return cont;
}


int cuentaAbajo(Arbin<int> a, int& cont) {
	if (a.hijoDer() == NULL && a.hijoIz() == NULL)
		return cont;
	else if (a.hijoDer() == NULL)
		return cuentaAbajo(a.hijoIz(), cont+=a.hijoIz().raiz());
	else if (a.hijoIz() == NULL)
		return cuentaAbajo(a.hijoDer(), cont += a.hijoDer().raiz());
	else
		return cuentaAbajo(a.hijoDer(), cont+=a.hijoDer().raiz()) + cuentaAbajo(a.hijoIz(), cont += a.hijoIz().raiz());
}

Arbin<int> lee_arbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<int>();
	case '[': {
		int raiz;
		in >> raiz;
		in >> c;
		return Arbin<int>(raiz);
	}
	case '(': {
		Arbin<int> iz = lee_arbol(in);
		int raiz;
		in >> raiz;
		Arbin<int> dr = lee_arbol(in);
		in >> c;
		return Arbin<int>(iz, raiz, dr);
	}
	default: return Arbin<int>();
	}
}


int main() {
	Arbin<int> arbol;
	while (cin.peek() != EOF) {
		cout << numero_singulares(lee_arbol(cin));
		string resto_linea;
		getline(cin, resto_linea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}
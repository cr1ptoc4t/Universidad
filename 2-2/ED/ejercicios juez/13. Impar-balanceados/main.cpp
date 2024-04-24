/*
NOMBRE Y APELLIDOS DE LOS COMPONENTES DEL GRUPO QUE HAN
REALIZADO LA PRÁCTICA: Catalina Fullana Mora


(si algún componente no ha realizado la práctica,
no debe aparecer)

*/

#include <iostream>
#include <string>
using namespace std;
#include "Arbin.h"


/*
   DETERMINACION JUSTIFICADA DE LA COMPLEJIDAD:



*/
int num_imparBalanceados(const Arbin<int>& a) {
	if (a.esVacio())
		return 0;


}


// NO MODIFICAR NADA A PARTIR DE AQUI

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
		Arbin<int> a = lee_arbol(cin);
		cout << num_imparBalanceados(a) << endl;
		string resto_linea;
		getline(cin, resto_linea);
	}
	return 0;
}
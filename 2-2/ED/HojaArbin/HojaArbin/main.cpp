using namespace std;
#include <iostream>
#include <string>

#include "Arbin.h"

int numHojas(const Arbin<int>& arb, int& cont)
{
	if (!arb.existeHijoDer() && !arb.existeHijoIz())
		return cont + 1;
	else if (!arb.existeHijoDer())
		return numHojas(arb.hijoIz(), cont);
	else if (
		!arb.existeHijoIz())
		return numHojas(arb.hijoDer(), cont);
	else
		return numHojas(arb.hijoIz(), cont) + numHojas(arb.hijoDer(), cont);
}


bool esHoja(const Arbin<int>& arbol) {

	if (arbol.esVacio()) 
		return false;

	if (arbol.hijoIz().esVacio() && arbol.hijoDer().esVacio())
		return true;
	

	return false;
}

int talla(const Arbin<int>& arb) {
	int max=1;
	if (esHoja(arb))
		return max;
	else if (!(arb.hijoDer().esVacio() || arb.hijoIz().esVacio())) {
		int altura_izq = talla(arb.hijoIz());
		int altura_der = talla(arb.hijoDer());

		if (altura_der > altura_izq)
			max = altura_der;
		else
			max = altura_izq;
	}
	else if (!arb.hijoIz().esVacio())
		max = talla(arb.hijoIz());
	else if (!arb.hijoDer().esVacio())
		max = talla(arb.hijoDer());

	return 1 + max;
}

void frontera(const Arbin<int>& arb) {
	if (esHoja(arb))
		cout << arb.raiz()<<" ";
	else {
		if (!arb.hijoIz().esVacio())
			frontera(arb.hijoIz());
		if (!arb.hijoDer().esVacio())
			frontera(arb.hijoDer());
	}
}

int minElem(const Arbin<int>& arb, int min) {
	cout << arb.raiz();

	if (arb.raiz() < min)
			min = arb.raiz();

	if (!esHoja(arb)){
		if (!arb.hijoIz().esVacio())
			min = minElem(arb.hijoIz(), min);

		if (!arb.hijoDer().esVacio())
			min= minElem(arb.hijoDer(), min);
	}
	

	return min;
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



/**
La entrada al programa consiste de líneas formadas por:
(1) Un árbol de enteros
(2) El valor de k
Los árboles se codifican de acuerdo con las siguientes reglas:
(1) El árbol vacío se codifica como #
(2) Los árboles simples se codifican como [v], con
	v el valor del nodo
(3) Los árboles complejos se codifican como (IvD),
	con I la codificación del hijo izquierdo,
	v el valor de la raíz, y D la codificación
	del hijo derecho.
Para cada línea leida, escribe en la salida estándar
el número de hojas que están a profundidad mayor que k

Ejemplo de entrada:

([2]7([4]3[5]))

salida: 3

*/


int main() {
	Arbin<int> arbol;
	while (cin.peek() != EOF) {
		Arbin<int> a = lee_arbol(cin);
		//int b=0;
		//cout << numHojas(a, b) << endl;
		//int max=0, cont = 0;
		//cout << talla(a) << endl;
		//frontera(a);
		cout << minElem(a, 10000);
	}
	return 0;
}
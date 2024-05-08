using namespace std;
#include <iostream>
#include "Arbin.h"
void analiza_peculiaridad(const Arbin <int>& a, int& minimo, int& maximo, int& npares, int& nimpares, bool&es_peculiar){
	if (esHoja(a)) {
		es_peculiar = true;
		minimo = maximo = a.raiz();
		npares = uno_si_par(a.raiz());
		nimpares = uno_si_impar(a.raiz());
	}
	else {
		if (a.hijoDer().esVacio()) {
			int minimo_iz, maximo_iz, npares_iz, nimpares_iz;
			bool peculiar_iz;
			analiza_peculiaridad(a.hijoIz(), minimo_iz, maximo_iz, npares_iz, nimpares_iz, peculiar_iz);
			if (peculiar_iz) {
				es_peculiar = a.raiz() < minimo_iz;
				minimo = min(a.raiz(), minimo_iz);
				maximo = max(a.raiz(), maximo_iz);
				npares = npares_iz + uno_si_par(a.raiz());
				nimpares = nimpares_iz + uno_si_impar(a.raiz());
			}
			else
				es_peculiar = false;
		}else if (a.hijoDer().esVacio()) {
			int minimo_der, maximo_der, npares_der, nimpares_der;
			bool peculiar_der;
			analiza_peculiaridad(a.hijoDer(), minimo_der, maximo_der, npares_der, nimpares_der, peculiar_der);
			if (peculiar_der) {
				es_peculiar = a.rader() < minimo_der;
				minimo = min(a.raiz(), minimo_der);
				maximo = max(a.raiz(), maximo_der);
				npares = npares_der + uno_si_par(a.raiz());
				nimpares = nimpares_der + uno_si_impar(a.raiz());
			}
			else
				es_peculiar = false;
		}
	}

}

int uno_si_par(int raiz) {

}

int uno_si_impar(int raiz) {

}
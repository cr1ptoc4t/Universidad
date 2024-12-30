#include <iostream>
using namespace std;

/*
DISE�O DEL ALGORITMO:
-- Describe con claridad, justificando las decisiones de dise�o realizadas,
-- el funcionamiento de tu algoritmo. Especifica claramente el cometido de cada
-- par�metro (en caso de que utilices una generalizaci�n), los casos base, y los
-- casos recursivos

ANALISIS DE LA COMPLEJIDAD:
-- Determina justificadamente el orden de complejidad del algoritmo dise�ado. o(n)
-- Escribe y resuelve las ecuaciones de recurrencia.

*/

bool es_interesante_recursivo(unsigned int n, int acumulacion, int& post) {

	if (n < 10) {
		post = 0;
		return true;
	}

	int num_act=n%10;

	if (num_act == 0) return false;
	if (acumulacion % num_act != 0) return false;

	bool b = es_interesante_recursivo(n/10, acumulacion+num_act, post);
	post += n;
	return b && post % n == 0;
}

bool es_interesante(unsigned int n) {
	int post;
    return es_interesante_recursivo(n,0, post);
}

void ejecuta_caso() {
	unsigned int n;
	cin >> n;
	if (es_interesante(n)) {
		cout << "SI" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

int main() {
	unsigned int num_casos;
	cin >> num_casos;
	for (int i = 0; i < num_casos; i++) {
		ejecuta_caso();
	}
}
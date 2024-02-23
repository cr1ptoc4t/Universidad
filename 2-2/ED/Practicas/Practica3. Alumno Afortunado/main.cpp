/*
N�mero de grupo: G25

Nombre y apellidos de los autores de la pr�ctica (si alguno de los miembros del grupo
no hay realizado la pr�ctica, no debe incluirse su nombre):
CATALINA FULLANA MORA
ALAI MIRANDA BLANCO LASCURAIN


*/
#include <iostream>
#include "cola.h"
using namespace std;

unsigned int afortunado(unsigned int n, unsigned int m) { //n>=1  m>=2 
	Cola<int> cl;
	int afortunado;

	for (int i = 1; i <= n; i++)
		cl.pon(i);
	


	int i = 1;
	while (!cl.esVacia()) {
		if (i % m == 0)
			afortunado = cl.primero();
		else 
			cl.pon(cl.primero());

		cl.quita();	
		i++;
	}


	return afortunado;
}


int main() {
	int n, m;
	while ((cin >> n)) {
		cin >> m;
		cout << afortunado(n, m) << endl;
	}
	return 0;
}
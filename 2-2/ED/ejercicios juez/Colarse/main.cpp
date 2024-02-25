#include <iostream>
using namespace std;
#include "cola.h"


int calculaTam(const Cola <int> q);
void cuela(Cola<int>& q, int pos) {
	// A IMPLEMENTAR

	if (!q.esVacia()) {
		Cola<int> aux_superior; 
		Cola<int> aux_inferior;

		int tam = calculaTam(q);

		
		for (int i = 0; i < pos%tam; i++) {
			aux_superior.pon(q.primero());
			q.quita();
		}
		int elemento = q.primero();
		q.quita();

		while(!q.esVacia()){
			aux_inferior.pon(q.primero());
			q.quita();
		}

		//recomponer

		q.pon(elemento);
		while (!aux_superior.esVacia()) {
			q.pon(aux_superior.primero());
			aux_superior.quita();
		}

		while (!aux_inferior.esVacia()) {
			q.pon(aux_inferior.primero());
			aux_inferior.quita();
		}
	}
}

int calculaTam(const Cola <int> q) {
	int tam = 0;
	Cola<int> q2=q;
	while (!q2.esVacia()) {
		q2.quita();
		tam++;
	}

	return tam;
}

// NO MODIFICAR A PARTIR DE AQUI

bool ejecuta_caso() {
	int n;
	cin >> n;
	if (n == -1) {
		return false;
	}
	else {
		Cola<int> q;
		for (int i = 0; i < n; i++) {
			int elem;
			cin >> elem;
			q.pon(elem);
		}
		int pos;
		cin >> pos;
		cuela(q, pos);
		for (int i = 0; i < n; i++) {
			cout << q.primero() << " ";
			q.quita();
		}
		cout << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
	return 0;
}
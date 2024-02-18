
#include <iostream>
#include "pila.h"
using namespace std;

int meterEnPilaYBuscarMax(Pila<int>& p1, Pila<int>& p2);
void reconstruir(Pila<int>& p1, Pila<int>& p2, int max);
void meterEnPila(Pila<int>& p1, Pila<int>& p2);

Pila<int> hundirAlMayor(const Pila<int>& p) {
	// A IMPLEMENTAR
	
	Pila <int> p1;
	//copiamos p en p2 porque p es const
	Pila <int> p2 = Pila<int>(p);
	if (!p2.esVacia()) {
		int max = meterEnPilaYBuscarMax(p2, p1);
		

		reconstruir(p2, p1, max);
	}
	return p2;
}

void meterEnPila(Pila<int>& p1, Pila<int>& p2) {

	try {
		while (!p1.esVacia()) {
			int elemento = p1.cima();
			p1.desapila();
			p2.apila(elemento);
			
		}
	}
	catch (EPilaVacia e) {}

}

int meterEnPilaYBuscarMax(Pila<int>& p1, Pila<int>& p2) {
	
	int max=p1.cima();

	try {
		while (!p1.esVacia()) {
			int elemento = p1.cima();
			p1.desapila();
			p2.apila(elemento);
			if (max < elemento)
				max = elemento;
		}
	}
	catch (EPilaVacia e) {}
	return max;
}

void reconstruir(Pila<int>& p1, Pila<int>& p2, int max) {
	bool primerMaxEncontrado = false;
	p1.apila(max);
	while (!p2.esVacia()) {
		int elemento = p2.cima();
		p2.desapila();

		if (elemento == max && !primerMaxEncontrado)
			primerMaxEncontrado = true;
		else
			p1.apila(elemento);

	}
}

// NO MODIFIQUES NADA DE LO QUE APARECE A CONTINUACION


Pila<int> leePila();
void muestraPila(Pila<int>& stack);
void resuelveCaso();


int main() {
	int numCases;
	cin >> numCases;
	for (int i = 0; i < numCases; i++)
		resuelveCaso();
	return 0;
}

void resuelveCaso() {
	Pila<int> pila = leePila();
	Pila<int> resultado = hundirAlMayor(pila);
	muestraPila(resultado);
}

// Lee de la entrada est�ndar una pila de n�meros enteros positivos acabada en -1
// Los elementos se reciben en orden (el primero es el elemento del fondo de la pila, y el �ltimo es la cima)
Pila<int> leePila() {
	int elem;
	cin >> elem;
	Pila<int> stack = Pila<int>();
	while (elem >= 0) {
		stack.apila(elem);
		cin >> elem;
	}
	return stack;
}

// Muestra por pantalla los elementos de la pila
void muestraPila(Pila<int>& stack) {
	string res;
	while (!stack.esVacia()) {
		cout << stack.cima();
		stack.desapila();
		if (!stack.esVacia())
			cout << " ";
	}
	cout << endl;
}
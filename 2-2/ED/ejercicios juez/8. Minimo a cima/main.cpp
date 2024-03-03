// NO MODIFIQUES NADA DE LO QUE APARECE EN ESTE FICHERO

#include <iostream>
#include "pila.h"
using namespace std;


Pila<int> readStack();
void printStack(Pila<int>& stack);
void resuelveCaso();


int main() {
	int numCases;
	cin >> numCases;
	for (int i = 0; i < numCases; i++)
		resuelveCaso();
}

void resuelveCaso() {
	Pila<int> pila = readStack();
	pila.minimoACima();
	printStack(pila);
}

// Lee de la entrada est�ndar una pila de n�meros enteros positivos acabada en -1
// Los elementos se reciben en orden (el primero es el elemento del fondo de la pila, y el �ltimo es la cima)
Pila<int> readStack() {
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
void printStack(Pila<int>& stack) {
	string res;
	while (!stack.esVacia()) {
		cout << stack.cima();
		stack.desapila();
		if (!stack.esVacia())
			cout << " ";
	}
	cout << endl;
}

#include <iostream>
#include <fstream>
#include "reglasJuego.h"

using namespace std;

int main() {
	tTablero tablero;
	ifstream archivo;
	int a, b, numPasos=1;
	if (leerTablero(archivo, tablero)) {
		mostrarTablero(tablero);
		cout << "Donde quieres poner la primera bombilla? ";
		cin >> a >> b;
		mostrarTablero(tablero);

		while (!(estaTerminado(tablero) || esPosQuit(a, b))) {
			ejecutarPos(tablero, a, b);
			mostrarTablero(tablero);
			numPasos++;
			cout << "Donde quieres poner la bombilla " << numPasos << "? ";
			cin >> a >> b;
		}
		return 0;
	}
}
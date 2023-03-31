
#include <iostream>
#include <fstream>
#include "reglasJuego.h"

using namespace std;

int main() {
	tTablero tablero;
	ifstream archivo;
	int a, b, numPasos=0;
	if (leerTablero(archivo, tablero)) {
		cin >> a >> b;
		while (!(estaTerminado(tablero)||esPosQuit(a,b))) { 
			mostrarTablero(tablero);
			ejecutarPos(tablero, a, b);
			mostrarTablero(tablero);
			numPasos++;
			cin >> a >> b;

		}
	
	return 0;
}
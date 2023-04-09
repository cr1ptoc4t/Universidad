
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
		ejecutarPos(tablero, a, b);
		while (!(estaTerminado(tablero) || esPosQuit(a, b))) {			//DEMORGAN
			mostrarTablero(tablero);
			numPasos++;
			cout << "Donde quieres poner la bombilla " << numPasos << "? ";
			cin >> a >> b;
			if (esPosReset(a, b)) resetear(tablero);
			ejecutarPos(tablero, a, b);
		}
		if (esPosQuit(a,b)) cout << "Gracias por jugar, nos vemos a la proxima"<<endl;
		else {
			cout << "has completado el juego" << endl; mostrarTablero(tablero);
		}

		return 0;
	}
}
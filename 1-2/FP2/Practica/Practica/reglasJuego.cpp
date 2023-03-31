
#include <iostream>
#include "reglasJuego.h"

using namespace std;


bool estaTerminado(tTablero const& tab) {
	return false;
}

bool esPosQuit(int x, int y) {
	return x == -1 && y == 0;
}

void ejecutarPos(tTablero& tab, int x, int y) {
	ponBombilla(tab.tablero[x][y]);
	iluminarDiagonales(tab, x, y);
}

void iluminarDiagonales(tTablero& tab, int x, int y) {
	int z = 1;
	//en el eje x hacia la izquierda hasta que encuentre una pared/inicio
	while (x-z >= 0 &&!esPared(celdaEnPos(tab, x , y - z))) {
		actualizaIluminacionCelda(tab.tablero[x][y - z], true);
		z++;
	}

	z = 1;
	//en el eje x hacia la derecha hasta que encuentre una pared/final
	while (z + x <= getNumCols(tab) && !esPared(celdaEnPos(tab, x, y + z))) {
		actualizaIluminacionCelda(tab.tablero[x][y + z], true);
		z++;
	}

	z = 1;
	// en el eje y hacia arriba
	while (z - y >= 0 && celdaEnPos(tab, x - z, y).tipo != PARED ) {
		actualizaIluminacionCelda(tab.tablero[x - z][y], true);
		z++;
	}

	z = 1;
	// en el eje y hacia abajo
	while (z + y <= getNumFilas(tab) && celdaEnPos(tab, x + z, y).tipo != PARED) {
		actualizaIluminacionCelda(tab.tablero[x + z][y], true);
		z++;
	}
}
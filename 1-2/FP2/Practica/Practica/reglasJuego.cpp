
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
	if (sePuedePonerBombilla(tab, x, y)) {
		ponBombilla(tab.tablero[x][y]);
		iluminarDiagonales(tab, x, y);
	} 
	else cout << "No puedes poner una bombilla en esta celda! Intentalo de nuevo" << endl;
}

void iluminarDiagonales(tTablero& tab, int x, int y) {
	int z = 1;
	//en el eje x hacia la izquierda hasta que encuentre una pared/inicio
	while (y-z >= 0 &&!esPared(celdaEnPos(tab, x , y - z))) {
		actualizaIluminacionCelda(tab.tablero[x][y - z], true);
		z++;
	}

	z = 1;
	//en el eje x hacia la derecha hasta que encuentre una pared/final
	while (z + y <= getNumCols(tab) && !esPared(celdaEnPos(tab, x, y + z))) {
		actualizaIluminacionCelda(tab.tablero[x][y + z], true);
		z++;
	}

	z = 1;
	// en el eje y hacia arriba
	while (x-z >= 0 && celdaEnPos(tab, x - z, y).tipo != PARED ) {
		actualizaIluminacionCelda(tab.tablero[x - z][y], true);
		z++;
	}

	z = 1;
	// en el eje y hacia abajo
	while (z + x <= getNumFilas(tab) && celdaEnPos(tab, x + z, y ).tipo != PARED) {
		actualizaIluminacionCelda(tab.tablero[x + z][y], true);
		z++;
	}
}


int numParedActual(const tTablero& tab, int x, int y) {
	int bombillas = 0;
	if (esBombilla(tab.tablero[x][y + 1])) bombillas++;
	if (esBombilla(tab.tablero[x][y - 1])) bombillas++;
	if (esBombilla(tab.tablero[x - 1][y])) bombillas++;
	if (esBombilla(tab.tablero[x + 1][y])) bombillas++;

	return bombillas;
}

bool sePuedePonerBombilla(const tTablero& tab, int x, int y) {
	return estaLibre(celdaEnPos(tab, x, y))/*&& (numParedActual(tab, x, y)<numParedRestringida(celdaEnPos(tab, x, y)))*/ && esPosicionValida(tab, x, y);
}

bool esPosicionValida(const tTablero tab, int x, int y) {
	return x >= 0 && x < tab.nFils&& y >= 0 && y < tab.nCols;
}
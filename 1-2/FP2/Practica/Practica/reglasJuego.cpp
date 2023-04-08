
#include <iostream>
#include "reglasJuego.h"

using namespace std;

//CHECK ESTO
bool estaTerminado(tTablero const& tab) {
	bool terminado = true;
	int i = 0;
	while (terminado&&i<tab.nCols) {
		int j = 0;
		while (terminado && j < tab.nFils) {
			if (!casillaValida(tab, i, j)){
				terminado = false;
			}
			j++;
		}
		i++;

	}
	return terminado;
}

bool esPosQuit(int x, int y) {
	return x == -1 && y == 0;
}

void ejecutarPos(tTablero& tab, int x, int y) {
	if (sePuedePonerBombilla(tab, x, y)) {
		ponBombilla(tab.tablero[x][y]);
		iluminarDiagonales(tab, x, y, true);
	}
	else if (esBombilla(celdaEnPos(tab, x, y))) {
		quitaBombilla(tab.tablero[x][y]);
		iluminarDiagonales(tab, x, y, false);
	}
	else cout << "No puedes poner una bombilla en esta celda! Intentalo de nuevo" << endl;
}

void iluminarDiagonales(tTablero& tab, int x, int y, bool iluminar) {
	int z = 1;
	//en el eje x hacia la izquierda hasta que encuentre una pared/inicio
	while (y-z >= 0 &&!esPared(celdaEnPos(tab, x , y - z))) {
		actualizaIluminacionCelda(tab.tablero[x][y - z], iluminar);
		z++;
	}

	z = 1;
	//en el eje x hacia la derecha hasta que encuentre una pared/final
	while (z + y <= getNumCols(tab) && !esPared(celdaEnPos(tab, x, y + z))) {
		actualizaIluminacionCelda(tab.tablero[x][y + z], iluminar);
		z++;
	}

	z = 1;
	// en el eje y hacia arriba
	while (x-z >= 0 && celdaEnPos(tab, x - z, y).tipo != PARED ) {
		actualizaIluminacionCelda(tab.tablero[x - z][y], iluminar);
		z++;
	}

	z = 1;
	// en el eje y hacia abajo
	while (x+z <= getNumFilas(tab) && celdaEnPos(tab, x + z, y ).tipo != PARED) {
		actualizaIluminacionCelda(tab.tablero[x + z][y], iluminar);
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
	return estaLibre(celdaEnPos(tab, x, y)) && esPosicionValida(tab, x, y);
}

bool esPosicionValida(const tTablero tab, int x, int y) {
	return x >= 0 && x < tab.nFils&& y >= 0 && y < tab.nCols;
}

bool casillaValida(const tTablero& tab, int x, int y) {
	tCelda c = celdaEnPos(tab, x, y);
	return (c.numBombillas>0&& !esPared(c))||(esParedRestringida(c)&&(numParedActual(tab,x,y)== c.numBombillas))||(esPared(c)&&c.numBombillas==-1);
}
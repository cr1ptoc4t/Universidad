
#include <iostream>
#include "reglasJuego.h"

using namespace std;


bool estaTerminado(tTablero const& tab) {
	return false;
}
bool esPosQuit(int x, int y) {
	return x == 1 && y == 0;
}

void ejecutarPos(tTablero& tab, int x, int y) {
	//esto no va aqui pero funciona
	for (int i = 0; i < tab.nCols;i++) {
		for (int j = 0; j < tab.nFils; j++) {
			if (celdaEnPos(tab, i, j).tipo==BOMBILLA) iluminarDiagonales(tab, i, j);
		}
	}
}

//HAY UN BUG
void iluminarDiagonales(tTablero& tab, int x, int y) {
	int z = 1;
	//en el eje x hacia la izquierda hasta que encuentre una pared/inicio
	while (x-z >= 0 &&!esPared(celdaEnPos(tab, x - z, y))) {
		setTipo(tab, x-z, y, BOMBILLA);//iluminar
		z++;
	}
	z = 1;
	//en el eje x hacia la derecha hasta que encuentre una pared/final
	while (z + x <= getNumCols(tab) && !esPared(celdaEnPos(tab, x + z, y))) {
		setTipo(tab, x + z, y, BOMBILLA);//iluminar
		z++;
	}
	z = 1;
	// en el eje y hacia arriba
	while (z - y >= 0 && celdaEnPos(tab, x, y - z).tipo != PARED ) {
		setTipo(tab, x, y-z, BOMBILLA);//iluminar
		z++;
	}
	z = 1;
	// en el eje y hacia abajo
	while (z + y >=getNumCols(tab) && celdaEnPos(tab, x, y + z).tipo != PARED) {
		setTipo(tab, x, y - z, BOMBILLA);//iluminar
		z++;
	}

}
#include <iostream>
#include "reglasJuego.h"
using namespace std;


bool estaTerminado(tTablero const& tab) {
	bool terminado = true;
	int i = 0, j=0;
	while (terminado&&i<tab.nCols) {
		int j = 0;
		while (terminado && j < tab.nFils) {
			if (!casillaValida(tab, i, j))	terminado = false;
			j++;
		}
		i++;
	}

	return terminado;
}

bool esPosQuit(int x, int y) {
	return x == -1 && y == 0;
}

//esto se tiene que poder simplificar
void ejecutarPos(tTablero& tab, int x, int y) {
	if (sePuedePonerBombilla(tab, x, y)) {
		tCelda c = celdaEnPos(tab, x, y);
		ponBombilla(c);
		ponCeldaEnPos(tab, x, y, c);

		iluminarDiagonales(tab, x, y, true);
	} else if (esBombilla(celdaEnPos(tab, x, y))) {

		tCelda c = celdaEnPos(tab, x, y);
		quitaBombilla(c);
		ponCeldaEnPos(tab, x, y, c);

		iluminarDiagonales(tab, x, y, false);
	}
	else cout << "No puedes poner una bombilla en esta celda! Intentalo de nuevo" << endl;
}


//esto estaa  mal, hay que usar tDir y no se puede hacer tipo:  tab.tablero[x][y - z]
//es un for y dentro un while
void iluminarDiagonales(tTablero& tab, int x, int y, bool iluminar) {

	int z = 1;
	//en el eje x hacia la izquierda hasta que encuentre una pared/inicio
	while (y-z >= 0 &&!esPared(celdaEnPos(tab, x , y - z))) {
		tCelda c = celdaEnPos(tab, x, y-z);
		actualizaIluminacionCelda(c, iluminar);
		ponCeldaEnPos(tab, x, y-z, c);
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


//AQUI HAY QYE USAR tDIR!!!!!!!
int numParedActual(const tTablero& tab, int x, int y) {
	int bombillas = 0;
	
	/* tiene que ser algo asi
	for (int i = 0; i < 3; i++) {
		if (esBombilla(celdaEnPos(tab, dir)))bombillas++;
	}
	*/
	if (esBombilla(celdaEnPos(tab, x, y + 1)))	bombillas++;
	if (esBombilla(celdaEnPos(tab, x, y - 1)))	bombillas++;
	if (esBombilla(celdaEnPos(tab, x - 1, y)))	bombillas++;
	if (esBombilla(celdaEnPos(tab, x + 1, y)))	bombillas++;

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

void iluminarDiagonales2(tTablero& tab, int x, int y, bool iluminar) {
	for (int i = 0; i < 3;i++) {
		iluminarDiagonal(tab, x,y, iluminar,tDir(i));
	}
}


//esto tendria que ser algo así
void iluminarDiagonal(tTablero& tab, int x, int y, bool iluminar, tDir dir) {
	int z = 0, k=0;

	while (/*no haya pared y no termine ni empiece el tablero:*/ false) {
		switch (dir) {
		case NORTE: {

		}break;
		case SUR: {

		}break; 
		case ESTE: {

		}break; 
		case OESTE: {

		}break;

		}
	}
}
#include <iostream>
#include "reglasJuego.h"
using namespace std;


bool estaTerminado(tTablero const& tab) {
	bool terminado = true;
	int i = 0, j=0;
	while (terminado&&i<tab.nFils) {
		int j = 0;
		while (terminado && j < tab.nCols) {
			if (!casillaValida(tab, i, j)) {
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

bool esPosReset(int x, int y) {
	return x == -1 && y == -1;
}

void ejecutarPos(tTablero& tab, int x, int y) {
	if (sePuedePonerBombilla(tab, x, y)|| esBombilla(celdaEnPos(tab, x, y))) {

		tCelda c = celdaEnPos(tab, x, y);

		if (sePuedePonerBombilla(tab, x, y))	ponBombilla(c);
		else if (esBombilla(c))					quitaBombilla(c);
	
		ponCeldaEnPos(tab, x, y, c);
		iluminarDiagonales(tab, x, y, esBombilla(c));
	}
	else if (esPosReset(x, y)) {
		cout << "...................RESETEANDO................." << endl;
		resetear(tab);
	} else if (!sePuedePonerBombilla(tab, x,y)){
		cout << "No puedes poner una bombilla en esta celda! Intentalo de nuevo" << endl;
	}
}

int numParedActual(const tTablero& tab, int x, int y) {
	int bombillas = 0;
	
	for (int i = 0; i < 4; i++) {
		int x1 = x;
		int y1 = y;
		tDiraCoordenada(tDir(i), x1, y1);
		if (esBombilla(celdaEnPos(tab, x1, y1))) bombillas++;
	}
	return bombillas;
}

void tDiraCoordenada(tDir dir, int& x, int& y){
	switch (dir) {
	case NORTE: {
		y --;
	}break;
	case SUR: {
		y ++;
	}break;
	case ESTE: {
		x--;
	}break;
	case OESTE: {
		x++;
	}
	}
}

bool sePuedePonerBombilla(const tTablero& tab, int x, int y) {
	tCelda c = celdaEnPos(tab, x, y);
	return estaLibre(celdaEnPos(tab, x, y)) && esPosicionValida(tab, x, y) && (c.numBombillas == 0);
}


bool esPosicionValida(const tTablero tab, int x, int y) {
	return x >= 0 && x < tab.nFils&& y >= 0 && y < tab.nCols;
}

bool casillaValida(const tTablero& tab, int x, int y) {
	tCelda c = celdaEnPos(tab, x, y);
		// si esta libre, que esté iluminada   numParedRestringida == numBombillas que la rodean
	return (c.numBombillas>0&& estaLibre(c))|| (esParedRestringida(c)&&(numParedActual(tab,x,y)== c.numBombillas))
		|| (esPared(c)&&c.numBombillas==-1) || esBombilla(c)&&c.numBombillas==1;
		//si es pared, numBombillas = 1			si es bombilla, que no esté dos veces iluminada
}

void iluminarDiagonales(tTablero& tab, int x, int y, bool iluminar) {
	for (int i = 0; i < 4;i++) {
		iluminarDiagonal(tab, x,y, iluminar,tDir(i));
	}
}

void iluminarDiagonal(tTablero& tab, int x, int y, bool iluminar, tDir dir) {
	tDiraCoordenada(dir, x, y);
	while (x>=0 && y>=0 && x<tab.nFils && y<tab.nCols && !esPared(celdaEnPos(tab,x,y))) {
		tCelda c = celdaEnPos(tab, x, y);
		actualizaIluminacionCelda(c, iluminar);
		ponCeldaEnPos(tab, x, y, c);
		tDiraCoordenada(dir, x, y);

	}
}
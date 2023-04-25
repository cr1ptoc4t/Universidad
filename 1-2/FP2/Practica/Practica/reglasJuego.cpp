#include <iostream>
#include "reglasJuego.h"
using namespace std;


bool estaTerminado(tTablero const& tab) {
	bool terminado = true;
	int i = 0, j=0;
	while (terminado && i<getNumFilas(tab)) {
		int j = 0;
		while (terminado && j < getNumCols(tab)) {
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
		iluminarEjes(tab, x, y, esBombilla(c));
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
	return estaLibre(celdaEnPos(tab, x, y)) && esPosicionValida(tab, x, y) && (numBombillas(c) == 0);
}


bool esPosicionValida(const tTablero tab, int x, int y) {
	return x >= 0 && x < getNumFilas(tab)&& y >= 0 && y < getNumCols(tab);
}

bool casillaValida(const tTablero& tab, int x, int y) {
	tCelda c = celdaEnPos(tab, x, y);
		// si esta libre, que esté iluminada   numParedRestringida == numBombillas que la rodean
	return (numBombillas(c)>0&& estaLibre(c))|| (esParedRestringida(c)&&(numParedActual(tab,x,y)== numBombillas(c)))
		|| (esPared(c)&&numBombillas(c)==-1) || esBombilla(c)&&numBombillas(c)==1;
		//si es pared, numBombillas = 1			si es bombilla, que no esté dos veces iluminada
}

void iluminarEjes(tTablero& tab, int x, int y, bool iluminar) {
	for (int i = 0; i < 4;i++) {
		iluminarEje(tab, x,y, iluminar,tDir(i));
	}
}

void iluminarEje(tTablero& tab, int x, int y, bool iluminar, tDir dir) {
	tDiraCoordenada(dir, x, y);
	while (x>=0 && y>=0 && x<getNumFilas(tab) && y<getNumCols(tab) && !esPared(celdaEnPos(tab,x,y))) {
		tCelda c = celdaEnPos(tab, x, y);
		actualizaIluminacionCelda(c, iluminar);
		ponCeldaEnPos(tab, x, y, c);
		tDiraCoordenada(dir, x, y);

	}
}

void resetear(tTablero& tab) {
	for (int i = 0; i < getNumFilas(tab); i++) {
		for (int j = 0; j < getNumCols(tab); j++) {
			if (!esPared(celdaEnPos(tab, i, j))) {
				tCelda c = celdaEnPos(tab, i, j);
				apagaCelda(c);
				ponCeldaEnPos(tab, i, j, c);
			}
		}
	}
}
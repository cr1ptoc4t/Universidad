
#include <iostream>
#include "reglasJuego.h"
using namespace std;

int main() {
	tTablero tablero;
	tablero.nCols = 10;
	tablero.nFils = 20;

	//ponBombilla(tablero.tablero[3][2]);
	//tablero.tablero[1][5].tipo = PARED;
	mostrarTablero(tablero);
	return 0;
}
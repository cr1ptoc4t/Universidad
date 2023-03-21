
#include <iostream>
#include "reglasJuego.h"
using namespace std;

int main() {
	tTablero tablero;
	ifstream archivo;
	//if(leerTablero(archivo, tablero)){
		tablero.nCols = 5;		
		tablero.nFils = 5;
	//}
	

	//ponBombilla(tablero.tablero[3][2]);
	//tablero.tablero[1][5].tipo = PARED;
	mostrarTablero(tablero);
	return 0;
}
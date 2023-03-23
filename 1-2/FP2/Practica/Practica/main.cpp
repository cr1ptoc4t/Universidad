
#include <iostream>
#include <fstream>
#include "reglasJuego.h"

using namespace std;

int main() {
	tTablero tablero;
	ifstream archivo;
	if (leerTablero(archivo, tablero)) {
		ejecutarPos(tablero, 3, 6);
		//mostrar tablero
		// while(){
		//	introducir donde quiere poner las bombillas
		//	preguntar si quiere chequear
		//}
	}
	

	//ponBombilla(tablero.tablero[3][2]);
	//tablero.tablero[1][5].tipo = PARED;
	mostrarTablero(tablero);
	return 0;
}
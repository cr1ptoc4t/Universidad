
#include <iostream>
#include "tablero.h"

using namespace std;


tCelda celdaEnPos(const tTablero& tab, int x, int y) {
	tCelda celda = tab.tablero[x][y];
	return celda;
}
int getNumFilas(const tTablero& tab) {
	return 0;
}
int getNumCols(const tTablero& tab) {
	return 0;
}
/*
bool leerTablero(ifstream& archivo, tTablero& tab) {
	return false;
}
*/
void ponCeldaEnPos(tTablero& tab, int x, int y, const tCelda& c) {

}
void mostrarTablero(const tTablero& tab) {
	
}

#include <iostream>
#include "tablero.h"
#include "colores.h"

using namespace std;


tCelda celdaEnPos(const tTablero& tab, int x, int y) {
	tCelda celda = tab.tablero[x][y];
	return celda;
}
int getNumFilas(const tTablero& tab) {
	return MAX_FILS;
}
int getNumCols(const tTablero& tab) {
	return MAX_COLS;
}
/*
bool leerTablero(ifstream& archivo, tTablero& tab) {
	return false;
}
*/
void ponCeldaEnPos(tTablero& tab, int x, int y, const tCelda& c) {
	tab.tablero[x][y].tipo = c.tipo;
	tab.tablero[x][y].numBombillas = c.numBombillas;
}
void mostrarTablero(const tTablero& tab) {
	for (int i = 0; i < tab.nCols; i++) {
		cout << BLUE << "|";
		if(i<9) cout<<" "<< i + 1 << " " << RESET;
		else if(i>=9&&i<100) cout << i + 1 << " " << RESET;
		else cout << i + 1 << RESET;
	}
	cout<< endl;

	for (int i = 0; i < tab.nFils;i++) {
		for (int j = 0; j < tab.nCols;j++) {
			cout << "|";
			if (tab.tablero[i][j].tipo == BOMBILLA) cout << BG_YELLOW;
			else if (tab.tablero[i][j].tipo == PARED) cout<<BG_GRAY;
			cout<< " . "<<RESET;
			
		}
		cout << endl;

	}
}
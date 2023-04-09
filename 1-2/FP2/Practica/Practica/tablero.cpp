
#include <iostream>
#include "tablero.h"
#include "colores.h"
#include "reglasJuego.h"

using namespace std;

tCelda celdaEnPos(const tTablero& tab, int x, int y) {
	return tab.tablero[x][y];
}

void setTipo(tTablero& tab, int x, int y,tTipo tipo) {
	tCelda c = celdaEnPos(tab, x, y);
	c.tipo = tipo;
	ponCeldaEnPos(tab, x, y, c);
}

int getNumCols(const tTablero& tab) {
	return tab.nCols;
}

int getNumFilas(const tTablero& tab) {
	return tab.nFils;
}

void ponCeldaEnPos(tTablero& tab, int x, int y, const tCelda& c) {
	tab.tablero[x][y].tipo = c.tipo;
	tab.tablero[x][y].numBombillas = c.numBombillas;
}

bool leerTablero(ifstream& archivo, tTablero& tab){
	bool abierto = false;
	char str;
	int numBombillas, x, y;
	tCelda celda;
	archivo.open("tablero.txt");
	if (archivo.is_open()) {
		archivo >> tab.nFils >> tab.nCols;
		for (int i = 0; i < tab.nCols; i++) {
			for (int j = 0; j < tab.nFils;j++) {
				archivo >> str;
				celda = charToCelda(str);
				ponCeldaEnPos(tab, i, j, celda);
			}
		}

		archivo >> numBombillas;
		for (int i = 0; i < numBombillas;i++) {
			archivo >> x;
			archivo >> y;
			tCelda c = celdaEnPos(tab, x, y);
			ponBombilla(c);
			ponCeldaEnPos(tab, x, y, c);
			iluminarDiagonales(tab, x, y, true);
		}

		archivo.close();
		abierto = true;
	}

	return abierto;
}

void mostrarTablero(const tTablero& tab) {
	cout << "  ";
	for (int i = 0; i < tab.nCols; i++) {
		cout << RED << "|";
		if(i<9) cout<<" "<< i << " " << RESET;
		else if(i>=9&&i<100) cout << i << " " << RESET;
		else cout << i << RESET;
	}
	cout<< endl;

	for (int i = 0; i < tab.nFils;i++) {
		cout<< RED << i<<  " " << RESET;
		for (int j = 0; j < tab.nCols;j++) {
			cout << "|";

			if (esBombilla(celdaEnPos(tab, i, j)))		cout << RED << BG_YELLOW;
			else if (estaIluminada(celdaEnPos(tab, i, j)))	cout << BG_YELLOW;
			else if (esPared(celdaEnPos(tab, i, j)))cout << BG_GRAY << BLACK;
			
			if(esParedRestringida(celdaEnPos(tab, i, j)))
				cout << " " << numBombillas(celdaEnPos(tab, i, j)) << " ";
			else
				cout << " " << celdaToChar(celdaEnPos(tab, i, j)) << " ";
			
			cout << RESET;
		}
		cout << endl;

	}

	cout << endl;
}




void resetear(tTablero& tab) {
	for (int i = 0; i < tab.nFils; i++) {
		for (int j = 0; j < tab.nCols; j++) {
			if(!esPared(celdaEnPos(tab, i, j))) {
				tCelda c = celdaEnPos(tab, i, j);
				apagaCelda(c);
				ponCeldaEnPos(tab, i, j, c);
			}
		}
	}
}
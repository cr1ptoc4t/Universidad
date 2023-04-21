
#include <iostream>
#include "tablero.h"
#include "colores.h"
#include "reglasJuego.h"

using namespace std;

tCelda celdaEnPos(const tTablero& tab, int x, int y) {
	return tab.tablero[x][y];
}

void setTipo(tTablero& tab, int x, int y,tTipo tipo) {
	tab.tablero[x][y].tipo = tipo;
}

int getNumCols(const tTablero& tab) {
	return tab.nCols;
}

int getNumFilas(const tTablero& tab) {
	return tab.nFils;
}

void ponCeldaEnPos(tTablero& tab, int x, int y, const tCelda& c) {
	tab.tablero[x][y] = c;
}

bool leerTablero(ifstream& archivo, tTablero& tab){
	bool abierto = false;
	char str;
	int x, y;
	tCelda celda;
	if (archivo.is_open()) {
		archivo >> tab.nFils >> tab.nCols;
		for (int i = 0; i < tab.nFils; i++) {
			for (int j = 0; j < tab.nCols;j++) {
				archivo >> str;
				celda = charToCelda(str);
				ponCeldaEnPos(tab, i, j, celda);
			}
		}
		archivo >> str;
		for (int i = 0; i < str -'0'; i++) {
			archivo >> x;
			archivo >> y;
			tCelda c = celdaEnPos(tab, x, y);
			ponBombilla(c);
			ponCeldaEnPos(tab, x, y, c);
			iluminarEjes(tab, x, y, true);
		}

		archivo.close();
		abierto = true;
	}

	return abierto;
}

void mostrarTablero(const tTablero& tab) {

	//indices eje x
	for (int i = 0; i < tab.nCols; i++) {
		cout << RESET << " | "<<LBLUE<< i;
	}

	cout <<RESET<< endl << "-+";
	for (int j = 0; j < tab.nCols; j++)
		cout << "---+";

	cout << endl;

	for (int i = 0; i < tab.nFils;i++) {
		cout<< LBLUE << i << RESET;		//indices eje y
		for (int j = 0; j < tab.nCols;j++) {
			cout << "|";
			
			//elegir color
			if (esBombilla(celdaEnPos(tab, i, j)))			cout << BLACK << BG_YELLOW;
			else if (estaIluminada(celdaEnPos(tab, i, j)))	cout << BG_YELLOW;
			else if (estaLibre(celdaEnPos(tab, i, j)))		cout << BG_WHITE;
			
			//output
			if(esParedRestringida(celdaEnPos(tab, i, j)))
				cout << " " << numBombillas(celdaEnPos(tab, i, j)) << " ";
			else
				cout << " " << celdaToChar(celdaEnPos(tab, i, j)) << " ";
			
			cout << RESET;

		}
		cout<< endl<<  "-+";
		
		for(int j=0; j<tab.nCols;j++)
			cout << "---+";

		cout << endl;
	}
	cout << endl;
}




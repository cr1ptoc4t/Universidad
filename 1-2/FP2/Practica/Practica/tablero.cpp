
#include <iostream>
#include "tablero.h"
#include "colores.h"

using namespace std;

tCelda celdaEnPos(const tTablero& tab, int x, int y) {
	return tab.tablero[x][y];
}

void setTipo(tTablero& tab, int x, int y,tTipo tipo) {
	//no se si aqui hay que crear una tCelda y despues pon celda en tal
	tab.tablero[x][y].tipo = tipo;
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


// usar char to celda
bool leerTablero(ifstream& archivo, tTablero& tab){
	bool abierto = false;
	char str;
	tCelda celda;
	archivo.open("tablero.txt");
	if (archivo.is_open()) {
		archivo >> tab.nFils;
		archivo >> tab.nCols;
		for (int i = 0; i < tab.nCols; i++) {
			for (int j = 0; j < tab.nFils;j++) {
				archivo >> str;
				celda = charToCelda(str);
				ponCeldaEnPos(tab, i, j, celda);
			}
		}
		archivo.close();
		abierto = true;
	}

	return abierto;
}

//usar celda to char
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

			if		(esBombilla(celdaEnPos(tab,i,j)))		cout << RED << BG_YELLOW << " * ";
			else if (estaIluminada(celdaEnPos(tab,i,j)))	cout << BG_YELLOW << "   ";
			else if (esPared(celdaEnPos(tab,i,j)))
				if(!esParedRestringida(celdaEnPos(tab,i,j)))cout << BG_GRAY << BLACK << "   ";
				else cout << BG_GRAY << BLACK<<" "<< celdaEnPos(tab,i,j).numBombillas<<" ";
			else cout<<"   ";
			cout << RESET;
		}
		cout << endl;

	}

	cout << endl;
}

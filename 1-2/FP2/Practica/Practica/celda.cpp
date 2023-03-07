
#include <iostream>
#include "celda.h"

using namespace std;
char celdaToChar(const tCelda& celda) {
	char c;
	if (celda.tipo == BOMBILLA) c = 'b';
	else if (celda.tipo == PARED) c = 'p';
	else if (celda.tipo == LIBRE) c = 'l';
	return c;
}

tCelda charToCelda(char c) {
	tCelda celda;

	if		(c == 'b')  celda.tipo = BOMBILLA;
	else if (c == 'p')	celda.tipo = PARED;
	else if (c == 'l')	celda.tipo = LIBRE;

	return celda;
}

bool esParedRestringida(const tCelda& c) {
	return false;
}
bool numParedRestringida(const tCelda& c) {
	return false;
}
bool esBombilla(const tCelda& c) {
	return c.tipo==BOMBILLA;
}
bool estaApagada(const tCelda& c) {
	
	return false;
}
bool estaIluminada(const tCelda& c) {
	return false;
}

void apagaCelda( tCelda& c) {
	c.tipo = LIBRE;

}
void actualizaIluminacionCelda( tCelda& c) {

}
void ponBombilla( tCelda& c) {
	c.tipo = BOMBILLA;
	//iluminar las dos diagonales?
}

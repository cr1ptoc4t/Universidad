
#include <iostream>
#include<stdio.h>
#include<ctype.h>
#include "celda.h"
using namespace std;

char celdaToChar(const tCelda& celda) {
	char c= ' ';
	if (celda.tipo == BOMBILLA) c = '*';
	else if (celda.tipo == PARED) c = celda.numBombillas;

	return c;
}

tCelda charToCelda(char c) {
	tCelda celda;

	if (c == '*')  celda.tipo = BOMBILLA;
	else if (c == 'X') celda.tipo = PARED;
	else if (c == '.')	celda.tipo = LIBRE;
	else if (isdigit(int(c))) {
		celda.numBombillas = c;
		celda.tipo = PARED;
	}
	return celda;
}

bool esPared(const tCelda& c){
	return c.tipo == PARED;
}

bool esParedRestringida(const tCelda& c) {
	return c.tipo ==PARED && c.numBombillas !=-1;
}

//FALTA ESTA
int numParedRestringida(const tCelda& c) {
	return 2;
}

bool esBombilla(const tCelda& c) {
	return c.tipo==BOMBILLA;
}

bool estaApagada(const tCelda& c) {
	return c.tipo== LIBRE && c.numBombillas==0;
}
bool estaIluminada(const tCelda& c) {
	return c.tipo == LIBRE && c.numBombillas > 0;
}

void apagaCelda( tCelda& c) {
	c.tipo = LIBRE;

}
void actualizaIluminacionCelda( tCelda& c, bool iluminar) {
	if (iluminar) c.numBombillas++;
	else if(!iluminar && c.numBombillas >0)	c.numBombillas--;
}

void ponBombilla( tCelda& c) {
	c.tipo = BOMBILLA;
}
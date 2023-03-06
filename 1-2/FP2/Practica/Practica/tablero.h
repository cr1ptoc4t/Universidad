#pragma once
#include "celda.h"
#include <iostream>
#include <fstream>

const int MAX_FILS = 10;
const int MAX_COLS = 10;

typedef enum tDir { NORTE, SUR, ESTE, OESTE };

typedef struct {
	int nFils, nCols;
	tCelda tablero[MAX_FILS][MAX_COLS];
}tTablero;

int getNumFilas(const tTablero& tab);
int getNumCols(const tTablero& tab);
//bool leerTablero(ifstream& archivo, tTablero& tab);
void ponCeldaEnPos(tTablero& tab, int x, int y, const tCelda& c);
void mostrarTablero(const tTablero& tab);

tCelda celdaEnPos(const tTablero& tab, int x, int y);
//ifstream& operator>>(ifstream& archivo, tTablero& tab);
//ostream& operator<<(ostream& out, const tTablero& tab);
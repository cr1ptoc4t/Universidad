#pragma once
#include "celda.h"
#include <iostream>
#include <fstream>
using namespace std;

const int MAX_FILS = 10;
const int MAX_COLS = 15;

typedef enum tDir { NORTE, SUR, ESTE, OESTE };

typedef struct {
	int nFils, nCols;
	tCelda tablero[MAX_FILS][MAX_COLS];
}tTablero;

tCelda celdaEnPos(const tTablero& tab, int x, int y);

int getNumFilas(const tTablero& tab);
int getNumCols(const tTablero& tab);

void ponCeldaEnPos(tTablero& tab, int x, int y, const tCelda& c);
void mostrarTablero(const tTablero& tab);
void setTipo(tTablero& tab, int x, int y, tTipo tipo);

bool leerTablero(ifstream& archivo, tTablero& tab);

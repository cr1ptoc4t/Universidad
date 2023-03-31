#pragma once
#include "tablero.h"

bool estaTerminado(tTablero const& tab); 
bool esPosQuit(int x, int y);
void ejecutarPos(tTablero& tab, int x, int y);
void iluminarDiagonales(tTablero& tab, int x, int y);

int numParedActual(const tTablero& tab, int x, int y);
bool sePuedePonerBombilla(const tTablero& tab, int x, int y);
bool esPosicionValida(const tTablero tab, int x, int y);
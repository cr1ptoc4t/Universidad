#pragma once
#include "tablero.h"

void ejecutarPos (tTablero& tab, int x, int y);
void iluminarEje(tTablero& tab, int x, int y, bool iluminar, tDir dir);
void tDiraCoordenada(tDir dir, int& x, int& y);
void iluminarEjes(tTablero& tab, int x, int y, bool iluminar);
void resetear(tTablero& tab);


int  numParedActual(const tTablero& tab, int x, int y);
int  elegirPartida();

bool sePuedePonerBombilla (const tTablero& tab, int x, int y);
bool esPosicionValida (const tTablero tab, int x, int y);
bool casillaValida (const tTablero& tab, int x, int y);
bool estaTerminado (tTablero const& tab);
bool esPosQuit (int x, int y);
bool esPosReset(int x, int y);
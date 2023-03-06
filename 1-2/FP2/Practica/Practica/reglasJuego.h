#pragma once
#include "tablero.h"



bool estaTerminado(tTablero const& tab); 
bool esPosQuit(int x, int y);
void ejecutarPos(tTablero& tab, int x, int y);